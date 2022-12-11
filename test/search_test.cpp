/// @file search_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-11
///
/// @copyright Copyright (c) 2022
///
///

#include "src/search.h"

#include <gtest/gtest.h>

// Search 는 OS에 포함된 파일 중 특정 확장자를 갖는 파일을 찾는 프로그램이다.

namespace search_doc::search::test {

TEST(SearchEngineTest, ConstructCase) { SearchEngine se("./"); }
}  // namespace search_doc::search::test
