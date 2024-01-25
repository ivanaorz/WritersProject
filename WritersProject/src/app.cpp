
#include<iostream>
#include <algorithm> // for std::equal, for std::find_if_not
#include <cctype>    // for std::tolower
#include <functional> // for std::function
#include <locale>     // for std::isspace

#include "book-entry.h"
#include "app.h"

using namespace std;
using std::string;

App::App() : isRunning (true) {

}

void App::run() {
   // bool isRunning = true;
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
            std::string createdUsername = authentication.createAccount(username, password);
            if (!createdUsername.empty()) {
                std::cout << "Account created successfully!\n";
                // Creating an entry vector for the new user
                userBookEntries[createdUsername] = std::vector<BookEntry>();
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
            std::string loggedInUsername = authentication.login(username, password);
            if (!loggedInUsername.empty()) {
                isLoggedIn = true;
                std::cout << "Login successful!\n";


                // Redirected to book entry menu
                while (isLoggedIn) {
                    ui.displayBookEntryMenu();

                    int bookEntryChoice;
                    std::cout << "Enter your choice: ";
                    std::cin >> bookEntryChoice;

                    switch (bookEntryChoice) {
                    case 1: // Create book entry
                        createBookEntry(username);
                        break;
                    case 2: // Read all book entries
                        readAllBookEntries(username);
                        break;
                    case 3: // Update book entry
                        updateBookEntry(username);
                        break;
                    case 4: // Delete book entry
                        deleteBookEntry(username);
                        break;
                    case 5: // Log out
                        authentication.logout();
                        isLoggedIn = false;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                }
            }
            else {
                std::cout << "Invalid username or password. Please try again or create an account.\n";
            }
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void App::createBookEntry(const std::string& username) {
    std::string title, author, genre;
    int year;
    ui.displayCreateBookEntryMenu(title, author, genre, year);
    BookEntry newEntry(title, author, genre, year);

    
     // Adding the book entry to the user's entries
    userBookEntries[username].push_back(newEntry);

    FileService::writeBooksToFile("book_entries.txt", userBookEntries[username]);
    std::cout << "Book entry created successfully!\n";

    displayExitText();
}

void App::readAllBookEntries(const std::string& username) {
    // Reading the entries specific to the logged-in user
    auto& userEntries = userBookEntries[username];

    // Checking if the user's entries are empty
    if (userEntries.empty()) {
        auto loadedEntries = FileService::readBooksFromFile("book_entries.txt");
        userEntries.swap(loadedEntries); 
    }

    if (userEntries.empty()) {
        std::cout << "No book entries available.\n";
    }
    else {
        ui.displayAllBookEntries(userEntries);
    }

    displayExitText();
}

// Trimming leading and trailing whitespaces from a string
void trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
        }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
        }).base(), str.end());
}


// Case-insensitive string comparison function 
bool caseInsensitiveStringCompare(const std::string& str1, const std::string& str2) {
    return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
        [](char c1, char c2) {
            return std::tolower(c1) == std::tolower(c2);
        });
}


void App::updateBookEntry(const std::string& username) {
    if (userBookEntries[username].empty()) {
        std::cout << "You don't have book entries yet.\n";
        return;
    }

    std::string title, author, genre;
    int year;

    
    ui.displayMessage("Choose the title of the book you want to update:");
    std::cin.ignore(); // Ignoring any leftover newline characters
    std::getline(std::cin, title);

    // Finding the book entry with the specified title (case-insensitive comparison)
    auto& userEntries = userBookEntries[username];
    auto entryIterator = std::find_if(userEntries.begin(), userEntries.end(),
        [title](const BookEntry& entry) {
            return caseInsensitiveStringCompare(entry.getTitle(), title);
        });

    if (entryIterator != userEntries.end()) {
        // After the book entry is found, update its information
        ui.displayUpdateBookEntryMenu(title, author, genre, year);
        // Updating the book entry with the new information
        entryIterator->setTitle(title);
        entryIterator->setAuthor(author);
        entryIterator->setGenre(genre);
        entryIterator->setYear(year);

        // Saving the updated entries to file
        FileService::writeBooksToFile("book_entries.txt", userEntries);
        std::cout << "Book entry updated successfully!\n";
    }
    else {
        std::cout << "Book entry with title '" << title << "' not found.\n";
    }

    displayExitText();
}



void App::deleteBookEntry(const std::string& username) {
    if (userBookEntries[username].empty()) {
        std::cout << "You don't have book entries yet.\n";
        return;
    }

    std::string titleToDelete;
    ui.displayMessage("Enter the title of the book entry you want to delete: ");
    std::cin.ignore(); // Ignoring any leftover newline characters
    std::getline(std::cin, titleToDelete);

    // Finding the book entry with the specified title
    auto& userEntries = userBookEntries[username];

    auto entryIterator = std::find_if(userEntries.begin(), userEntries.end(),
        [titleToDelete](const BookEntry& entry) {
            return caseInsensitiveStringCompare(entry.getTitle(), titleToDelete);
        });

    if (entryIterator != userEntries.end()) {
        // Book entry is found, so, we need to erase it from the vector
        userEntries.erase(entryIterator);
        FileService::writeBooksToFile("book_entries.txt", userEntries);
        std::cout << "Book entry deleted successfully!\n";
    }
    else {
        std::cout << "Book entry with title '" << titleToDelete << "' not found.\n";
    }
    

    displayExitText();
}

void App::displayExitText() {
    std::string exitChoice;
    std::cout << "Type 'exit' to leave this menu: ";
    std::cin >> exitChoice;

    if (exitChoice == "exit") {
        // Redirecting to the book entry menu
        isLoggedIn = true;
    }
    else {
        std::cout << "Invalid choice. Returning to the book entry menu anyway.\n";
        // Redirecting to the book entry menu
        isLoggedIn = true;
    }

  
}






          




        