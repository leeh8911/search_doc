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

#include <filesystem>

#include "src/value_object/document.h"

namespace search_doc::domain::test {

TEST(ActualFileRootTest, TotalFilesCase) {
    ActualFileRoot sut("/develop/test/file_root/test_root", {".md"});

    auto doc_list = sut.Search();

    EXPECT_EQ(1, doc_list.size());

    std::filesystem::directory_entry expect_entry("/develop/test/file_root/test_root/test_file.md");
    EXPECT_EQ(value_object::Document(expect_entry), *doc_list.front());
}

TEST(ActualFileRootTest, KeywordCheckCase) {
    ActualFileRoot sut("/develop/test/file_root/test_root", {".md"});

    auto doc_list = sut.Search();

    auto doc = doc_list.front();
    EXPECT_TRUE(doc->Contains("Test"));
    EXPECT_TRUE(doc->Contains("File"));
}
}  // namespace search_doc::domain::test
