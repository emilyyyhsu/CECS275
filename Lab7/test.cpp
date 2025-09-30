#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

#include "calcScores.h"

// Function prototype for testPrintVector
void testPrintVector(vector<vector<vector<double>>> &allGrades);

int main(void){
    fstream input;
    input.open("scores.txt");
    //input.open("new_scores.txt");

    int totalAssignments[5];
    int totalAssignmentsDropped[5];

    //  rows go in such fashion:
    //  * all total lab/quiz/exam/project points
    //  * first students' grades
    //  * second students' grades
    //  * and so on and so on
    vector<vector<vector<double>>> allGrades;
    
    // First line of file
    getTotalAssignments(input,totalAssignments);
    for(int val: totalAssignments){
        cout << "Total Assignments: " << val  << endl;
    }

    // Have a function to get amount of quiz/labs dropped
    getTotalAssignments(input,totalAssignmentsDropped);
    for(int val: totalAssignmentsDropped){
        cout << "Total Assignments Dropped: " << val  << endl;
    }

    // PROBLEM: This is looping through the entire file, we only want this to grab the first line
    cout << "===========================================\nPOPULATING POINTS POSSIBLE VECTOR" << endl;
    populateGradeVector(totalAssignments, allGrades, 1);
    testPrintVector(allGrades); // should be a buncha 0s

    cout << "===========================================\nINPUTTING POINTS" << endl;
    getPoints(input, totalAssignments, allGrades);
    testPrintVector(allGrades); // PLEASE PRINT NUMBERS PLEAAAAAAASE

    cout << "===========================================\nDROPPED LOWEST POINTS" << endl;
    dropLowestScore(input, totalAssignments, totalAssignmentsDropped,allGrades );
    testPrintVector(allGrades);
    return 1;
}

void testPrintVector(vector<vector<vector<double>>> &allGrades){
    for(int i = 0; i < allGrades.size(); i++){
        for(int j = 0; j < allGrades[i].size(); j++){
            for(int k = 0; k < allGrades[i][j].size(); k++){
                cout << allGrades[i][j][k] << " ";
            }
        }
        cout << endl;
    }
}