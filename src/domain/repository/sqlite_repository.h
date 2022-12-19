/// @file sqlite_repository.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-17
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_DOMAIN_REPOSITORY_SQLITE_REPOSITORY_H_
#define SRC_DOMAIN_REPOSITORY_SQLITE_REPOSITORY_H_

#include <string>

#include "src/domain/repository/repository.h"
#include "src/value_object/document.h"

namespace search_doc::domain {

class SqlRepository : public Repository {
 public:
    SqlRepository();
    value_object::DocumentList Query(std::string) override;
    void Update(const value_object::DocumentList& doc_list) override;
};
}  // namespace search_doc::domain

#endif  // SRC_DOMAIN_REPOSITORY_SQLITE_REPOSITORY_H_
