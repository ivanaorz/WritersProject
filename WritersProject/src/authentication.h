#pragma once
#include <string>

class Authentication {
public:
    std::string createAccount(const std::string& username, const std::string& password);
    std::string login(const std::string& username, const std::string& password);
    void logout();


};
