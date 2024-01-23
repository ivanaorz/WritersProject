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


void UserInterface::displayBookEntryMenu() {
    std::cout << "1. Create book entry\n";
    std::cout << "2. Read all book entries\n";
    std::cout << "3. Update book entry\n";
    std::cout << "4. Delete book entry\n";
    std::cout << "5. Log out\n";
}

void UserInterface::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
};