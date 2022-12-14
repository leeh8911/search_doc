/// @file search.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-11
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_SEARCH_H_
#define SRC_SEARCH_H_

#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_set>

namespace search_doc::search {

/// @brief 최근 업데이트가 진행된 문서 파일을 찾아줍니다.
class SearchEngine {
 public:
    explicit SearchEngine(std::string root = "~/");

 private:
    std::unordered_set<std::string> mTargetExtension{};
};
}  // namespace search_doc::search

#endif  // SRC_SEARCH_H_
