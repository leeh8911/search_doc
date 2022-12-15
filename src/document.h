/// @file document.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_DOCUMENT_H_
#define SRC_DOCUMENT_H_

#include <set>
#include <string>
#include <vector>

namespace search_doc::value_object {
class Document {
 public:
    explicit Document(std::string name, std::set<std::string> keywords = {});

 private:
    std::string name_{};
    std::set<std::string> keywords_{};
};

using DocumentList = std::vector<Document>;

}  // namespace search_doc::value_object

#endif  // SRC_DOCUMENT_H_
