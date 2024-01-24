#include "app.h"
#include<iostream>

using std::string;

App::App() {

}

void App::run() {
    bool isRunning = true;
    bool isLoggedIn = false;  

    while (isRunning) {
        ui.displayMainMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string username, password;
            ui.displayAccountMenu(username, password);
            // Handling Create Account 
            if (authentication.createAccount(username, password)) {
                std::cout << "Account created successfully!\n";
            }
            else {
                std::cout << "Failed to create account. Please try again.\n";
            }
            break;
        }
        case 2: {
            std::string username, password;
            ui.displayLoginMenu(username, password);
            // Handling Log in
            if (authentication.login(username, password)) {
                isLoggedIn = true;
                std::cout << "Login successful!\n";
                ui.displayBookEntryMenu(); // after successful log in redirecting to book entry menu 
            }
            else {
                std::cout << "Invalid username or password. Please try again.\n";
            }
            break;
        }
        // case 3:
            // Handling Book Entry Menu 
            // break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

     
    }
}