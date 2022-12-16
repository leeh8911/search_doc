/// @file document.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#include "src/value_object/document.h"

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

namespace search_doc::value_object {

namespace fs = std::filesystem;

Document::Document(std::string fullfile) : Document(fs::directory_entry(fullfile)) {}

Document::Document(const std::filesystem::directory_entry& entry)
    : name_(entry.path().filename().string()),
      path_(entry.path().parent_path().string()),
      keyword_map_(),
      filetime_(entry.last_write_time()) {
    Read();
}

bool Document::operator==(const IDocument& other) const {
    if (name_ != other.Name()) return false;
    if (filetime_ != other.Filetime()) return false;

    return true;
}

bool Document::Contains(std::string keyword) const { return keyword_map_.contains(keyword); }

std::string Document::Name() const { return name_; }

std::string Document::Path() const { return path_; }

std::map<std::string, std::set<size_t>> Document::KeywordMap() const { return keyword_map_; }

fs::file_time_type Document::Filetime() const { return filetime_; }

void Document::Read() {
    std::ifstream fs;
    fs.open(path_ + "/" + name_);

    std::string word;
    size_t count = 0;
    while (fs >> word) {
        auto& index = keyword_map_[word];
        index.emplace(count++);
    }
}

std::ostream& operator<<(std::ostream& os, const Document& doc) {
    os << doc.path_ << "/" << doc.name_ << "["
       << std::chrono::duration_cast<std::chrono::milliseconds>(doc.filetime_.time_since_epoch()).count() << "]"
       << ": {";

    std::vector<std::string> temp_format{};
    auto format = [](const std::pair<std::string, std::set<size_t>>& p) {
        std::string result = p.first;
        result += ":[";
        for (auto index : p.second) {
            result += std::to_string(index) + ", ";
        }
        result += "]";
        return result;
    };

    std::transform(std::begin(doc.keyword_map_), std::end(doc.keyword_map_), std::back_inserter(temp_format), format);
    std::copy(std::begin(temp_format), std::end(temp_format), std::ostream_iterator<std::string>(os, ", "));
    os << "}";
    return os;
}

}  // namespace search_doc::value_object
