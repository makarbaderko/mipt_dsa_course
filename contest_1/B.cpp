#include <cmath>
#include <iostream>
#include <vector>

int main() {
  const int cPrecision = 6;
  std::cout << std::fixed;
  std::cout.precision(cPrecision);

  int n;
  std::cin >> n;
  std::vector<double> arr(n);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  // Precomputation
  std::vector<double> prefix_log(n + 1);
  prefix_log[0] = 0;

  // prefix_log[i] = ln (a[0] * ... * a[i-1])
  for (int i = 1; i < n + 1; i++) {
    prefix_log[i] = prefix_log[i - 1] + std::log(arr[i - 1]);
  }

  // Requests
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int l;
    int r;
    std::cin >> l >> r;
    double ans =
        std::exp((prefix_log[r + 1] - prefix_log[l]) / (double)(r - l + 1.0));
    std::cout << ans << "\n";
  }
  return 0;
}