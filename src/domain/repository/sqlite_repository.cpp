/// @file sqlite_repository.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-17
///
/// @copyright Copyright (c) 2022
///
///

#include "src/domain/repository/sqlite_repository.h"

extern "C" {
#include <sqlite3.h>
}

#include <exception>

#include "src/value_object/document.h"

namespace search_doc::domain {
SqlRepository::SqlRepository() {
    sqlite3* db = nullptr;
    sqlite3_stmt* res = nullptr;

    int rc = sqlite3_open(":memory:", &db);

    if (rc != SQLITE_OK) {
        sqlite3_close(db);
    }

    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, nullptr);

    if (rc != SQLITE_OK) {
        sqlite3_close(db);
    }

    rc = sqlite3_step(res);

    if (rc == SQLITE_ROW) {
        printf("%s\n", sqlite3_column_text(res, 0));
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
}

value_object::DocumentList SqlRepository::Query(std::string) { return value_object::DocumentList{}; }

void SqlRepository::Update(const value_object::DocumentList& doc_list) { doc_list.size(); }
}  // namespace search_doc::domain
