#include "authentication.h"
#include <iostream>

bool Authentication::createAccount(const std::string& username, const std::string& password) {
    // TO DO: Implement account creation logic (add user to a list or database)
    std::cout << "Account created successfully!\n";
    return true;
}

bool Authentication::login(const std::string& username, const std::string& password) {
    // TO DO: Implement login logic (check credentials against stored data)
    std::cout << "Login successful!\n";
    return true;
}

void Authentication::logout() {
    // TO DO: Implement logout logic (clear user session data)
    std::cout << "Logout successful!\n";
}