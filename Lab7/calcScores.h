/*
 * Header files where calculations are done
 * @author: Natasha Kho
 * @author: Emily Hsu
 * Created on: 2025-09-11
 * Last Modified: 2025-09-15
 * Reference: 
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "randGen.h"

// Function prototypes
void printMenu(int userSelect);
void generateReport(string fileName);
void printResults(double projectGrade, double labGrade, 
                    double quizGrade, double examGrade, double finalGrade, 
                    double totalGrade, char letterGrade);

using namespace std;

// Grade weights
const double gradeWeights[5] = {0.10, 0.15, .15, 0.40, 0.20};

// Converts fractional value to percentage
const int TO_PERCENT = 100;
const double GradeA = 0.90,
             GradeB = 0.80,
             GradeC = 0.70,
             GradeD = 0.60;

/*
 * @author: Natasha Kho
 * @param: filestream file variable
 * @param: reference integer array of length 5
*/
void getTotalAssignments(fstream& file, int (&totalAssignmentsArray)[5]){
    // First line of file
    for(int i = 0; i < 5; i++ ){
        file >> totalAssignmentsArray[i];
    }
    
}

/*
 * Work in progress. struggling
 * currently, it just erases whatever is at the default 0 index.
*/
void dropLowestScore(fstream& file,  vector<vector<vector<double>>> (&allGrades), int typeOfAssignment){
    //int lowestScore = 0x7FFFFFFF; // this is the maximum int in hex

    // this iterates through all the students (41 total)
    for(int i = 0; i < allGrades.size(); i++ ){

        // this iterates through a student's assignment categories (5 total)
        for(int j = typeOfAssignment; j < allGrades[i].size(); j++){
            // cout << "function called" << endl;
            int indexToDrop = 0;     

            // cout << "STARTING NEW ITERATION: " << j << endl;

            // this iterates through a student's assignment's grades 
            // (ie. lab grades, then quiz grades, then exam grades, etc.)
            for(int k = 0; k < allGrades[i][j].size(); k++){
                // cout << "Where is K going: " << k << endl;
                // cout << allGrades[i][j].size() << " is the size of this shit." << endl;
                // if all of the current values of indexesToDrop are lower than the current value of allGrades, 
                // then it's added to get dropped
                if(allGrades[i][typeOfAssignment][indexToDrop] > allGrades[i][typeOfAssignment][k]){
                    // cout << "SETTING NEW K: " << k << endl;
                    indexToDrop = k;
                }
                
            }    
            // cout << "ERASING AT INDEX: " << indexToDrop << " WITH VALUE: " << allGrades[i][typeOfAssignment][indexToDrop] << endl;    
            // cout << "type of assignment: " << typeOfAssignment << endl;
            // cout << "FUCK " << allGrades[i][typeOfAssignment][indexToDrop] << endl;

            allGrades[i][typeOfAssignment].erase(allGrades[i][typeOfAssignment].begin() + indexToDrop);   
            break;
        }
    }
    
}

/*
 * @author: Natasha Kho
 * @param: filestream file variable
 * @param: amount of assignments to iterate through
 * @return total score of one category of assignment
*/
void getPoints(fstream& file, int (&totalAssignmentAmount)[5], vector<vector<vector<double>>> &allGrades){
    double temp;
    for(int i = 0; i < allGrades.size(); i++){
        for(int j = 0; j < allGrades[i].size(); j++){
            for(int k = 0; k < allGrades[i][j].size(); k++){
                file >> allGrades[i][j][k];
            }
        }
    }
    // for(int i = 0; i < totalAssignmentAmount; i++){
    //     file >> totalScoreArray[i];
    // }
}

