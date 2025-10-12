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
void generateReportClass(fstream &inputFile, vector<vector<vector<double>>> &allGrades, int (&totalAssignmentsDropped)[5], int (&totalAssignments)[5], 
        int isGradesDropped, vector<double> &calculatedPercentages, vector<double> &averageScores);
void vector_dumptruck(vector<double> &calculatedPercentages, vector<double> &averageScores,
                      vector<vector<double>> &calculatedClassPercentages, vector<vector<vector<double>>> &allGrades);

using namespace std;

// Grade weights
const double gradeWeights[5] = {0.15, 0.15, .40, 0.10, 0.20};

// Converts fractional value to percentage
const int TO_PERCENT = 100;
const double GradeA = 0.90,
             GradeB = 0.80,
             GradeC = 0.70,
             GradeD = 0.60;

/*
 * @author Natasha Kho

void dropLowestScore(fstream& file,vector<vector<vector<double>>> (&allGrades), int typeOfAssignment){
    for(int i = 0; i < allGrades.size(); i++ ){

        for(int j = typeOfAssignment; j < allGrades[i].size(); j++){
            int indexToDrop = 0;     

            for(int k = 0; k < allGrades[i][j].size(); k++){
                if(allGrades[i][typeOfAssignment][indexToDrop] > allGrades[i][typeOfAssignment][k]){
                    indexToDrop = k;
                }
                
            }    

            allGrades[i][typeOfAssignment].erase(allGrades[i][typeOfAssignment].begin() + indexToDrop);   
            break;
        }
    }
    
}
*/

