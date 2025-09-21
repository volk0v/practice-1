#include <errors.h>

#include <fstream>
#include <iostream>

namespace file_parser {

const size_t kMaxWordSize = 32;

int ReadWordsAndCountCorrect(const char* file_name, const char* expected_word) {
  std::ifstream is(file_name);
  if (!is.is_open()) {
    std::cerr << errors::kFailedToOpen << std::endl;
    return -1;
  }

  const size_t kLengthOfExpectedWord = strlen(expected_word);
  int amount_of_correct_words = 0;

  char word[kMaxWordSize + 1];
  while (is >> word) {
    int checked_letters[kLengthOfExpectedWord];
    for (int i = 0; i < kLengthOfExpectedWord; i++) {
      checked_letters[i] = 0;
    }

    for (char letter : word) {
      for (int i = 0; i < kLengthOfExpectedWord; i++) {
        if (letter == expected_word[i]) {
          checked_letters[i] = 1;
        }
      }
    }

    int amount_of_same_letters = 0;
    for (int element : checked_letters) {
      amount_of_same_letters += element;
    }

    if (amount_of_same_letters == kLengthOfExpectedWord) {
      amount_of_correct_words++;
    }
  }

  return amount_of_correct_words;
}
};  // namespace file_parser