// THIS is ok
void populateGradeVector(int (&totalAssignmentAmount)[5], vector<vector<vector<double>>> &allGrades, int amountOfStudents){
    for(int i = 0; i < amountOfStudents + 1; i++){ // iterate 40 times because 40 students
        vector<vector<double>> studentScore; // Students' scores
        for(int j = 0; j < 5; j++){ // iterate 5 times because 5 categories per student
            vector<double> individualGrades;
            for(int k = 0; k < totalAssignmentAmount[j]; k++){ // iterates through amount of grades for each category
                individualGrades.push_back(0);
                // cout << individualGrades[k] << ' ';
            }
            studentScore.push_back(individualGrades);
            // cout << endl;
        }
         allGrades.push_back(studentScore); // pushing data for one student
                                            // allGrades[i] = push back needs to contain vector<vector<double>
    }
}

/*
 * @author: Natasha Kho
 * @param: total grade after calculations
 * @return letter grade based on score
*/
std::string getLetterGrade(vector<double> &calculatedPercentages){
    double totalGrade;
    for(int i = 0; i < calculatedPercentages.size(); i++){
        totalGrade += calculatedPercentages[i];
        cout << calculatedPercentages[i] << endl;
    }
    // cout << "Total Grade: " << totalGrade <<endl;
    calculatedPercentages.push_back(totalGrade);

    if (totalGrade >= GradeA) {
        return "A";
    } else if (totalGrade >= GradeB){
        return "B";
    } else if (totalGrade >= GradeC){
        return "C";
    } else if (totalGrade >= GradeD){
        return "D";
    } else {
        return "F";
    }
}

/*
 * @author: Natasha Kho
 * @param: actual points earned on total assignmenets
 * @param: total amount of points possible on assignment type
 * @return percentage of specific category
*/
void calculatePercentage(double grade, double total, double gradeWeight, vector<double> &calculatedPercentages){
    calculatedPercentages.push_back((grade/total) * gradeWeight);
}

