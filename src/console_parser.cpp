#include <cstring>

namespace console_parser {

char* GetValueOfArgument(int argc, char** argv, const char* argument_name) {
  if (argc < 5) {
    return nullptr;
  }

  for (int pos_of_arg = 1; pos_of_arg <= 3; pos_of_arg += 2) {
    if (strcmp(argv[pos_of_arg], argument_name) == 0) {
      return argv[pos_of_arg + 1];
    }
  }

  return nullptr;
}

char* GetWordFromArguments(int argc, char** argv) {
  return GetValueOfArgument(argc, argv, "--word");
}

char* GetFilenameFromArguments(int argc, char** argv) {
  return GetValueOfArgument(argc, argv, "--file");
}

};  // namespace console_parser
