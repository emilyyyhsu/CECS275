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
#include <cmath>

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
 * @author: Emily Hsu
 * @param: 
 * @param: 
 * @return 
*/
double dropLowestQuiz(fstream& file, int iterationAmount){
    int score1 = 0, score2 = 0;
    double total = 0;
    file >> score1;
    for (int i = 0; i < iterationAmount; i++){
        file >> score2;
        score1 = fmin(score1, score2);
        score2 = fmax(score1, score2);
        total += score2;
    }
    return total;
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
    double quizTotal    = dropLowestQuiz(file, quizAmt);
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


    printResults(projectGrade, labGrade, quizGrade, examGrade, finalGrade, totalGrade, letterGrade);
}

/*
 * @author: Emily Hsu
*/
void printResults(double projectGrade, double labGrade, double quizGrade, double examGrade, double finalGrade, double totalGrade, char letterGrade){
    cout << "Project: " << fixed << setprecision(2) << projectGrade << "%\n" 
    << "Lab: " << labGrade << "%\n"
    << "Quiz: " << quizGrade << "%\n"
    << "Exams: " << examGrade << "%\n"
    << "Final Exam: " << finalGrade << "%\n"
    << "Total: " << totalGrade << "%\n"
    << "Final Letter Grade: " << letterGrade << endl;
}

/*
 * @author: Emily Hsu
*/
void printMenu(int userSelect){
    fstream userFile;
    string fileName;

    while (userSelect != 4){
        cout << "Select an option:\n1. Generate fake data\n2. Which score file to use\n3. Show student score report\n4. Exit program\n" << userSelect << endl;
        cin >> userSelect;
        if (userSelect == 1){
            userFile.open(fileName);
            while(userFile.fail()){
                cout << "Enter a valid file name." << endl;
            } generateGradeReport(userFile);
        } else if (userSelect == 2){
            cout << "Choose a score file: " << fileName << endl;
            cin >> fileName;
            cout << "Successfully uploaded score file " << fileName << endl;
        } else if (userSelect == 3){
            userFile.open(fileName);
            while(userFile.fail()){
                cout << "Enter a valid file name or select option 2 and choose a score file." << endl;
            } generateGradeReport(userFile);
        } else if (userSelect == 4){
            exit();
        }
    }
}

/*
 * @author: Emily Hsu
*/
void exit(void){
    cout << "Exiting program..." << endl;
}
