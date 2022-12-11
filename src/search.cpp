/// @file search.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-11
///
/// @copyright Copyright (c) 2022
///

#include "/develop/src/search.h"

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>

namespace search_doc::search {

SearchEngine::SearchEngine(std::string root) : mTargetExtension{"doc", "txt", "md"} {
    using namespace std::string_literals;  // NOLINT

    std::ostream_iterator<std::string> os_it(std::cout, " ");
    std::copy(std::begin(mTargetExtension), std::end(mTargetExtension), os_it);
}
}  // namespace search_doc::search
