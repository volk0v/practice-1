#pragma once

#include <cstring>

namespace console_parser {

const char* GetWordFromArguments(int argc, const char** argv);
const char* GetFilenameFromArguments(int argc, const char** argv);

};  // namespace console_parser
