/// @file database.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-17
///
/// @copyright Copyright (c) 2022
///
///

#include "src/database/database.h"

#include <sqlite3.h>

#include <chrono>
#include <iostream>
#include <list>
#include <memory>
#include <string>

#include "src/value_object/document.h"
namespace search_doc::db {

const std::string kQueryTableCreate =
    "CREATE TABLE Document(Name TEXT, Path TEXT, Keyword TEXT, DocIndex TEXT, Time TEXT);";

const std::string kQueryTableExist = "SELECT name FROM sqlite_master WHERE type='table' AND name='Document';";

const std::string kQueryTableDrop = "DROP TABLE IF EXISTS Document;";

const std::string kQueryTableExistRecord =
    "SELECT Name FROM Document WHERE Path=? AND Keyword=? AND DocIndex=? AND Time=?;";

const std::string kQueryTableDeleteRecord = "DELETE FROM Document WHERE Name=?;";

const std::string kQueryTableUpsertRecord = "INSERT OR REPLACE INTO Document VALUES(?, ?, ?, ?, ?);";

const std::string kQueryTableSelectAll = "SELECT Name FROM Document;";

const std::string kQueryDbCleanUp = "VACUUM;";

const std::string kQueryDbBegin = "BEGIN;";

const std::string kQueryDbCommit = "COMMIT;";

const std::string kQueryDbRollback = "ROLLBACK;";

bool Database::Open(std::string file_name) {
    int rc = sqlite3_open(file_name.c_str(), &db);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    if (IsTableExist() == false) {
        CreateTable();
    }

    return true;
}

bool Database::Close() { return (sqlite3_close(db) == SQLITE_OK); }

bool Database::Upsert(const value_object::Document& doc) {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableUpsertRecord.c_str();
    bool result = true;

    auto keyword_map = doc.KeywordMap();
    auto time = doc.Filetime();

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, doc.Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 22, doc.Path().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 22, "", -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 22, "", -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 22, time.c_str(), -1, SQLITE_STATIC);

    // begin
    this->Begin();
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fwprintf(stderr, L"line %d: %s\n", __LINE__, sqlite3_errmsg16(this->db));
        result = false;
    }
    // commit
    this->Commit();

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    return result;
}

bool Database::Delete(std::string file_path) {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableDeleteRecord.c_str();
    bool result = true;

    sqlite3_prepare16_v2(db, query, -1, &stmt, nullptr);
    sqlite3_bind_text16(stmt, 1, file_path.c_str(), -1, SQLITE_STATIC);

    // begin
    this->Begin();
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }
    // commit
    this->Commit();

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    return result;
}

std::list<std::string> Database::GetAllRecords() {
    std::list<std::string> result;
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableSelectAll.c_str();

    sqlite3_prepare16_v2(db, query, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int type = sqlite3_column_type(stmt, 0);
        if (type != SQLITE_TEXT) {
            continue;
        }
        std::string file_name((char*)(sqlite3_column_text(stmt, 0)));  // NOLINT
        result.push_back(file_name);
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::DropTable() {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableDrop.c_str();
    bool result = true;

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

    // begin
    Begin();
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }
    // commit
    Commit();

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::CreateTable() {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableCreate.c_str();
    bool result = true;

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    Begin();
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }

    Commit();

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::IsTableExist() {
    bool result = false;
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryTableExist.c_str();

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = true;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::Begin() {
    bool result = false;
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryDbBegin.c_str();

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::Commit() {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryDbCommit.c_str();
    bool result = true;

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}

bool Database::Rollback() {
    sqlite3_stmt* stmt = nullptr;
    const char* query = kQueryDbRollback.c_str();
    bool result = true;

    sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        result = false;
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);

    return result;
}
}  // namespace search_doc::db