void getIndividualStudentPointsTotal(vector<vector<vector<double>>> &allGrades, int studentNumber, int (&totalAssignments)[5], vector<double> &totalEarnedPoints){
    vector<double> oneStudentScore;
    for(int i = studentNumber; i < allGrades.size(); i++){
        for(int j = 0; j < allGrades[studentNumber].size(); j++){
            for(int k = 0; k < allGrades[i][j].size(); k++){
                oneStudentScore.push_back(allGrades[studentNumber][j][k]);
            }
        }
        break;
    }

    // this totals the points earned in each category by the student 
    int cursor = 0;
    for(int assignmentInCategory: totalAssignments){
        double temp = 0;;
        //cout << "\nAssignment amount in Category: " << assignmentInCategory << endl;
        for(int i = 0; i < assignmentInCategory; i++){
            temp += oneStudentScore[cursor];
            // cout << "TEMP " << temp << " ";
            //cout << "score " << oneStudentScore[cursor] << " ";
            cursor++;
        }
        totalEarnedPoints.push_back(temp);
    }
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

void generateReportOneStudent(fstream &inputFile, vector<double> (&oneStudentScore), vector<vector<vector<double>>> &allGrades, int (&totalAssignmentsDropped)[5], int (&totalAssignments)[5], int isGradesDropped, int studentNumber, vector<double> &calculatedPercentages){
    // First line of file
    getTotalAssignments(inputFile,totalAssignments);
    // for(int val: totalAssignments){
    //     cout << "Total Assignments: " << val  << endl;
    // }

    // Have a function to get amount of quiz/labs dropped
    getTotalAssignments(inputFile,totalAssignmentsDropped);
    // for(int val: totalAssignmentsDropped){
    //     cout << "Total Assignments Dropped: " << val  << endl;
    // }

    // cout << "===========================================\nPOPULATING POINTS POSSIBLE VECTOR" << endl;
    populateGradeVector(totalAssignments, allGrades, 40);
    // testPrintVector(allGrades); // should be a buncha 0s

    // cout << "===========================================\nINPUTTING POINTS" << endl;
    getPoints(inputFile, totalAssignments, allGrades);
    // testPrintVector(allGrades); // PLEASE PRINT NUMBERS PLEAAAAAAASE

    // used for calculations
    vector<double> totalEarnedPoints;
    vector<double> totalPointsPossible;
    if(isGradesDropped){
        // Do the stuff to drop the lowest grade as per requested wahoo!
        for(int i = 0; i < sizeof(totalAssignmentsDropped)/sizeof(totalAssignmentsDropped[0]); i++){
        int amtOfAssignmentsToDrop = totalAssignmentsDropped[i];
            while(amtOfAssignmentsToDrop){
                //cout << "AT I: " << i << " ASSIGNMENT TO BE DROPPED DETECTED ::: " << totalAssignmentsDropped[i] << endl;
                dropLowestScore(inputFile, allGrades,i );
                amtOfAssignmentsToDrop--;
            }
        }
    }
    
    getIndividualStudentPointsTotal(allGrades, studentNumber, totalAssignments, totalEarnedPoints); // student score is totalEarnedPoints
    getIndividualStudentPointsTotal(allGrades, 0, totalAssignments, totalPointsPossible);
    

    // cout << "\nTOTALLED POINTS: ";
    // for(double x: totalEarnedPoints){
    //     cout << x << " ";
    // }
    // cout << endl;
    
    // this calculates the percentages for one student
    //  calculatePercentage(double grade, double total, double gradeWeight, vector<double> &calculatedPercentages)
    for(int i = 0; i < totalEarnedPoints.size(); i++){
        calculatePercentage(totalEarnedPoints[i], totalPointsPossible[i], gradeWeights[i], calculatedPercentages);
        // cout << "Total Earned Points at index: " << i << " produces: " << totalEarnedPoints[i] << endl;
        // cout << "Total Points Possible at index: " << i << " produces: " << totalPointsPossible[i] << endl;
    }
    cout << "\nPERCENTAGES: ";
    for(double x: calculatedPercentages){
        cout << x << " ";
    }
    cout << endl;
}

/*
 * @author: Emily Hsu
 * @author Natasha Kho (Formatting)
 * couts the report
 * @param: weighted project grade as decimal
*/
void printResults(vector<double> calculatedPercentages){
    string letterGrade = getLetterGrade(calculatedPercentages);

    cout << "=========================================================\n" 
    << "Project: "      << setw(23) << fixed << setprecision(2) << calculatedPercentages[0] * TO_PERCENT    << "%\n" 
    << "Lab: "          << setw(27)                             << calculatedPercentages[1] * TO_PERCENT        << "%\n"
    << "Quiz: "         << setw(26)                             << calculatedPercentages[2] * TO_PERCENT       << "%\n"
    << "Exams: "        << setw(25)                             << calculatedPercentages[3] * TO_PERCENT       << "%\n"
    << "Final Exam: "   << setw(20)                             << calculatedPercentages[4] * TO_PERCENT      << "%\n"
    << "Total: "        << setw(25)                             << calculatedPercentages[5] * TO_PERCENT      << "%\n"
    << "Final Letter Grade: "                                   << letterGrade                  << "\n"
    << "=========================================================\n" << endl;
}


/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
std::string printMenu(void){
    std::string outputString;
    outputString =  "=========================================================\nSelect an option:\n1. Generate fake data\n2. View grade report.\n3. Which score file to use\n4. Generate grade report\n5. Change password\n6. Log out\n7. Exit program\n=========================================================";
    return outputString;
}

/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
string uploadFile(){
    string fileName;
    cout << "---------------------------------------------------------\n"
        << "Choose a score file: " << endl;
    cin >> fileName;
    cout << "Successfully uploaded score file " << fileName 
        << "!\n---------------------------------------------------------"<< endl;
    return fileName;
}


/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
string checkFile(){
    string fileName;
    cout << "---------------------------------------------------------\n" 
        << "Choose a file for your score report: " 
        << endl;
    cin >> fileName;
    cout << "---------------------------------------------------------" << endl; 
    return fileName;
}
