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

namespace search_doc::test {
TEST(DatabaseIntegratedTest, SampleCase) {
    db::Database database;

    EXPECT_TRUE(database.Open("test.sqlite"));

    EXPECT_TRUE(database.Close());
}
}  // namespace search_doc::test
