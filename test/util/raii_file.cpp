/// @file raii_file.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-18
///
/// @copyright Copyright (c) 2022
///
///

#include "test/util/raii_file.h"

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace search_doc::test::util {
RAIIFile::RAIIFile(std::string file_name) : file_path() {
    file_path = fs::current_path().string() + file_name;

    file_stream.open(file_path, std::ios::app);
    file_stream.close();
}

RAIIFile::~RAIIFile() { fs::remove(file_path); }

RAIIFile& RAIIFile::operator<<(std::string s) {
    file_stream.open(file_path, std::ios::app);

    file_stream << s;

    file_stream.close();

    return *this;
}

std::string RAIIFile::Path() const { return file_path; }
}  // namespace search_doc::test::util
