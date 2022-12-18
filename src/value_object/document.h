/// @file document.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-12-14
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_VALUE_OBJECT_DOCUMENT_H_
#define SRC_VALUE_OBJECT_DOCUMENT_H_

#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace search_doc::value_object {
namespace fs = std::filesystem;

/// @brief Document 클래스의 인터페이스이다.
///
struct IDocument {
    virtual ~IDocument() = default;

    virtual bool operator==(const IDocument& other) const = 0;
    virtual bool Contains(std::string keyword) const = 0;

    //  protected:
    virtual std::string Name() const = 0;
    virtual std::string Path() const = 0;
    virtual std::map<std::string, std::set<size_t>> KeywordMap() const = 0;
    virtual std::string Filetime() const = 0;
};

/// @brief Document class.
///
class Document : public IDocument {
 public:
    explicit Document(std::string fullfile);
    explicit Document(const fs::directory_entry& entry);

    bool operator==(const IDocument& other) const override;
    bool Contains(std::string keyword) const override;

    friend std::ostream& operator<<(std::ostream& os, const Document& doc);

    std::string Name() const override;
    std::string Path() const override;
    std::map<std::string, std::set<size_t>> KeywordMap() const override;
    std::string Filetime() const override;

 private:
    std::string name_{};
    std::string path_{};
    std::map<std::string, std::set<size_t>> keyword_map_{};
    fs::file_time_type filetime_{};

    void Read();
};

using DocumentPtr = std::shared_ptr<Document>;
using DocumentList = std::vector<DocumentPtr>;

}  // namespace search_doc::value_object

#endif  // SRC_VALUE_OBJECT_DOCUMENT_H_
