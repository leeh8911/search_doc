/// @file search_doc_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#include "src/search_doc.h"

#include <gtest/gtest.h>

namespace search_doc {
namespace test {
TEST(SearchDocTest, FindNoneKeywordCase) {
    api::SearchDoc sut;

    api::DocumentList result = sut.Find("");

    EXPECT_EQ(0, result.size());
}
}  // namespace test
}  // namespace search_doc