void dropLowestScore(fstream& file, vector<vector<vector<double>>> (&allGrades), int typeOfAssignment)
{
    int minIndex, minValue;

    for(int i = 0; i < allGrades.size(); i++)
    {
        for(int j = 0; j < allGrades[i].size(); j++)
        {
            for(int k = 0; k < allGrades[i][j].size(); k++)
            {
                minIndex = k;
                minValue = allGrades[i][typeOfAssignment][k];
                for(int index = k + 1; index < allGrades[i][j].size(); index++)
                {
                    if(allGrades[i][typeOfAssignment][index] < minValue)
                    {
                        minValue = allGrades[i][typeOfAssignment][index];
                    }
                }
                swap(allGrades[i][typeOfAssignment][minIndex], allGrades[i][typeOfAssignment][k]);
            }
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
}

/*
 * @author: Natasha Kho
 * @param: filestream file variable
 * @param: reference integer array of length 5
*/
void getTotalAssignments(fstream& file, int (&totalAssignmentsArray)[5]){
    for(int i = 0; i < 5; i++ ){
        file >> totalAssignmentsArray[i];
    }
    
}

/*
 * @author Natasha Kho
*/
void populateGradeVector(int (&totalAssignmentAmount)[5], vector<vector<vector<double>>> &allGrades, int amountOfStudents){
    for(int i = 0; i < amountOfStudents + 1; i++){ // iterate 40 times because 40 students
        vector<vector<double>> studentScore; // Students' scores
        for(int j = 0; j < 5; j++){ // iterate 5 times because 5 categories per student
            vector<double> individualGrades;
            for(int k = 0; k < totalAssignmentAmount[j]; k++){ // iterates through amount of grades for each category
                individualGrades.push_back(0);
            }
            studentScore.push_back(individualGrades);
        }
         allGrades.push_back(studentScore); // pushing data for one student
                                            // allGrades[i] = push back needs to contain vector<vector<double>
    }
}

/*
 * @author Natasha Kho
 * overloaded
*/
void populateStudentVector(int (&totalAssignmentAmount)[5], vector<vector<double>> &allGrades, int amountOfStudents){
    for(int i = 0; i < amountOfStudents + 1; i++){ // iterate 40 times because 40 students
        vector<double> studentScore; // Students' scores
        for(int j = 0; j < 5; j++){ // iterate 5 times because 5 categories per student
            
            studentScore.push_back(0);
        }
        // cout << endl;
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
    }
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
    calculatedPercentages.push_back((grade/total)*gradeWeight);
}

/*
 * @author: Natasha Kho
 * secret second author
*/
void calculateClassPercentage(vector<vector<vector<double>>> grade, vector<double> total, double gradeWeight, vector<vector<double>> &calculatedPercentages, int assignmentType){
    double forklift = 0;
    for (int i = 0; i < grade.size(); i++){ // 40 iterations
        forklift = 0;
        for (int j = 0; j < grade[i].size(); j++){ //  5 iterations
            for (int k = 0; k < grade[i][j].size(); k++){ // amt of assignments
                forklift += grade[i][assignmentType][k] / total[assignmentType] * gradeWeight;
            }
            calculatedPercentages[i].at(assignmentType) = forklift; //40 x 5   
            break;

        }
    }
}

/*
 * @author: Natasha Kho
 * for single student usage
*/
void getAverageOfCategory(double pointsEarned, int amountOfAssignments, vector<double> &averageOfSingleCategory){
    averageOfSingleCategory.push_back(pointsEarned/amountOfAssignments);
}

/*
 * @author: Natasha Kho
 * for class average
*/
void getAverageOfCategoryOfClass(vector<vector<double>> calculatedPercentages, int assignmentType, vector<double> &averageOfSingleCategory){
    double pointsEarned = 0; 
    for (int i = 0; i < calculatedPercentages.size(); i++){
        pointsEarned += calculatedPercentages[i][assignmentType];
    }
    
    averageOfSingleCategory.push_back(pointsEarned/40);
}

/*
 * @author: Natasha Kho
 * returns totalEarnedPoints (which is points earned in each category)
*/
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

    int cursor = 0;
    for(int assignmentInCategory: totalAssignments){
        double temp = 0;;
        for(int i = 0; i < assignmentInCategory; i++){
            temp += oneStudentScore[cursor];
            cursor++;
        }
        totalEarnedPoints.push_back(temp);
    }
}

void getTotalScoresOfOneCategory(vector<vector<vector<double>>> &allGrades, int (&totalAssignments)[5], int assignmentType, vector<vector<vector<double>>> &totalCategoryPoints){
    vector<double> pointsEarnedForOneCategory;
    double temp = 0;
    for(int i = 1; i < allGrades.size(); i++){
        for(int j = 0; j < allGrades[assignmentType].size(); j++){
            for(int k = 0; k < allGrades[i][assignmentType].size(); k++){
                temp += allGrades[i][assignmentType][k]; // adds each score of one category
            }

            pointsEarnedForOneCategory.push_back(temp); // puts total of one category into vector;
            temp = 0;
            break;
        }
    }

    for(int i = 0; i < allGrades.size()-1; i++){ // this runs 40 times
        totalCategoryPoints[i][assignmentType].at(0) = pointsEarnedForOneCategory[i]; // this is not working correctly

    }
}

/*
 * @author: Natasha Kho
*/
void generateReportClass(fstream &inputFile, int classSize, vector<vector<vector<double>>> &allGrades, int (&totalAssignmentsDropped)[5], int (&totalAssignments)[5], 
                         int isGradesDropped, vector<vector<double>> &calculatedPercentages, vector<double> &averageScores){
    // used for calculations
    vector<vector<vector <double>>> totalCategoryPoints;
    vector<double> totalPointsPossible;
    int temp[5] = {1, 1, 1, 1, 1};

    // First line of file
    getTotalAssignments(inputFile,totalAssignments);

    getTotalAssignments(inputFile,totalAssignmentsDropped);

    populateGradeVector(totalAssignments, allGrades, classSize);

    getPoints(inputFile, totalAssignments, allGrades);

    populateGradeVector(temp, totalCategoryPoints, 39);
    populateStudentVector(temp, calculatedPercentages, 39);    
    if(isGradesDropped){
        for(int i = 0; i < sizeof(totalAssignmentsDropped)/sizeof(totalAssignmentsDropped[0]); i++){
            int amtOfAssignmentsToDrop = totalAssignmentsDropped[i];
            while(amtOfAssignmentsToDrop){
                dropLowestScore(inputFile, allGrades,i);
                amtOfAssignmentsToDrop--;
                totalAssignments[i]--;
            }
        }
    }

    
    for(int i = 0; i < sizeof(totalAssignmentsDropped)/sizeof(totalAssignmentsDropped[0]); i++){ // goes for amount of categories there are
        getTotalScoresOfOneCategory(allGrades, totalAssignments, i, totalCategoryPoints); // student score is totalEarnedPoints
    }


    getIndividualStudentPointsTotal(allGrades, 0, totalAssignments, totalPointsPossible);
    for(int i = 0; i < allGrades.size() - 1; i++){ // this needs to iterate 40 times
        for(int j = 0; j < sizeof(totalAssignments)/sizeof(totalAssignments[0]); j++){ // iterates 5 times
            calculateClassPercentage(totalCategoryPoints, totalPointsPossible, gradeWeights[j], calculatedPercentages, j);
        }
    }

    for(int i = 0; i < sizeof(totalAssignments)/sizeof(totalAssignments[0]); i++){
        getAverageOfCategoryOfClass(calculatedPercentages, i, averageScores);
    }
}
void generateReportOneStudent(fstream &inputFile, vector<vector<vector<double>>> &allGrades, int (&totalAssignmentsDropped)[5], int (&totalAssignments)[5], int isGradesDropped, int studentNumber, 
vector<double> &calculatedPercentages, vector<double> &averageScores){
    // First line of file
    getTotalAssignments(inputFile,totalAssignments);

    // Have a function to get amount of quiz/labs dropped
    getTotalAssignments(inputFile,totalAssignmentsDropped);
    populateGradeVector(totalAssignments, allGrades, 40);
    getPoints(inputFile, totalAssignments, allGrades);

    // used for calculations
    vector<double> totalEarned;
    vector<double> totalPointsPossible;

    if(isGradesDropped){
        for(int i = 0; i < sizeof(totalAssignmentsDropped)/sizeof(totalAssignmentsDropped[0]); i++){
        int amtOfAssignmentsToDrop = totalAssignmentsDropped[i];
            while(amtOfAssignmentsToDrop){
                dropLowestScore(inputFile, allGrades,i );
                amtOfAssignmentsToDrop--;
                totalAssignments[i]--;
            }
        }
    }
    getIndividualStudentPointsTotal(allGrades, studentNumber, totalAssignments, totalEarned); // student score is totalEarnedPoints
    getIndividualStudentPointsTotal(allGrades, 0, totalAssignments, totalPointsPossible);

    for(int i = 0; i < totalEarned.size(); i++){
        calculatePercentage(totalEarned[i], totalPointsPossible[i], gradeWeights[i], calculatedPercentages);
        getAverageOfCategory(totalEarned[i], totalAssignments[i], averageScores);
    }
}

void vector_dumptruck(
    vector<double> &calculatedPercentages, vector<double> &averageScores,
    vector<vector<double>> &calculatedClassPercentages,
    vector<vector<vector<double>>> &allGrades){
        calculatedPercentages.clear();
        averageScores.clear();
        calculatedClassPercentages.clear();
        allGrades.clear();
}

/*
 * @author Natasha Kho
 * couts the report
 * @param: weighted project grade as decimal
*/
void printResults(vector<double> calculatedPercentages, vector<double> averageScores){
    string letterGrade = getLetterGrade(calculatedPercentages);

    cout << "===============================================\n" << setw(20) << "GRADES"           << "\n"
    << "Project: "      << setw(23) << fixed << setprecision(2) << calculatedPercentages[3] * TO_PERCENT    << "%\n" 
    << "Lab: "          << setw(27)                             << calculatedPercentages[0] * TO_PERCENT    << "%\n"
    << "Quiz: "         << setw(26)                             << calculatedPercentages[1] * TO_PERCENT    << "%\n"
    << "Exams: "        << setw(25)                             << calculatedPercentages[2] * TO_PERCENT    << "%\n"
    << "Final Exam: "   << setw(20)                             << calculatedPercentages[4] * TO_PERCENT    << "%\n"
    << "Total: "        << setw(25)                             << calculatedPercentages[5] * TO_PERCENT    << "%\n"
    << "Final Letter Grade: " << setw(10)                       << letterGrade                              << "\n"
    << "===============================================\n" << endl;

    cout << "===============================================\n" << setw(25) << "AVERAGE GRADES" << "\n"
    << "Project: "      << setw(23) << fixed << setprecision(2) << averageScores[3]             << "%\n" 
    << "Lab: "          << setw(27)                             << averageScores[0]             << "%\n"
    << "Quiz: "         << setw(26)                             << averageScores[1]             << "%\n"
    << "Exams: "        << setw(25)                             << averageScores[2]             << "%\n"
    << "Final Exam: "   << setw(20)                             << averageScores[4]             << "%\n"
    << "===============================================\n" << endl;
}

/*
 * @author Natasha Kho
*/
void printClassResults(vector<double> classAvg){
    double totalAvg;
    for(double x: classAvg){
        totalAvg += x;
    }
    
    cout << "===============================================\n" << setw(25) << "CLASS AVERAGES" << "\n"
    << "Project: "      << setw(23) << fixed << setprecision(2) << classAvg[3] * TO_PERCENT     << "%\n" 
    << "Lab: "          << setw(27)                             << classAvg[0] * TO_PERCENT     << "%\n"
    << "Quiz: "         << setw(26)                             << classAvg[1] * TO_PERCENT     << "%\n"
    << "Exams: "        << setw(25)                             << classAvg[2] * TO_PERCENT     << "%\n"
    << "Final Exam: "   << setw(20)                             << classAvg[4] * TO_PERCENT     << "%\n"
    << "Total: "        << setw(25)                             << totalAvg    * TO_PERCENT     << "%\n"
    << "===============================================\n" << endl;
}

/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
void printMenu(void){
    cout <<  "=========================================================\n"
    << "Select an option:\n"
    << "1. Generate fake data\n"
    << "2. Select which score file to use\n"
    << "3. Generate grade report\n"
    << "4. Show class average percentages\n"
    << "5. N/A\n"
    << "6. N/A \n"
    << "7. Log Out\n"
    << "8. Exit program\n"
    << "=========================================================\n";


}

/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
void fileImport(fstream &inputFile) {
  string scoreFile; // create string var for file name
  cout << "Please Enter Score File:\n"; // prompt use to enter file name
  cin  >> scoreFile; // take filename input from user
  inputFile.open(scoreFile); // attempt to open file

  // if file did not open:
  while(inputFile.is_open() == 0) {
    inputFile.close(); // close file
    cout << "There was an error opening the file. Please enter the Score File again:\n"; // repeat prompt to open valid file
    cin  >> scoreFile; // take input from user and attempt to open file again
    inputFile.open(scoreFile);
    // if file still does not open, loop error message
  }
}


/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
int checkFile(fstream &inputFile){
    while(!inputFile.is_open()){
        cout << "Files is not open... Please input a file to use\n";
        fileImport(inputFile);
    }
    return 1;
}