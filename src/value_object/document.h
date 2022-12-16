/// @file document.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_VALUE_OBJECT_DOCUMENT_H_
#define SRC_VALUE_OBJECT_DOCUMENT_H_

#include <filesystem>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace search_doc::value_object {
namespace fs = std::filesystem;
class Document {
 public:
    explicit Document(std::string name, std::set<std::string> keywords = {}, fs::file_time_type filetime = {});
    explicit Document(const fs::directory_entry& entry);

    bool operator==(const Document& other) const;
    bool Contains(std::string keyword) const;

    friend std::ostream& operator<<(std::ostream& os, const Document& doc);

 private:
    std::string name_{};
    std::map<std::string, std::set<size_t>> keyword_map_{};
    std::set<std::string> keywords_{};
    fs::file_time_type filetime_{};

    void Read();
};

using DocumentList = std::vector<Document>;

}  // namespace search_doc::value_object

#endif  // SRC_VALUE_OBJECT_DOCUMENT_H_
