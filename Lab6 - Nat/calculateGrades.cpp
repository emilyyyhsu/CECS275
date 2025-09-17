/*
 * This program calculates your grades
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

using namespace std;

// Grade weights
const double TEN_PERCENT = 0.10,
            FIFTEEN_PERCENT = 0.15,
            TWENTY_PERCENT = 0.20,
            FORTY_PERCENT = 0.40;

// Converts fractional value to percentage
const int TO_PERCENT = 100;
const double GradeA = 0.90,
             GradeB = 0.80,
             GradeC = 0.70,
             GradeD = 0.60;

// Function prototypes
void generateGradeReport(fstream& file);

int main (void){
    fstream inFile;
    inFile.open("text.txt");
    generateGradeReport(inFile);
}

/*
 * @author: Natasha Kho
 * @param: filestream file variable
 * @return total number of assignments for one category 
*/
int getTotalAssignments(fstream& file){
    // First line of file
    int totalAssignments = 0;
    file >> totalAssignments;
    return totalAssignments;
}

/*
 * @author: Natasha Kho
 * @param: filestream file variable
 * @param: amount of assignments to iterate through
 * @return total score of one category of assignment
*/
double getPoints(fstream& file, int iterationAmount){
    int score = 0;
    double total = 0;
    for(int i = 0; i < iterationAmount; i++){
        file >> score;
        total += score;
    }
    return total;
}

/*
 * @author: Natasha Kho
 * @param: total grade after calculations
 * @return letter grade based on score
*/
char getLetterGrade(double totalGrade){
    if (totalGrade >= GradeA) {
        return 'A';
    } else if (totalGrade >= GradeB){
        return 'B';
    } else if (totalGrade >= GradeC){
        return 'C';
    } else if (totalGrade >= GradeD){
        return 'D';
    } else {
        return 'F';
    }
}

/*
 * @author: Natasha Kho
 * @param: actual points earned on total assignmenets
 * @param: total amount of points possible on assignment type
 * @return percentage of specific category
*/
double calculatePercentage(double grade, double total, double gradeWeight){
    return (grade/total) * gradeWeight;
}
/*
 * @author: Natasha Kho
 * @author: Emily Hsu
 * @param: score file
*/
void generateGradeReport(fstream& file){
    // Amount of assignments in each category
    int labAmt        = getTotalAssignments(file);
    int quizAmt       = getTotalAssignments(file);
    int examAmt       = getTotalAssignments(file);
    int projectAmt    = getTotalAssignments(file);
    int finalAmt      = getTotalAssignments(file);

    // Total points possible in each category
    double labTotal     = getPoints(file, labAmt);
    double quizTotal    = getPoints(file, quizAmt);
    double examTotal    = getPoints(file, examAmt);
    double projectTotal = getPoints(file, projectAmt);
    double finalTotal   = getPoints(file, finalAmt);

    // Points earned in each category
    double labGrade     = getPoints(file, labAmt);
    double quizGrade    = getPoints(file, quizAmt);
    double examGrade    = getPoints(file, examAmt);
    double projectGrade = getPoints(file, projectAmt);
    double finalGrade   = getPoints(file, finalAmt);

    labGrade = calculatePercentage(labGrade, labTotal, FIFTEEN_PERCENT);
    quizGrade = calculatePercentage(quizGrade, quizTotal, FIFTEEN_PERCENT);
    examGrade = calculatePercentage(examGrade, examTotal, FORTY_PERCENT);
    projectGrade = calculatePercentage(projectGrade, projectTotal, TEN_PERCENT);
    finalGrade = calculatePercentage(finalGrade, finalTotal, TWENTY_PERCENT);
    double totalGrade = labGrade + quizGrade + examGrade
                + projectGrade + finalGrade;
    
    char letterGrade = getLetterGrade(totalGrade);


    // printResults();
}

/*
 * @author: Emily Hsu
*/
void printResults(void){

}

/*
 * @author: Emily Hsu
*/
void printMenu(void){

}

/*
 * @author: Emily Hsu
*/
void exit(void){

}
