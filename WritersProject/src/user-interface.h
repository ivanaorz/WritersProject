#pragma once

#include<string>
#include <vector>
#include "book-entry.h"
using std::string;

class UserInterface {
public:
    void displayMainMenu();
    void displayAccountMenu(string& username, string& password);
    void displayLoginMenu(string& username, string& password);
    void displayBookEntryMenu();
    void displayCreateBookEntryMenu(string& title, string& author, string& genre, int& year);
    void displayAllBookEntries(const std::vector<BookEntry>& entries);
    void displayUpdateBookEntryMenu(string& title, string& author, string& genre, int& year);
    void displayMessage(const std::string& message);

};
