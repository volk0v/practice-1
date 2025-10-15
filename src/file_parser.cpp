#include "file_parser.hpp"

#include <fstream>

#include "errors.hpp"

namespace file_parser {

const size_t kMaxWordSize = 32;

bool IsCorrectWord(const char* word, const char* expected_word,
                   const size_t expected_length) {
  int checked_letters[expected_length];
  for (int i = 0; i < expected_length; i++) {
    checked_letters[i] = 0;
  }

  const size_t word_length = strlen(word);
  for (int i = 0; i < word_length; i++) {
    char letter = word[i];
    for (int j = 0; j < expected_length; j++) {
      if (letter == expected_word[j]) {
        checked_letters[j] = 1;
      }
    }
  }

  int amount_of_same_letters = 0;
  for (int element : checked_letters) {
    amount_of_same_letters += element;
  }

  if (amount_of_same_letters != expected_length) return false;

  return true;
}

int ReadWordsAndCountCorrect(const char* file_name, const char* expected_word) {
  std::ifstream input_file(file_name);
  if (!input_file.is_open()) return -1;

  const size_t expected_length = strlen(expected_word);
  int amount_of_correct_words = 0;

  char word[kMaxWordSize + 1];
  while (input_file >> word) {
    if (IsCorrectWord(word, expected_word, expected_length)) {
      amount_of_correct_words++;
    }
  }

  return amount_of_correct_words;
}

};  // namespace file_parser
