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
Document::Document(std::string name, std::set<std::string> keywords, fs::file_time_type filetime)
    : name_(std::move(name)), keywords_(std::move(keywords)), filetime_(filetime) {}

Document::Document(const std::filesystem::directory_entry& entry)
    : name_(entry.path().string()), keyword_map_(), keywords_(), filetime_(entry.last_write_time()) {
    Read();
}

bool Document::operator==(const Document& other) const {
    if (name_ != other.name_) return false;
    if (filetime_ != other.filetime_) return false;
    if (keywords_.size() != other.keywords_.size()) return false;

    auto this_it = std::begin(keywords_);
    auto other_it = std::begin(other.keywords_);

    for (; this_it != std::end(keywords_); ++this_it, ++other_it) {
        if (*this_it != *other_it) {
            return false;
        }
    }

    return true;
}

bool Document::Contains(std::string keyword) const { return keywords_.contains(keyword); }

void Document::Read() {
    std::ifstream fs;
    fs.open(name_);

    std::string word;
    size_t count = 0;
    while (fs >> word) {
        keywords_.emplace(word);
        auto& index = keyword_map_[word];
        index.emplace(count++);
    }
}

std::ostream& operator<<(std::ostream& os, const Document& doc) {
    os << doc.name_ << "["
       << std::chrono::duration_cast<std::chrono::milliseconds>(doc.filetime_.time_since_epoch()).count() << "]"
       << ": {";

    std::copy(std::begin(doc.keywords_), std::end(doc.keywords_), std::ostream_iterator<std::string>(os, ", "));
    os << "}";
    return os;
}

}  // namespace search_doc::value_object
