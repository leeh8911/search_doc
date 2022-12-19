/// @file database_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-17
///
/// @copyright Copyright (c) 2022
///

#include "src/database/database.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <list>
#include <string>

#include "src/value_object/document.h"
#include "test/util/raii_file.h"

namespace search_doc::test {
namespace fs = std::filesystem;
TEST(DatabaseIntegratedTest, SampleCase) {
    util::RAIIFile file("dummy_file.dtxt");
    value_object::Document doc(file.Path());

    db::Database sut;

    EXPECT_TRUE(sut.Open("test.sqlite"));

    EXPECT_TRUE(sut.Upsert(doc));

    auto string_list = sut.GetAllRecords();

    for (auto str : string_list) {
        std::cout << str << "\n";
    }

    EXPECT_TRUE(sut.Close());
}
}  // namespace search_doc::test
