#include <ifstream>
#include <iostream>
#include <string>

struct CountCity {
  std::unordered_map<char, size_t> char_count;
  size_t lines;
  size_t words;
};


std::unordered_map<char, size_t> count_char (std::string filename) {
  std::unordered_map<std::string, size_t> m{};
  std::ifstream f{filename};

  if (!f) std::cerr << "no file" << '\n';

  while(char c == get_char(f)) {
    m[c]++
  }
      
return m;




}

size_t count_lines (std::string& filename) {
  std::ifstream f{filename};
  size_t line_count{};

  if (!f) {
    std::cerr << "no file" << '\n';
    return 0;
  }


  std::string line;
  while(std::getline(f, line)) {
    ++line_count;

  }

  return line_count;
}

CountCity count_em(std::string filename) {

}
