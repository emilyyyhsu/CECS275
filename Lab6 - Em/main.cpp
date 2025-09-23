/*
 * This program calculates your grades
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
*/



int main (void){
    fstream inFile;
    string fileName;
    string newPassword;
    int userSelect;

    // Prompt initial login
    userLogin(newPassword);

    do{
        // Prints menu and gets user's input
        userSelect = printMenu();

        // Beautiful asf switch case
        switch (userSelect){
        case 1:
            generateReport();
            break;
        case 2:
            fileName = uploadFile();
            inFile.open(fileName);
            break;
        case 3:
            if(checkFile(inFile)){
                generateGradeReport(inFile);
            }
            break;
        case 4: // Change password
            newPassword = setNewPassword();
            break;
        case 5:
            cout << "Logging out...\n---------------------------------------------------------" << endl;
            userLogin(newPassword);
            break;
        case 6: 
            continue;
        default: 
            cout << "Error occurred. Please try again." << endl;
            break;
        }
    }
    while(userSelect != 6);
    cout << "Bye bye!" << endl;
}
