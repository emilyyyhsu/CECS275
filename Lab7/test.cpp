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
    //input.open("scores.txt");
    input.open("new_scores.txt");

    int totalAssignments[5];
    int totalAssignmentsDropped[5];

    //  rows go in such fashion:
    //  * all total lab points
    //  * all total quiz points
    //  * all total exam points
    //  * and so on and so on
    vector<vector<vector<double>>> possiblePoints;

    //  rows go:
    //  * all earned lab points
    //  * all earned quiz points
    //  * all earned exam points
    //  * and so on and so on
    vector<vector<vector<double>>> earnedPoints;
    
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

    cout << "===========================================\nPOPULATING POINTS POSSIBLE VECTOR" << endl;
    populateGradeVector(totalAssignments, possiblePoints);
    testPrintVector(possiblePoints); // should be a buncha 0s

    cout << "===========================================\nINPUTTING POINTS" << endl;
    getPoints(input, totalAssignments, possiblePoints);
    testPrintVector(possiblePoints); // PLEASE PRINT NUMBERS PLEAAAAAAASE
    // ive been at this for three hours im gonna fucking nut it works oh my god jesus is real

    cout << "===========================================\nPOPULATING POINTS EARNED VECTOR" << endl;
    populateGradeVector(totalAssignments, earnedPoints);
    testPrintVector(earnedPoints); // should be a buncha 0s

    cout << "===========================================\nINPUTTING GRADES" << endl;
    getPoints(input,totalAssignments, earnedPoints);
    testPrintVector(earnedPoints); // PLEASE PRINT NUMBERS PLEAAAAAAASE
    
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