#include "book-entry.h"
#include <sstream>

BookEntry::BookEntry(const std::string& title, const std::string& author, const std::string& genre, int year)
    : title(title), author(author), genre(genre), year(year) {}

std::string BookEntry::serialize() const {
    std::ostringstream oss;
    oss << title << '|' << author << '|' << genre << '|' << year;
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

std::string BookEntry::getTitle() const {
    return title;
}

std::string BookEntry::getAuthor() const {
    return author;
}

std::string BookEntry::getGenre() const {
    return genre;
}

int BookEntry::getYear() const {
    return year;
}

// Setter methods
void BookEntry::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void BookEntry::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void BookEntry::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void BookEntry::setYear(int newYear) {
    year = newYear;
}