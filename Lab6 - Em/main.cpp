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
    int userSelect;
    string fileName;
    inFile.open("text.txt");
    printMenu(userSelect);
    generateReport(fileName);
}
