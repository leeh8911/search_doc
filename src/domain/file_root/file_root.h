/// @file file_root/file_root.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_DOMAIN_FILE_ROOT_FILE_ROOT_H_
#define SRC_DOMAIN_FILE_ROOT_FILE_ROOT_H_

#include <filesystem>
#include <memory>
#include <set>
#include <string>

#include "src/value_object/document.h"

namespace search_doc::domain {
struct FileRoot {
    virtual ~FileRoot() = default;

    virtual value_object::DocumentList Search() = 0;
};
using FileRootPtr = std::unique_ptr<FileRoot>;

namespace fs = std::filesystem;
class ActualFileRoot : public FileRoot {
 public:
    explicit ActualFileRoot(fs::path root_path, std::set<std::string> extensions);
    value_object::DocumentList Search() override;

 private:
    fs::path root_path_{};
    std::set<std::string> extensions_{};
};
}  // namespace search_doc::domain

#endif  // SRC_DOMAIN_FILE_ROOT_FILE_ROOT_H_
