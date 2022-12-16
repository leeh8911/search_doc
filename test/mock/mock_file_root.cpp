/// @file mock_file_root.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#include "test/mock/mock_file_root.h"

#include "src/document.h"

namespace search_doc::test {
value_object::DocumentList MockFileRoot::Search() {
    value_object::DocumentList result{};

    return result;
}
}  // namespace search_doc::test
