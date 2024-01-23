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
            // TO DO: Handle Create Account 
            break;
        }
        case 2:
            // TO DO: Handle Log in
            break;
        case 3:
            // TO DO: Handle Book Entry Menu 
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

     
    }
}