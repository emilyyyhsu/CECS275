#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<string> makeUsernameBank(fstream& login_info)
{
    string username, password;
    vector<string> usernameBank;
    while(login_info >> username >> password)
    {
        usernameBank.push_back(username);
    }
    return usernameBank;
}

vector<string> makePasswordBank(fstream& login_info)
{
    string username, password;
    vector<string> passwordBank;
    while(login_info >> username >> password)
    {
        passwordBank.push_back(password);
    }
    return passwordBank;
}

void updateInfo(fstream& login_info, vector<string> usernameBank, vector<string> passwordBank)
{
    for(int i = 0; i < usernameBank.size()-1; i++){
        login_info << usernameBank[i] << passwordBank[i];
    }
}

void registration(fstream& login_info){
    vector<string> usernameBank, passwordBank;
    string nUsername, nPassword, username;

    usernameBank = makeUsernameBank(login_info);
    passwordBank = makePasswordBank(login_info);

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

    login_info << nUsername << nPassword;

    cout << "Successfully registered!" << endl;
}

void login(fstream& login_info){
    vector<string> usernameBank, passwordBank;
    string mUsername, mPassword, username, password;
    int index = 0, access = 0, attempt = 0;

    usernameBank = makeUsernameBank(login_info);
    passwordBank = makePasswordBank(login_info);
    
    do
    {
        if(attempt == 1){
            cout << "Username does not exist. Please try again." << endl;
        }

        cout << "Enter your username: " << endl;
        cin >> mUsername;

        for(int i = 0; i < usernameBank.size()-1;i++)
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


void setNewPassword(fstream& login_info)
{
    vector<string> usernameBank, passwordBank;
    string mUsername, mPassword, nPassword;
    int attempt = 0, index = 0, access = 0;

    usernameBank = makeUsernameBank(login_info);
    passwordBank = makePasswordBank(login_info);

    do
    {
        if(attempt == 1){
            cout << "Username does not exist. Please try again." << endl;
        }

        cout << "Enter your username: " << endl;
        cin >> mUsername;

        for(int i = 0; i < usernameBank.size()-1;i++)
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
    
    updateInfo(login_info, usernameBank, passwordBank);
}



int user_login(int accountMade, vector<string> &usernameBank, vector<string> &passwordBank){
    fstream login_info;
    login_info.open("login.txt");

    int userSelect, access, user;
    do{
        cout << "Choose an option:\n1. Register\n2. Login\n3. Change or forgot password" << endl;
        cin >> userSelect;

        switch(userSelect){
        case 1: 
            registration(login_info);
            // registration(usernameBank, passwordBank);
            // if(accountMade != 1){
            //     userSelect = 2;
            //     break;
            // }
            // accountMade = 1;
            break;
        
        case 2: 
            login(login_info);
            // if(accountMade != 1){
            //     registration(usernameBank, passwordBank);
            //     userSelect= 2;
            //     break;
            // } login(usernameBank, passwordBank);
            // accountMade = 1;
            break;

        case 3: 
            setNewPassword(login_info);
            // if (accountMade != 1){
            //     registration(usernameBank, passwordBank);
            //     userSelect = 2;
            //     break;
            // } setNewPassword(usernameBank, passwordBank);
            // accountMade = 1;
            break;

        default: 
            cout << "Error occurred. Please try again." << endl;
            break;
        }
    }while(userSelect != 2);
   return 1;
}