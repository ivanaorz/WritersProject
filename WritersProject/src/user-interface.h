#pragma once

#include<string>
using std::string;

class UserInterface {
public:
    void displayMainMenu();
    void displayAccountMenu(string& username, string& password);
    void displayBookEntryMenu();
    void displayMessage(const std::string& message);

};
