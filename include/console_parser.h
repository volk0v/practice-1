#pragma once

#include <cstring>

namespace console_parser {
char* GetWordFromArguments(int argc, char** argv);
char* GetFilenameFromArguments(int argc, char** argv);
};  // namespace console_parser
