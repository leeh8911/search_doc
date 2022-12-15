/// @file repository.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_REPOSITORY_H_
#define SRC_REPOSITORY_H_

#include <memory>
#include <string>

#include "src/document.h"

namespace search_doc::repository {
/// @brief 데이터베이스를 다루기 위한 인터페이스 클래스
///
struct Repository {
    virtual ~Repository() = default;

    virtual value_object::DocumentList Query(std::string) = 0;
    virtual void Update(const value_object::DocumentList& doc_list) = 0;
};

using RepositoryPtr = std::unique_ptr<Repository>;

}  // namespace search_doc::repository

#endif  // SRC_REPOSITORY_H_
