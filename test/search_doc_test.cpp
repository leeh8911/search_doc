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

#include "src/document.h"
#include "src/repository.h"
#include "test/mock_repository.h"

namespace search_doc::test {
TEST(SearchDocTest, FindNoneKeywordInEmptyRepositoryCase) {
    api::SearchDoc sut(std::make_unique<MockRepository>());

    value_object::DocumentList result = sut.Find("");

    EXPECT_EQ(0, result.size());
}
}  // namespace search_doc::test