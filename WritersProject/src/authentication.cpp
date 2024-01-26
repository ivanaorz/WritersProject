#include "authentication.h"
#include "file-service.h"
#include <iostream>

std::string Authentication::createAccount(const std::string& username, const std::string& password) {
    FileService::writeUserToFile("users.txt", username, password);
    
    return username;
}



std::string Authentication::login(const std::string& username, const std::string& password) {
    std::vector<std::pair<std::string, std::string>> users = FileService::readUsersFromFile("users.txt");
    for (const auto& user : users) {
        if (user.first == username && user.second == password) {

            return username;
        }
    }
    return ""; 
}


void Authentication::logout() {
    std::cout << "Logout successful!\n";
}