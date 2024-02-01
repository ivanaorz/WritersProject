#include "file-service.h"
#include <fstream>

void FileService::writeUserToFile(const std::string& filename, const std::string& username, const std::string& password) {
    std::ofstream file(filename, std::ios_base::app);
    if (file.is_open()) {
        file << username << '|' << password << '\n';
        file.close();
    }
}

std::vector<std::pair<std::string, std::string>> FileService::readUsersFromFile(const std::string& filename) {
    std::vector<std::pair<std::string, std::string>> users;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('|');
            if (pos != std::string::npos) {
                std::string username = line.substr(0, pos);
                std::string password = line.substr(pos + 1);
                users.push_back(std::make_pair(username, password));
            }
        }
        file.close();
    }
    return users;
}

bool FileService::writeBooksToFile(const std::string& filename, const std::vector<BookEntry>& entries) {
    std::ofstream file(filename, std::ios_base::app);
    if (file.is_open()) {
        std::vector<std::string> existingEntries = readExistingEntries(filename);

        for (const auto& entry : entries) {
            // Checking if the entry already exists in the file
            if (std::find(existingEntries.begin(), existingEntries.end(), entry.serialize()) == existingEntries.end()) {
                file << entry.serialize() << '\n';
            }
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

std::vector<std::string> FileService::readExistingEntries(const std::string& filename) {
    std::vector<std::string> existingEntries;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Checking if the line is not already in existingEntries
            if (std::find(existingEntries.begin(), existingEntries.end(), line) == existingEntries.end()) {
                existingEntries.push_back(line);
            }
        }
        file.close();
    }
    return existingEntries;
}

std::vector<BookEntry> FileService::readBooksFromFile(const std::string& filename) {
    std::vector<BookEntry> entries;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            BookEntry entry = BookEntry::deserialize(line);
            entries.push_back(entry);
        }
        file.close();
    }
    return entries;
}



