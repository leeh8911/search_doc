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

namespace fs = std::filesystem;

SearchEngine::SearchEngine(std::string root) : mTargetExtension{".doc", ".txt", ".md"} {}

void FileSearchRecursive(std::string root) {
    std::unordered_set<std::string> mTargetExtension{".doc", ".txt", ".md"};
    for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(root)) {
        const fs::path& dir_path = dir_entry.path();
        if (mTargetExtension.contains(dir_path.extension())) {
            std::cout << "doc-" << dir_path << "\n";
        }
    }
}
}  // namespace search_doc::search
