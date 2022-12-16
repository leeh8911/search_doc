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

#include "src/value_object/document.h"

namespace search_doc::api {

using domain::FileRootPtr;
using repository::RepositoryPtr;

SearchDoc::SearchDoc(RepositoryPtr repo, FileRootPtr root) : repo_(std::move(repo)), root_(std::move(root)) {}

value_object::DocumentList SearchDoc::Find(std::string keyword) { return repo_->Query(keyword); }

value_object::DocumentList SearchDoc::Collect() { return value_object::DocumentList{}; }
}  // namespace search_doc::api
