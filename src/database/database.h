/// @file database.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-17
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_DATABASE_DATABASE_H_
#define SRC_DATABASE_DATABASE_H_

#include <sqlite3.h>

#include <filesystem>
#include <list>
#include <string>

#include "src/value_object/document.h"

namespace search_doc::db {

class Database {
 public:
    bool Open(std::string file_name);
    bool Close();
    bool Upsert(const value_object::Document& doc);
    bool Delete(std::string key);
    std::list<std::string> GetAllRecords();

 private:
    sqlite3* db;

    bool DropTable();
    bool CreateTable();
    bool IsTableExist();

    bool Begin();
    bool Commit();
    bool Rollback();
};
}  // namespace search_doc::db

#endif  // SRC_DATABASE_DATABASE_H_
