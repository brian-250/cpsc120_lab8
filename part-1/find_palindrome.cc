// Grey Espinoza
// CPSC 120-12
// 2022-10-27
// gray@csu.fullerton.edu
// @CSUFgrey
//
// Lab 08-01
// Partners: @brian-250
//
// Program to print out Palindromes from a file
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& word) {
  if (word.length() <= 3) {
    return false;
  }
  std::string reversed_word{word.rbegin(), word.rend()};
  return (word == reversed_word);
}

int main(int argc, char const* argv[]) {
  std::vector<std::string> arguments =
      std::vector<std::string>{argv, argv + argc};
  if (arguments.size() != 2) {
    std::cout << "Please provide a path to a file. Exiting.\n";
    return 1;
  }
  std::string input_file_name{arguments.at(1)};
  std::ifstream input_file_stream{input_file_name};
  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << input_file_name
              << ". Exiting.\n";
    return 1;
  }
  while (input_file_stream.good()) {
    std::string line_buffer;
    std::getline(input_file_stream, line_buffer);
    if (IsPalindrome(line_buffer)) {
      std::cout << line_buffer << "\n";
    }
  }
  input_file_stream.close();
  return 0;
}