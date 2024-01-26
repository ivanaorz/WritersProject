#pragma once
#include <string>
#include <vector>
#include "book-entry.h"

class FileService {
public:
    static void writeUserToFile(const std::string& filename, const std::string& username, const std::string& password);
    static std::vector<std::pair<std::string, std::string>> readUsersFromFile(const std::string& filename);

    bool writeBooksToFile(const std::string& filename, const std::vector<BookEntry>& entries);
    static std::vector<BookEntry> readBooksFromFile(const std::string& filename);
};
