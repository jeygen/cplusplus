// practice nice
#include <iostream>

// count letters, count words, count lines
// fizzbuzz
// fibo, factorial
// is_prime, is_even
// sum_digits, count_digits, reverse_number
// swap
// is_palindrome, is_anagram, count_vowels
// is_power_of_2, bin_to_dec, dec_to_bin
// bitwise
// gcd, lcm
// and more?

// linkedlist, stack, queue/fifo

// dpi
// something to demonstrate virtual functions and inheritance

// head -> next -> next

#include <iostream>

int small(int x, int y) {
  if (x <= y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  int a {5};
  int b {7};
  int c {-1};

  std::cout << "a  b " << small(a,b) << '\n';
  std::cout << "a  c " << small(a,c) << '\n';
  std::cout << "c  b " << small(c,b) << '\n';
  
  return 0;
}

