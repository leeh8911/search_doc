/// @file mock_file_root.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef TEST_MOCK_MOCK_FILE_ROOT_H_
#define TEST_MOCK_MOCK_FILE_ROOT_H_

#include "src/file_root/file_root.h"

namespace search_doc::test {
class MockFileRoot : public domain::FileRoot {
    value_object::DocumentList Search() override;
};
}  // namespace search_doc::test

#endif  // TEST_MOCK_MOCK_FILE_ROOT_H_
