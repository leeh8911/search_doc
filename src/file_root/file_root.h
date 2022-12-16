/// @file file_root/file_root.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_FILE_ROOT_FILE_ROOT_H_
#define SRC_FILE_ROOT_FILE_ROOT_H_

#include <memory>
#include <set>
#include <string>

#include "../value_object/document.h"

namespace search_doc::domain {
struct FileRoot {
    virtual ~FileRoot() = default;

    virtual value_object::DocumentList Search() = 0;
};

using FileRootPtr = std::unique_ptr<FileRoot>;

class ActualFileRoot : public FileRoot {
 public:
    explicit ActualFileRoot(std::string root_path, std::set<std::string> extensions);
    value_object::DocumentList Search() override;

 private:
    std::string root_path_{};
    std::set<std::string> extensions_{};
};
}  // namespace search_doc::domain

#endif  // SRC_FILE_ROOT_FILE_ROOT_H_
