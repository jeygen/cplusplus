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


// includes ///////////////////////////////////////////
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <cctype>
///////////////////////////////////////////////////////

int main(int argv, chars* argc[]) {
  // provide function name for each attempt
  std::string arg = argv[1];
  std::cout << "Running with arg: " << arg << '\n';

  if (arg == std::string("analyze_file") {
      std::string filename = "practice.cpp";
      FileStats stats = analyze_file(filename);
      print_stats(filename, stats);
  }

  return 0;
}   

// file counts

struct FileStats {
    std::unordered_map<char, int> letter_counts;
    size_t word_count = 0; // size_t is what sizeof returns, cpp way 
    size_t line_count = 0; // it is unsigned int
};

FileStats analyze_file(const std::string& filename) {
    FileStats stats;
//  std::ifstream file = std::ifstream(file) // copy style is not prefered
    std::ifstream file(filename); // direct initialization is prefered

    if (!file) {
        std::cerr << "Error: File '" << filename << "' not found.\n";
        return {};
    }

    std::string line;
    while (std::getline(file, line)) {
        ++stats.line_count;

        bool in_word = false;
        for (char ch : line) {
            unsigned char uc = static_cast<unsigned char>(ch);
            ch = static_cast<char>(std::tolower(uc));

            if (std::isalpha(uc))
                ++stats.letter_counts[ch];

            if (std::isspace(uc) || std::ispunct(uc)) {
                if (in_word) {
                    ++stats.word_count;
                    in_word = false;
                }
            } else {
                in_word = true;
            }
        }
        if (in_word)
            ++stats.word_count;
    }

    return stats;
}

void print_stats(const std::string& filename, const FileStats& stats) {
    std::cout << "File: " << filename << "\n";
    std::cout << "Lines: " << stats.line_count << "\n";
    std::cout << "Words: " << stats.word_count << "\n";
    std::cout << "\nLetter frequencies:\n";
    for (const auto& [letter, count] : stats.letter_counts)
        std::cout << letter << ": " << count << '\n';
}

int main() {
    return 0;
}















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




