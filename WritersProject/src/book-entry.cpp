#include "book-entry.h"
#include <sstream>
#include <iostream>

// I AM ALLOCATING MEMORY ON HEAP FOR TITLE AND AUTHOR
BookEntry::BookEntry(const std::string& title, const std::string& author, const std::string& genre, int year)
    : title(new std::string(title)), author(new std::string(author)), genre(genre), year(year) {}

// DESTRUCTOR TO DELETE MEMORY
BookEntry::~BookEntry() {
    delete title;
    delete author;
}

// COPY CONSTRUCTOR
BookEntry::BookEntry(const BookEntry& other)
    : title(new std::string(*(other.title))), author(new std::string(*(other.author))), genre(other.genre), year(other.year) {}

// ASSIGNMENT OPERATOR
BookEntry& BookEntry::operator=(const BookEntry& other) {
    if (this != &other) {
        delete title;
        delete author;

        title = new std::string(*(other.title));
        author = new std::string(*(other.author));
        genre = other.genre;
        year = other.year;
    }
    return *this;
}

std::string BookEntry::serialize() const {
    std::ostringstream oss;
    oss << *title << '|' << *author << '|' << genre << '|' << year;
    return oss.str();
}


BookEntry BookEntry::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string title, author, genre;
    int year;

    std::getline(iss, title, '|');
    std::getline(iss, author, '|');
    std::getline(iss, genre, '|');
    iss >> year;

    return BookEntry(title, author, genre, year);
}


// Getter methods
std::string BookEntry::getTitle() const {
    return (title != nullptr) ? *title : "";
}

std::string BookEntry::getAuthor() const {
    return (author != nullptr) ? *author : "";
}

std::string BookEntry::getGenre() const {
    return genre;
}

int BookEntry::getYear() const {
    return year;
}

// Setter methods
void BookEntry::setTitle(const std::string& newTitle) {
    *title = newTitle;
}

void BookEntry::setAuthor(const std::string& newAuthor) {
    *author = newAuthor;
}

void BookEntry::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void BookEntry::setYear(int newYear) {
    year = newYear;
}