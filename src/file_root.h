/// @file file_root.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_FILE_ROOT_H_
#define SRC_FILE_ROOT_H_

#include <memory>

namespace search_doc::domain {
struct FileRoot {
    virtual ~FileRoot() = default;
};

using FileRootPtr = std::unique_ptr<FileRoot>;
}  // namespace search_doc::domain

#endif  // SRC_FILE_ROOT_H_
