#include <cstring>
#include <fstream>
#include <iostream>

#define MAX_WORD_SIZE 32

namespace errors {
const char* WRONG_ARGUMENT =
    "Wrong arguments! You must use --file <filename> and --word <word>";
const char* FAILED_TO_OPEN_FILE = "Failed to open file!";
};  // namespace errors

namespace consoleparser {

char* getValueOfArgument(int argc, char** argv, char* argumentName) {
  if (argc < 5) {
    return nullptr;
  }

  for (int posOfArgument = 1; posOfArgument <= 3; posOfArgument += 2) {
    if (strcmp(argv[posOfArgument], argumentName) == 0) {
      return argv[posOfArgument + 1];
    }
  }

  return nullptr;
}

char* getWordFromArguments(int argc, char** argv) {
  return getValueOfArgument(argc, argv, (char*)"--word");
}

char* getFilenameFromArguments(int argc, char** argv) {
  return getValueOfArgument(argc, argv, (char*)"--file");
}

};  // namespace consoleparser

namespace fileparser {

int readWordsAndCountCorrect(const char* fileName, const char* expectedWord) {
  std::ifstream is(fileName);
  if (!is.is_open()) {
    std::cerr << errors::FAILED_TO_OPEN_FILE << std::endl;
    return -1;
  }

  const int LENGTH_OF_EXPECTED_WORD = strlen(expectedWord);
  int amountOfCorrectWords = 0;

  char word[MAX_WORD_SIZE + 1];
  is >> word;
  while (!is.eof()) {
    int checkedLetters[LENGTH_OF_EXPECTED_WORD];
    for (int i = 0; i < LENGTH_OF_EXPECTED_WORD; i++) {
      checkedLetters[i] = 0;
    }

    for (int i = 0; i < strlen(word); i++) {
      char letter = word[i];

      for (int j = 0; j < LENGTH_OF_EXPECTED_WORD; j++) {
        if (letter == expectedWord[j]) {
          checkedLetters[j] = 1;
        }
      }
    }

    int amountOfSameLetters = 0;
    for (int i = 0; i < LENGTH_OF_EXPECTED_WORD; i++) {
      amountOfSameLetters += checkedLetters[i];
    }

    if (amountOfSameLetters == LENGTH_OF_EXPECTED_WORD) {
      amountOfCorrectWords++;
    }

    is >> word;
  }

  is.close();

  return amountOfCorrectWords;
}
};  // namespace fileparser

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cerr << errors::WRONG_ARGUMENT << std::endl;
    return 1;
  }

  const char* word = consoleparser ::getWordFromArguments(argc, argv);
  const char* fileName = consoleparser ::getFilenameFromArguments(argc, argv);

  if (word == nullptr || fileName == nullptr) {
    std::cerr << errors::WRONG_ARGUMENT << std::endl;
    return 1;
  }

  int correctWords = fileparser::readWordsAndCountCorrect(fileName, word);
  if (correctWords == -1) {
    return 1;
  }

  std::cout << correctWords << std::endl;

  return 0;
}
