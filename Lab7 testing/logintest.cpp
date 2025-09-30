#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<string> loginInfo;
vector<string> usernameBank;
vector<string> passwordBank;

void registration(vector<string> &usernameBank, vector<string> &passwordBank);
void login(vector<string> usernameBank, vector<string> passwordBank);
void setNewPassword(vector<string> usernameBank, vector<string> passwordBank);
void user_login(vector<string> usernameBank, vector<string> passwordBank);

int main(void){
    user_login(usernameBank, passwordBank);
    return 0;
}

void registration(vector<string> &usernameBank, vector<string> &passwordBank){
    string nUsername, nPassword;

    cout << "Enter a new username: " << endl;
    cin >> nUsername;
    for(int i=0;i<usernameBank.size();i++){
        while(nUsername == usernameBank[i]){
            cout << "Username already exists. Please choose another one." << endl;
            cin >> nUsername;
        }
    }
    cout << "Enter a new password: " << endl;
    cin >> nPassword;

    usernameBank.push_back(nUsername);
    passwordBank.push_back(nPassword);

    cout << "Successfully registered! Returning to login..." << endl;

    for(const string& s : usernameBank){
        cout << s << " ";
    } for (const string& s : passwordBank){
        cout << s << " ";
    }

}

void login(vector<string> usernameBank, vector<string> passwordBank){
    int i, index, access = 0, attempt = 0;
    string mUsername, mPassword;

    cout << "Enter your username: " << endl;
    cin >> mUsername;
    do{
        for(i=0;i<usernameBank.size();i++){
            if (mUsername == usernameBank[i]){
                index = i;
                access = 1;
                break;
            }
        }if(access == 0){
            cout << "Username does not exist. Please try again." << endl;
            cin >> mUsername;
        }
    }while(access==0);

    access = 0;
    cout << "Enter your password: " << endl;
    cin >> mPassword;
    do{
        for(i=0;i<passwordBank.size();i++){
            if(mPassword == passwordBank[i]){
                access = 1;
                break;
            }
        }
        if(access == 0){
            cout << "Password failed. Please try again." << endl;
            cin >> mPassword;
            attempt++;
        }if(attempt == 3){
                cout << "You failed to input the correct password." << endl;
                break;
        }
    }while(access==0);
}

void setNewPassword(vector<string> usernameBank, vector<string> passwordBank){
    int i, match=0, index;
    string username, newPassword;

    cout << "Enter your username: " << endl;
    cin >> username;
    do{
        for(i=0;i<usernameBank.size();i++){
            if(username == usernameBank[i]){
                match = 1;
                index = i;
                break;
            }
        } if (match == 0){
            cout << "Username does not exist. Please try again." << endl;
            cin >> username;
        }
    }while(match == 0);
    cout << "Enter your new password: " << endl;
    cin >> newPassword;
    cout << index << endl;
    passwordBank.at(index) = newPassword;

    for(const string& s : usernameBank){
        cout << s << " ";
    } for (const string& s : passwordBank){
        cout << s << " ";
    }

    cout << "Successfully changed password! Returning to login..." << endl;
}


void user_login(vector<string> usernameBank, vector<string>passwordBank){
    int userSelect, access, user = 0;
    /*
     * 1. registration
     * 2. login
     * 3. change/forgot password
    */

    do{
        cout << "Choose an option:\n1. Register\n2. Login\n3. Change or forgot password" << endl;
        cin >> userSelect;

        switch(userSelect){
        case 1: 
            registration(usernameBank, passwordBank);
            user = 1;
            break;
        
        case 2: 
            if(user == 0){
                registration(usernameBank, passwordBank);
            } login(usernameBank, passwordBank);
            user = 1;
            break;

        case 3: 
            if (user == 0){
                registration(usernameBank, passwordBank);
            } setNewPassword(usernameBank, passwordBank);
            user = 1;
            break;

        default: 
            cout << "Error occurred. Please try again." << endl;
            break;
        }
    }while(userSelect != 2);
   
}
 