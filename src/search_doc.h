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

namespace search_doc {
namespace api {

using Document = std::map<std::string, size_t>;
using DocumentList = std::vector<Document>;

class SearchDoc {
 public:
    SearchDoc() = default;

    DocumentList Find(std::string keyword);
    DocumentList Collect();
};
}  // namespace api
}  // namespace search_doc

#endif  // SRC_SEARCH_DOC_H_
