/// @file file_root_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#include "src/file_root/file_root.h"

#include <gtest/gtest.h>

#include "src/document.h"

namespace search_doc::domain::test {

TEST(ActualFileRootTest, TotalFilesCase) {
    ActualFileRoot sut("./test_root", {"md"});

    auto doc_list = sut.Search();

    EXPECT_EQ(1, doc_list.size());
}
}  // namespace search_doc::domain::test