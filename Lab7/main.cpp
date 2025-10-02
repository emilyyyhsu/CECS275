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
#include "login.h"

/* 
 * Our new code of Lab 6 breaks down Lab 5 into separate functions. We’ve created four main functions to generate a score report. 
 * generateAssignmentAmount randomly generates the number of assignments for each category. generateMaxScores uses the previously 
 * generated number of assignments to generate the maximum possible score for each category. generateScores randomly generates 
 * scores for each assignment. generateReport uses all of the previous functions to create a text file with the generated score file. 
 * On a separate header file, we have added other functions for the user’s experience, such as a log-in function with an option 
 * to change the password and a function to upload a score file that can be used to generate a grade report.
*/

fstream inFile, userFile, inputFile;
string fileName, newPassword, viewReport, dropped;
vector<string> usernameBank, passwordBank;
vector<double> calculatedPercentages, averageScores;
vector<vector<vector<double>>> allGrades;
int studentNumber, userSelect, upload = 0, report = 0, isGradesDropped, totalAssignmentsDropped[5], totalAssignments[5];

int main(void){
    // Prompt initial login
    user_login(usernameBank, passwordBank);
    
    do{
        // Prints menu and gets user's input
        cout << printMenu() << endl;
        cin >> userSelect;

        switch (userSelect){
        // Generate fake data
        case 1: 
            generateReport();
            break;
        // Which score file to use
        case 2:
            fileName = uploadFile();
            userFile.open(fileName);
            upload = 1;
            break;
        // Generate grade report
        case 3:
            if (!upload){
                fileName = checkFile();
                userFile.open(fileName);
            } 
            report = 1;
            cout << "Would you like to view your grade report? (Y/N)" << endl;
            cin >> viewReport;
            if (viewReport == "Y"){
                cout << "With grades dropped? (Y/N)" << endl;
                cin >> dropped;
                cout << "What is your student number?" << endl;
                cin >> studentNumber;
                if(dropped == "Y"){
                    generateReportOneStudent(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 1, studentNumber, calculatedPercentages, averageScores);
                }else if(dropped == "N"){
                    generateReportOneStudent(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 0, studentNumber, calculatedPercentages, averageScores);
                }
            }
            printResults(calculatedPercentages, averageScores);
            upload = 0;
            userFile.close();
            break;
        // View grade report with and without dropped items
        case 4:
            if (report == 1){
                cout << "View report with grades dropped? (Y/N)" << endl;
                cin >> dropped;
                cout << "What is your student number?" << endl;
                cin >> studentNumber;
                if(dropped == "Y"){
                    generateReportOneStudent(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 1, studentNumber, calculatedPercentages, averageScores);
                }else if(dropped == "N"){
                    generateReportOneStudent(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 0, studentNumber, calculatedPercentages, averageScores);
                }
                printResults(calculatedPercentages, averageScores);
                upload = 0;
                userFile.close();
            } else {
                cout << "Please generate a grade report first using option 3." << endl;
            }
            break;
        // Show class average percentages for each category and average for total percentage
        case 5: 
            if (!upload){
                fileName = checkFile();
                userFile.open(fileName);
            } 
            cout << "View average percentages with grades dropped? (Y/N)" << endl;
            cin >> dropped;
            if(dropped == "Y"){
                generateReportClass(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 1, calculatedPercentages, averageScores);
            }else if(dropped == "N"){
                generateReportClass(userFile, allGrades, totalAssignmentsDropped, totalAssignments, 0, calculatedPercentages, averageScores);
            }
            printClassResults(calculatedPercentages);
            upload = 0;
            userFile.close();
            break;
        // Log out 
        case 6:
            cout << "Logging out..." << endl;
            user_login(usernameBank, passwordBank);
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
    return 0;
}
