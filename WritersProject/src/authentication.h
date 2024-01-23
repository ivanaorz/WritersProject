#pragma once
#include <string>

class Authentication {
public:
    bool createAccount(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();


};
