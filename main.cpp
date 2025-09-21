#include <console_parser.h>
#include <errors.h>
#include <file_parser.h>

#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cerr << errors::kWrongArgument << std::endl;
    return 1;
  }

  const char* word = console_parser::GetWordFromArguments(argc, argv);
  const char* file_name = console_parser::GetFilenameFromArguments(argc, argv);

  if (word == nullptr || file_name == nullptr) {
    std::cerr << errors::kWrongArgument << std::endl;
    return 1;
  }

  int correct_words = file_parser::ReadWordsAndCountCorrect(file_name, word);
  if (correct_words == -1) {
    return 1;
  }

  std::cout << correct_words << std::endl;

  return 0;
}
