/// @file raii_file.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-18
///
/// @copyright Copyright (c) 2022
///
///

#ifndef TEST_UTIL_RAII_FILE_H_
#define TEST_UTIL_RAII_FILE_H_

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace search_doc::test::util {
namespace fs = std::filesystem;
class RAIIFile {
 public:
    explicit RAIIFile(std::string file_name);
    ~RAIIFile();

    RAIIFile& operator<<(std::string s);
    std::string Path() const;

 private:
    fs::path file_path{};
    std::ofstream file_stream{};
};
}  // namespace search_doc::test::util
#endif  // TEST_UTIL_RAII_FILE_H_
