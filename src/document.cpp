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
}  // namespace search_doc::value_object
