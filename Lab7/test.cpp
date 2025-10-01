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
    vector<double> calculatedPercentages;
    vector<double> averageScore;

    //  rows go in such fashion:
    //  * all total lab/quiz/exam/project points
    //  * first students' grades
    //  * second students' grades
    //  * and so on and so on
    vector<vector<vector<double>>> allGrades;
    vector<double> individualStudentScores;
    generateReportClass(input, allGrades, totalAssignmentsDropped, totalAssignments, 0, 1, calculatedPercentages,averageScore);
    //printResults(calculatedPercentages,averageScore);
    return 1;
}

// void testPrintVector(vector<vector<vector<double>>> &allGrades){
//     for(int i = 0; i < allGrades.size(); i++){
//         for(int j = 0; j < allGrades[i].size(); j++){
//             for(int k = 0; k < allGrades[i][j].size(); k++){
//                 cout << allGrades[i][j][k] << " ";
//             }
//         }
//         cout << endl;
//     }
// }