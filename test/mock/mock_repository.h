/// @file mock_repository.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///
///

#ifndef TEST_MOCK_MOCK_REPOSITORY_H_
#define TEST_MOCK_MOCK_REPOSITORY_H_

#include <string>

#include "src/repository.h"
#include "src/value_object/document.h"
namespace search_doc::test {
class MockRepository : public repository::Repository {
 public:
    ~MockRepository() override = default;
    MockRepository() = default;

    value_object::DocumentList Query(std::string name) override;
    void Update(const value_object::DocumentList& doc_list) override;

 private:
    value_object::DocumentList doc_list_{};
};
}  // namespace search_doc::test
#endif  // TEST_MOCK_MOCK_REPOSITORY_H_
