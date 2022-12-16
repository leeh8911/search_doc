/// @file file_root.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#include "src/file_root/file_root.h"

#include <filesystem>
#include <set>
#include <string>
#include <utility>

#include "../value_object/document.h"

namespace fs = std::filesystem;

namespace search_doc::domain {
ActualFileRoot::ActualFileRoot(std::string root_path, std::set<std::string> extensions)
    : root_path_(std::move(root_path)), extensions_(std::move(extensions)) {}

value_object::DocumentList ActualFileRoot::Search() {
    value_object::DocumentList doc_list{};
    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(fs::path(root_path_))) {
        if (extensions_.contains(entry.path().extension())) {
            doc_list.emplace_back(std::make_shared<value_object::Document>(entry));
        }
    }

    return doc_list;
}

}  // namespace search_doc::domain
