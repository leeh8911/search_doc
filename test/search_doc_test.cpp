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
#include "test/mock/mock_file_root.h"
#include "test/mock/mock_repository.h"

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

// TODO(sangwon): SearchDoc Collection 파일 시스템을 순회를 돌며 문서를 찾고, 문서 안에 포함된 키워드를 추출하는 작업을
// 수행한다.
// TODO(sangwon): 파일시스템에 대한 인터페이스 필요
// TODO(sangwon): 목 파일 시스템을 통해 순회를 돌며 파일을 찾아 놓는다.
TEST(SearchDocTest, CollectNoneFilesCase) {
    auto repo = std::make_unique<MockRepository>();

    api::SearchDoc sut(std::move(repo));

    auto doc_lists = sut.Collect();
    EXPECT_EQ(0, doc_lists.size());
}

TEST(SearchDocTest, CollectSingleFileCase) {
    auto repo = std::make_unique<MockRepository>();
    auto root = std::make_unique<MockFileRoot>();

    api::SearchDoc sut(std::move(repo), std::move(root));

    auto doc_lists = sut.Collect();
    EXPECT_EQ(0, doc_lists.size());
}
}  // namespace search_doc::test