#pragma once
#include "user-interface.h"
#include "authentication.h"

class App {
public:


    App();
    void run();

private:
    bool isRunning;
    bool isLoggedIn;
    UserInterface ui;
    Authentication authentication;


};
