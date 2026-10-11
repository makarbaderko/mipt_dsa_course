#include <cstdint>
#include <iostream>
#include <vector>

const int cBitsInByte = 8;
const int cByteValues = 256;
const int cBytesInNumber = 8;
const int c8BitExtractor = 0b11111111;

int ExtractByteValue(uint64_t x, const int& byte) {
  return (x >> (byte * cBitsInByte)) & c8BitExtractor;
}

void CountingSortByByte(std::vector<uint64_t>& arr, int byte) {
  // if byte == 0 -> sort by the rightmost
  std::vector<int> buckets(cByteValues, 0);
  std::vector<uint64_t> sorted(arr.size());

  for (uint64_t x : arr) {
    int byte_value = ExtractByteValue(x, byte);
    buckets[byte_value]++;
  }

  // Turn the bucket list into bucket prefix sum list to store bucket boundaries
  for (int i = 1; i < cByteValues; i++) {
    buckets[i] += buckets[i - 1];
  }

  for (int i = (int)(arr.size()) - 1; i >= 0; i--) {
    int byte_value = ExtractByteValue(arr[i], byte);
    sorted[buckets[byte_value] - 1] =
        arr[i];  // right boundary of previous bucket
    buckets[byte_value]--;
  }

  std::swap(arr, sorted);
}

void RadixSort(std::vector<uint64_t>& arr) {
  for (int byte = 0; byte < cBytesInNumber; byte++) {
    CountingSortByByte(arr, byte);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<uint64_t> arr(n);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  RadixSort(arr);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << '\n';
}

