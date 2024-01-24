#include "authentication.h"
#include "file-service.h"
#include <iostream>

bool Authentication::createAccount(const std::string& username, const std::string& password) {
    FileService::writeUserToFile("users.txt", username, password);
    std::cout << "Account created successfully!\n";
    return true;
}

bool Authentication::login(const std::string& username, const std::string& password) {
    std::vector<std::pair<std::string, std::string>> users = FileService::readUsersFromFile("users.txt");
    for (const auto& user : users) {
        if (user.first == username && user.second == password) {
            std::cout << "Login successful!\n";
            return true;
        }
    }
    std::cout << "Invalid username or password. Please try again.\n";
    return false;
}

void Authentication::logout() {
    std::cout << "Logout successful!\n";
}