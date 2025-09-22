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
#include "grades.h"

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
void printMenu(int userSelect);
void generateReport(string fileName);
void printResults(double projectGrade, double labGrade, double quizGrade, double examGrade, double finalGrade, double totalGrade, char letterGrade);

int main (void){
    fstream inFile;
    int userSelect;
    string fileName;
    inFile.open("text.txt");
    printMenu(userSelect);
    generateReport(fileName);
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
 * @param: filestream file variable
 * @param: amount of assignments to iterate through
 * @return total score of one category of assignment with the lowest grade dropped
*/
double dropLowestScore(fstream& file, int iterationAmount){
    int score1 = 0, score2 = 0, maxScore, minScore, total = 0;

    file >> score1 >> score2;
    cout << "SCORE1: " << score1 << " SCORE2: " << score2 << endl;  
    
    if (iterationAmount%2 == 0){
        for (int i = 0; i < iterationAmount-2; i++){
            minScore = min(score1, score2);
            maxScore = max(score1, score2);
            total += maxScore;
            score1 = minScore;
            file >> score2;
            
            cout <<  "MAX: " << maxScore << " MIN: " << minScore << " TOTAL: " << total << endl;
            cout << "SCORE1: " << score1 << " SCORE2: " << score2 << endl;  
        }
    }else if(iterationAmount%2 != 0){
        for (int i = 0; i < iterationAmount-1; i++){
            minScore = min(score1, score2);
            maxScore = max(score1, score2);
            total += maxScore;
            score1 = minScore;
            if(i<iterationAmount-2){
                file >> score2;
            }
            cout <<  "MAX: " << maxScore << " MIN: " << minScore << " TOTAL: " << total << endl;
            cout << "SCORE1: " << score1 << " SCORE2: " << score2 << endl;  
        }
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
    double quizTotal    = getPoints(file, quizAmt);
    double examTotal    = getPoints(file, examAmt);
    double projectTotal = getPoints(file, projectAmt);
    double finalTotal   = getPoints(file, finalAmt);

    // Points earned in each category
    double labGrade     = dropLowestScore(file, labAmt);
    double quizGrade    = dropLowestScore(file, quizAmt);
    double examGrade    = getPoints(file, examAmt);
    double projectGrade = getPoints(file, projectAmt);
    double finalGrade   = getPoints(file, finalAmt);
    cout << labGrade << " " << quizGrade << " " << examGrade << " " << projectGrade << " " << finalGrade << endl;

    labGrade = calculatePercentage(labGrade, labTotal-1, FIFTEEN_PERCENT);
    quizGrade = calculatePercentage(quizGrade, quizTotal-1, FIFTEEN_PERCENT);
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
 * @param: weighted project grade as decimal
 * @param: weighted lab grade as decimal
 * @param: weighted quiz grade as decimal
 * @param: weighted exam grade as decimal
 * @param: weighted final grade as decimal
 * @param: total grade earned as decimal
 * @param: final letter grade 
*/
void printResults(double projectGrade, double labGrade, double quizGrade, double examGrade, double finalGrade, double totalGrade, char letterGrade){
    cout << "Project: " << fixed << setprecision(2) << projectGrade*TO_PERCENT << "%\n" 
    << "Lab: " << labGrade*TO_PERCENT << "%\n"
    << "Quiz: " << quizGrade*TO_PERCENT << "%\n"
    << "Exams: " << examGrade*TO_PERCENT << "%\n"
    << "Final Exam: " << finalGrade*TO_PERCENT << "%\n"
    << "Total: " << totalGrade*TO_PERCENT << "%\n"
    << "Final Letter Grade: " << letterGrade << endl;
}

/*
 * @author: Emily Hsu
 * @param: User's new password
*/
int userLogin(string newPassword){
    int i=0, access = 0, userSelect;
    string username, password;

    const string password1 = "abc", password2 = "123";

    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "Enter your password: " << endl;
    cin >> password;

    if ((password == password1)|(password == password2)|(password == newPassword)){
        access = 1;
    }
    while(access != 1){
        cout << "Password is wrong, try again." << endl;
        cin >> password;
        if ((password == password1)|(password == password2)|(password == newPassword)){
            break;
        }
        i++;
        if (i==2){
            cout << "You failed to input the correct password." << endl;
            break;
        }
    } 
    return access;
}

/*
 * @author: Emily Hsu
 * @param: user's integer selection of function in menu 
*/
void printMenu(int userSelect){
    fstream userFile;
    int access, uploaded = 0;
    string fileName, newPassword = "";

    access = userLogin(newPassword);
    if (access == 0){
        userSelect = 6;
    }

    while (userSelect != 6){
        cout << "Select an option:\n1. Generate fake data\n2. Which score file to use\n3. Show student score report\n4. Change password\n5. Log out\n6. Exit program" << endl;
        cin >> userSelect;
        switch (userSelect){
        case 1:
            cout << "Enter a name for your file ending with '.txt': " << endl;
            cin >> fileName;
            generateReport(fileName);
            cout << fileName << " generated!" << endl;
            break;
        case 2:
            cout << "Choose a score file: " << endl;
            cin >> fileName;
            cout << "Successfully uploaded score file " << fileName << "!" << endl;
            uploaded = 1;
            break;
        case 3:
            if (uploaded == 0){
                cout << "Choose a file for your score report: " << endl;
                cin >> fileName;
            } 
            userFile.open(fileName);
            while (userFile.fail()){
                cout << "Re-enter your file name." << endl;
                cin >> fileName;
                userFile.open(fileName);
            }
            generateGradeReport(userFile);
            uploaded = 0;
            userFile.close();
            break;
        case 4:
            cout << "Enter your new password: " << endl;
            cin >> newPassword;
            cout << "Password changed!" << endl;
            break;
        case 5:
            cout << "Logging out..." << endl;
            userLogin(newPassword);
            break;
        case 6: 
            break;
        default: 
            cout << "Error occurred. Please try again." << endl;
            break;
        }
    } cout << "Exiting program..." << endl;
}

