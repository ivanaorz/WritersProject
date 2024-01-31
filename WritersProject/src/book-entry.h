#pragma once
#include <string>

class BookEntry {
public:
    BookEntry(const std::string& title, const std::string& author, const std::string& genre, int year);

    // COPY CONSTRUCTOR
    BookEntry(const BookEntry& other);

    // ASSIGNMENT OPERATOR
    BookEntry& operator=(const BookEntry& other);

    // DESTRUCTOR TO DELETE MEMORY
    ~BookEntry();


    std::string serialize() const;
    static BookEntry deserialize(const std::string& data);

    // Getter methods
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getYear() const;

    // Setter methods
    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setGenre(const std::string& newGenre);
    void setYear(int newYear);


private:
    std::string* title;
    std::string* author;
    std::string genre;
    int year;

};

