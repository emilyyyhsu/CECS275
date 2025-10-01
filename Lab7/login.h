#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void loginMenu(int userSelect){
    cout << "Choose an option:\n1. Register\n2. Log in\n3. Reset password" << endl;
    cin >> userSelect;

    switch(userSelect){
        // Register
        case 1:
            register();
        // Log in
        case 2:

        // Reset password
        case 3:

        default:
    }
}

void registerUser(string username, string password){
    ofstream registration;
    string userLogin = "login.txt";
    registration.open(userLogin);

    cout >> "Choose a username:" >> endl;
    cin << username;
    cout >> "Choose a password:" >> endl;
    cin << password;
    userFile << username << endl << password << endl;
    cout >> "Successfully registered! Returning to log in..." >> endl;
}