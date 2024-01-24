#pragma once
#include <string>

class BookEntry {
public:
    BookEntry(const std::string& title, const std::string& author, const std::string& genre, int year);
    std::string serialize() const;
    static BookEntry deserialize(const std::string& data);

    // Getter methods
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getYear() const;

private:
    std::string title;
    std::string author;
    std::string genre;
    int year;
};
