/*
 * This program gives the user a choice between calculating their grades,
 * selecting which file to use, resetting their password, or generating fake scores
 * @author: Natasha Kho
 * @author: Emily Hsu
 * Created on: 2025-09-11
 * Last Modified: 2025-09-15
 * Reference: 
*/
#include "calcScores.h"

/* 
 * Our new code of Lab 6 breaks down Lab 5 into separate functions. We’ve created four main functions to generate a score report. 
 * generateAssignmentAmount randomly generates the number of assignments for each category. generateMaxScores uses the previously 
 * generated number of assignments to generate the maximum possible score for each category. generateScores randomly generates 
 * scores for each assignment. generateReport uses all of the previous functions to create a text file with the generated score file. 
 * On a separate header file, we have added other functions for the user’s experience, such as a log-in function with an option 
 * to change the password and a function to upload a score file that can be used to generate a grade report.

int main (void){
    fstream inFile, userFile;
    string fileName, newPassword, viewReport;
    
    int userSelect, upload = 0, report = 0;

    // Prompt initial login
    if(userLogin(newPassword)){
        do{
            // Prints menu and gets user's input
            cout << printMenu() << endl;
            cin >> userSelect;

            switch (userSelect){
            // Generate fake data
            case 1: 
                generateReport();
                break;
            // Print grade report
            case 2:
                if (report == 1){
                    printResults(generateGradeReport(userFile));
                } else {
                    cout << "Please generate a grade report first using option 4." << endl;
                }
                break;
            // Choose which score file to use
            case 3:
                fileName = uploadFile();
                userFile.open(fileName);
                upload = 1;
                break;
            // Generate grade report
            case 4:
                if (!upload){
                    fileName = checkFile();
                    userFile.open(fileName);
                } 
                report = 1;
                cout << "Would you like to view your grade report? (Y/N)" << endl;
                cin >> viewReport;
                if (viewReport == "Y"){
                    printResults(generateGradeReport(userFile));
                }
                upload = 0;
                userFile.close();
                break;
            // Change password
            case 5: 
                newPassword = setNewPassword();
                break;
            // Log out 
            case 6:
                cout << "Logging out...\n---------------------------------------------------------" << endl;
                userLogin(newPassword);
                break;
            // Exit program
            case 7: 
                break;
            default: 
                cout << "Error occurred. Please try again." << endl;
                break;
            }
        }
        while(userSelect != 7);
        cout << "Bye bye!" << endl;
    }
}
*/