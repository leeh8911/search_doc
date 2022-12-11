/// @file filesystem.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-11
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_FILESYSTEM_H_
#define SRC_FILESYSTEM_H_

#include <unordered_set>

namespace search_doc::search::value_object {

class Node {
 public:
 private:
    std::unordered_set<Node*> children;
};
}  // namespace search_doc::search::value_object

#endif  // SRC_FILESYSTEM_H_
