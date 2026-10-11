#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> Merge(
    const std::vector<std::pair<int, int>>& arr1,
    const std::vector<std::pair<int, int>>& arr2) {
  int i = 0;
  int j = 0;

  std::vector<std::pair<int, int>> merged(arr1.size() + arr2.size());

  while (i < (int)arr1.size() || j < (int)arr2.size()) {
    if (i == (int)arr1.size()) {
      merged[i + j] = arr2[j];
      j++;
      continue;
    }

    if (j == (int)arr2.size()) {
      merged[i + j] = arr1[i];
      i++;
      continue;
    }

    if (arr1[i] <= arr2[j]) {
      merged[i + j] = arr1[i];
      i++;
    } else {
      merged[i + j] = arr2[j];
      j++;
    }
  }

  return merged;
}

std::vector<std::pair<int, int>> MergeSort(
    const std::vector<std::pair<int, int>>& arr) {
  if ((int)arr.size() <= 1) {
    return arr;
  }
  int size_l = arr.size() / 2;
  std::vector<std::pair<int, int>> l(arr.begin(), arr.begin() + size_l);
  std::vector<std::pair<int, int>> r(arr.begin() + size_l, arr.end());
  l = MergeSort(l);
  r = MergeSort(r);
  return Merge(l, r);
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> arr(n);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i].first >> arr[i].second;
  }

  arr = MergeSort(arr);

  std::vector<std::pair<int, int>> ans;

  for (auto unt : arr) {
    if ((ans.empty()) || (unt.first > ans.back().second)) {
      ans.push_back(unt);
    } else {
      ans.back().second = std::max(ans.back().second, unt.second);
    }
  }

  std::cout << ans.size() << '\n';

  for (auto unt : ans) {
    std::cout << unt.first << ' ' << unt.second << '\n';
  }

  return 0;
}
