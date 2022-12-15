/// @file document.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#include "src/document.h"

#include <string>
#include <utility>
namespace search_doc::value_object {
Document::Document(std::string name, std::set<std::string> keywords)
    : name_(std::move(name)), keywords_(std::move(keywords)) {}

bool Document::operator==(const Document& other) const {
    if (name_ != other.name_) return false;
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

}  // namespace search_doc::value_object
