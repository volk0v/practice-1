#include <gtest/gtest.h>

#include <vector>

#include "console_parser.h"

TEST(ConsoleParserTests, Getting_word) {
  std::vector<const char*> args = {"./app", "--word", "test", "--file",
                                   "/path/to/file"};

  const char* word =
      console_parser::GetWordFromArguments(args.size(), args.data());

  ASSERT_EQ("test", word);
}

TEST(ConsoleParserTests, Getting_file) {
  std::vector<const char*> args = {"./app", "--word", "test", "--file",
                                   "/path/to/file"};

  const char* filename =
      console_parser::GetFilenameFromArguments(args.size(), args.data());

  ASSERT_EQ("/path/to/file", filename);
}
