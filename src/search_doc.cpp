/// @file search_doc.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#include "src/search_doc.h"

#include <string>
#include <utility>

#include "src/document.h"

namespace search_doc::api {
SearchDoc::SearchDoc(repository::RepositoryPtr repo) : repo_(std::move(repo)) {}

value_object::DocumentList SearchDoc::Find(std::string keyword) {
    value_object::DocumentList result{};

    return result;
}

value_object::DocumentList SearchDoc::Collect() { return value_object::DocumentList{}; }
}  // namespace search_doc::api
