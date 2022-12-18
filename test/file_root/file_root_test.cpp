/// @file file_root_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#include "src/domain/file_root/file_root.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>

#include "src/value_object/document.h"
#include "test/util/raii_file.h"

namespace search_doc::test {
namespace fs = std::filesystem;

TEST(ActualFileRootTest, TotalFilesCase) {
    util::RAIIFile file("dummy.dtxt");
    file << "Test "
         << "File";

    fs::path file_path = file.Path();

    domain::ActualFileRoot sut(file_path.parent_path().string(), {file_path.extension()});

    auto doc_list = sut.Search();

    EXPECT_EQ(1, doc_list.size());

    std::filesystem::directory_entry expect_entry(file.Path());
    EXPECT_EQ(value_object::Document(expect_entry), *doc_list.front());
}

TEST(ActualFileRootTest, KeywordCheckCase) {
    util::RAIIFile file("dummy.dtxt");
    file << "Test "
         << "File";

    fs::path file_path = file.Path();

    domain::ActualFileRoot sut(file_path.parent_path().string(), {file_path.extension()});

    auto doc_list = sut.Search();

    auto doc = doc_list.front();
    EXPECT_TRUE(doc->Contains("Test")) << *doc;
    EXPECT_TRUE(doc->Contains("File")) << *doc;
}
}  // namespace search_doc::test
