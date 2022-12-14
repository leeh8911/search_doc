/// @file search_doc.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_SEARCH_DOC_H_
#define SRC_SEARCH_DOC_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "src/document.h"
#include "src/repository.h"
namespace search_doc::api {

class SearchDoc {
 public:
    explicit SearchDoc(repository::RepositoryPtr repo);

    value_object::DocumentList Find(std::string keyword);
    value_object::DocumentList Collect();

 private:
    repository::RepositoryPtr repo_{};
};
}  // namespace search_doc::api

#endif  // SRC_SEARCH_DOC_H_
