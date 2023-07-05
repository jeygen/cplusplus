// Copyright 2023 Josh

// before linting

// bs returns -1 for no index o/w returns index of target

#include <vector>
#include <iostream>

int bs(const std::vector<int>& v, int target) {
  int mid = 0;
  int l = 0;
  int r = v.size() - 1;

  while (l <= r) {
    mid = l + (r - l) / 2;
    if (target == v[mid]) {
      return mid;
    } else if (target < v[mid]) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}


int main() {
  std::vector<int> v = {1, 2, 345};
  std::cout << bs(v, 2) << std::endl;
  std::cout << bs(v, 9) << std::endl;
  return 0;
}
