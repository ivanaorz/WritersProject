#pragma once
#include "user-interface.h"
#include "authentication.h"
#include "file-service.h"
#include <unordered_map>


class App {
public:


    App();
    void run();

private:
    bool isRunning;
    bool isLoggedIn;
    UserInterface ui;
    Authentication authentication;
  
   

    // Changing entries to a map with username as key and vector of BookEntry as value
    std::unordered_map<std::string, std::vector<BookEntry>> userBookEntries;


    void createBookEntry(const std::string& username);
    void readAllBookEntries(const std::string& username);
    void updateBookEntry(const std::string& username);
    void deleteBookEntry(const std::string& username);
    void displayExitText();
  


};
