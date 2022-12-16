/// @file mock_repository.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#include "test/mock/mock_repository.h"

#include <algorithm>

namespace search_doc::test {
value_object::DocumentList MockRepository::Query(std::string name) {
    value_object::DocumentList result{};
    result.reserve(doc_list_.size());

    for (const auto& doc : doc_list_) {
        if (doc.Contains(name)) {
            result.emplace_back(doc);
        }
    }
    return result;
}

void MockRepository::Update(const value_object::DocumentList& doc_list) {
    std::copy(std::begin(doc_list), std::end(doc_list), std::back_inserter(doc_list_));
}

}  // namespace search_doc::test