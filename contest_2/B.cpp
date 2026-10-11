#include <iostream>
#include <vector>

// Simple-sort to sort the vectors with five elements (inplace)

void InsertionSort(std::vector<int>& arr, int l, int r) {
  for (int i = l + 1; i < r; i++) {
    int tmp = arr[i];
    int j = i - 1;
    while (j >= l && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = tmp;
  }
}

int DQS(std::vector<int>& arr, int k) {
  int n = (int)arr.size();

  if (n == 1) {
    return arr[0];
  }

  std::vector<int> medians((n + 4) / 5);

  for (int left = 0; left < n; left += 5) {
    int right = std::min(n, left + 5);  // n if got out
    InsertionSort(arr, left, right);

    int median_i = left + (right - left) / 2;
    medians[left / 5] = arr[median_i];
  }

  int pivot = DQS(medians, (int)(medians.size()) / 2);  // median of medians

  std::vector<int> l;
  std::vector<int> m;
  std::vector<int> r;

  l.reserve(n / 2);
  m.reserve(n / 2);
  r.reserve(n / 2);

  for (int i = 0; i < n; i++) {
    if (arr[i] < pivot) {
      l.push_back(arr[i]);
    } else if (arr[i] == pivot) {
      m.push_back(arr[i]);
    } else {
      r.push_back(arr[i]);
    }
  }

  if (k < (int)l.size()) {
    return DQS(l, k);
  }

  if (k < (int)(l.size() + m.size())) {
    return pivot;
  }

  return DQS(r, k - (int)(l.size() + m.size()));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  int k;
  const long long c1 = 123;
  const long long c2 = 45;
  const long long c3 = 1e7 + 4321;

  std::cin >> n >> k;
  std::vector<int> arr(n);
  std::cin >> arr[0] >> arr[1];

  k--;

  for (int i = 2; i < n; i++) {
    arr[i] = ((long long)arr[i - 1] * c1 + (long long)arr[i - 2] * c2) % (c3);
  }

  std::cout << DQS(arr, k) << "\n";
  return 0;
}

