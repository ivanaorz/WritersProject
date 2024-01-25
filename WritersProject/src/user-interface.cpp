#include<iostream>
#include "user-interface.h"

using std::string;

void UserInterface::displayMainMenu() {
    std::cout << "\n===== Writers Hub Menu =====\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Log in\n";
    std::cout << "===========================\n";
}

void UserInterface::displayAccountMenu(string& username, string& password) {
    std::cout << "\n===== Create Account Menu =====\n";
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
}

void UserInterface::displayLoginMenu(string& username, string& password) {
    std::cout << "\n===== Login Menu =====\n";
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
}

void UserInterface::displayBookEntryMenu() {
    std::cout << "\n===== Book entry Menu =====\n";
    std::cout << "1. Create book entry\n";
    std::cout << "2. Read all book entries\n";
    std::cout << "3. Update book entry\n";
    std::cout << "4. Delete book entry\n";
    std::cout << "5. Log out\n";
}

void UserInterface::displayCreateBookEntryMenu(string& title, string& author, string& genre, int& year) {
    std::cout << "\n===== Create Book Entry =====\n";

    // Clearing the input buffer before reading the title
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter publication year: ";
    std::cin >> year;

    // Clearing the input buffer to avoid issues with subsequent cin operations
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void UserInterface::displayAllBookEntries(const std::vector<BookEntry>& entries) {
    std::cout << "\n===== All Book Entries =====\n";
    for (const auto& entry : entries) {
        std::cout << "Title: " << entry.getTitle() << "\n";
        std::cout << "Author: " << entry.getAuthor() << "\n";
        std::cout << "Genre: " << entry.getGenre() << "\n";
        std::cout << "Publication Year: " << entry.getYear() << "\n";
        std::cout << "---------------------------\n";
    }
}

void UserInterface::displayUpdateBookEntryMenu(string& title, string& author, string& genre, int& year) {
    std::cout << "\n===== Update Book Entry =====\n";

    std::cout << "Enter new title: ";
    std::getline(std::cin, title);

    std::cout << "Enter new author: ";
    std::getline(std::cin, author);

    std::cout << "Enter new genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter new publication year: ";
    std::cin >> year;

    // Clearing the input buffer to avoid issues with subsequent cin operations
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInterface::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
};