#include <cstring>
#include <fstream>
#include <iostream>

#include "console_parser.hpp"
#include "errors.hpp"
#include "file_parser.hpp"

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cerr << errors::kWrongArgument << std::endl;
    return 1;
  }

  const char* word = console_parser::GetWordFromArguments(
      argc, const_cast<const char**>(argv));
  const char* file_name = console_parser::GetFilenameFromArguments(
      argc, const_cast<const char**>(argv));

  if (word == nullptr || file_name == nullptr) {
    std::cerr << errors::kWrongArgument << std::endl;
    return 1;
  }

  int correct_words = file_parser::ReadWordsAndCountCorrect(file_name, word);
  if (correct_words == -1) return 1;

  std::cout << correct_words << std::endl;

  return 0;
}
