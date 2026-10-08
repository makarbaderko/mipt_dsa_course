#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  std::string t;

  std::cin >> s >> t;

  int n = (int)s.size();

  std::vector<int> deletions(n);

  for (int i = 0; i < n; i++) {
    std::cin >> deletions[i];
    deletions[i]--;  // 0-based
  }

  int left = 0;
  int right = n + 1;
  // max symbols we can delete without problems
  while (left + 1 < right) {
    // try to delete mid if possible
    int mid = left + (right - left) / 2;

    std::vector<int> deleted(n, 0);

    for (int i = 0; i < mid; i++) {
      deleted[deletions[i]] = 1;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
      if ((deleted[i] == 0) && j < (int)t.size() && s[i] == t[j]) {
        j++;
      }
    }

    if (j == (int)t.size()) {
      left = mid;
    } else {
      right = mid;
    }
  }

  std::cout << left << '\n';

  return 0;
}