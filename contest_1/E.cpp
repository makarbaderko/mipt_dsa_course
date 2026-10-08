#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<long long> a(n);
  std::vector<long long> b(n);
  std::vector<long long> delta(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    delta[i] = b[i] - a[i];
  }

  int q;
  std::cin >> q;

  while ((q--) != 0) {
    long long x;
    std::cin >> x;

    // find first i where delta_i <= x
    int left = 0;
    int right = n;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (delta[mid] <= x) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    if (left == 0) {
      std::cout << 1 << '\n';
    } else if (left == n) {
      std::cout << n << '\n';
    } else {
      if (a[left] + x <= a[left - 1] + delta[left - 1]) {
        std::cout << left + 1 << '\n';
      } else {
        std::cout << left << '\n';
      }
    }
  }
  return 0;
}