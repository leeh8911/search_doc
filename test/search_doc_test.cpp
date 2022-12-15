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

TEST(SearchDocTest, FindKeywordInNoneEmptyRepositoryCase) {
    auto repo = std::make_unique<MockRepository>();

    value_object::DocumentList docs{};
    value_object::Document empty_keyword("empty keyword", std::set<std::string>{});
    value_object::Document manual("manual", std::set<std::string>{"something"});
    docs.emplace_back(empty_keyword);
    docs.emplace_back(manual);

    repo->Update(docs);

    api::SearchDoc sut(std::move(repo));

    auto result = sut.Find("something");

    EXPECT_EQ(1, result.size());
    EXPECT_EQ(manual, result.front());
}

TEST(SearchDocTest, NonExistKeyword) {
    auto repo = std::make_unique<MockRepository>();

    value_object::DocumentList docs{};
    value_object::Document empty_keyword("empty keyword", std::set<std::string>{});
    value_object::Document manual("manual", std::set<std::string>{"something"});
    docs.emplace_back(empty_keyword);
    docs.emplace_back(manual);

    repo->Update(docs);

    api::SearchDoc sut(std::move(repo));

    auto result = sut.Find("blah");

    EXPECT_EQ(0, result.size());
}
}  // namespace search_doc::test