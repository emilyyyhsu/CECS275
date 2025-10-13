#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<string> makeUsernameBank(void)
{
    ifstream inFile("login.txt");
    string username, password;
    vector<string> usernameBank;
    while(inFile >> username >> password)
    {
        usernameBank.push_back(username);
    }
    return usernameBank;
}

vector<string> makePasswordBank(void)
{
    ifstream inFile("login.txt");
    string username, password;
    vector<string> passwordBank;
    while(inFile >> username >> password)
    {
        passwordBank.push_back(password);
    }
    return passwordBank;
}

void updateInfo(vector<string> usernameBank, vector<string> passwordBank)
{
    ofstream outFile("login.txt");
    for(int i = 0; i < usernameBank.size(); i++){
        outFile<< usernameBank[i] << " " << passwordBank[i] << endl;
    }
}

void registration(void)
{
    ofstream outFile("login.txt", ios::app);
    vector<string> usernameBank, passwordBank;
    string nUsername, nPassword, username;

    usernameBank = makeUsernameBank();
    passwordBank = makePasswordBank();

    cout << "Enter a new username: " << endl;
    cin >> nUsername;
    
    for(string username : usernameBank)
    {
        while (nUsername == username)
        {
            cout << "Username already exists. Please choose another one." << endl;
            cin >> nUsername;
        }
    }

    cout << "Enter a new password: " << endl;
    cin >> nPassword;

    outFile << nUsername << " " << nPassword << endl;

    cout << "Successfully registered!" << endl;
}

void login(void)
{
    vector<string> usernameBank, passwordBank;
    string mUsername, mPassword, username, password;
    int index = 0, access = 0, attempt = 0;

    usernameBank = makeUsernameBank();
    passwordBank = makePasswordBank();

    do
    {
        if(attempt == 1){
            cout << "Username does not exist. Please try again." << endl;
        }

        cout << "Enter your username: " << endl;
        cin >> mUsername;

        for(int i = 0; i < usernameBank.size();i++)
        {
            if(mUsername == usernameBank[i]){
                index = i;
                access = 1;
            }
        }
        attempt = 1;
    } while(!access);
    while(access){
        cout << "Enter you password: " << endl;
        cin >> mPassword;
        if(mPassword == passwordBank[index])
        {
            break;
        }
        else
        {
            cout << "Password is incorrect. Please try again." << endl;
            attempt++;
            if(attempt == 3){
                cout << "Login failed. Returning to menu..." << endl;
                break;
            }
        }
    }
}


void setNewPassword(void)
{
    vector<string> usernameBank, passwordBank;
    string mUsername, mPassword, nPassword;
    int attempt = 0, index = 0, access = 0;

    usernameBank = makeUsernameBank();
    passwordBank = makePasswordBank();

    do
    {
        if(attempt == 1){
            cout << "Username does not exist. Please try again." << endl;
        }

        cout << "Enter your username: " << endl;
        cin >> mUsername;

        for(int i = 0; i < usernameBank.size();i++)
        {
            if(mUsername == usernameBank[i]){
                index = i;
                access = 1;
            }
        }
        attempt = 1;
    } while(!access);

    cout << "Enter your current password: " << endl;
    cin >> mPassword;
    while(mPassword != passwordBank[index])
    {
        cout << "Password is incorrect. Please try again." << endl;
        cin >> mPassword;
    }
    cout << "Enter your new password: " << endl;
    cin >> nPassword;
    passwordBank[index] = nPassword;

    updateInfo(usernameBank, passwordBank);
}



void user_login(void){
    int userSelect, access, user;
    do{
        cout << "Choose an option:\n1. Register\n2. Login\n3. Change or forgot password" << endl;
        cin >> userSelect;

        switch(userSelect){
        case 1: 
            registration();
            break;
        
        case 2: 
            login();
            break;

        case 3: 
            setNewPassword();
            break;

        default: 
            cout << "Error occurred. Please try again." << endl;
            break;
        }
    }while(userSelect != 2);
   
}