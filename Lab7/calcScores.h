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
#include "randGen.h"

// Function prototypes
void printMenu(int userSelect);
void generateReport(string fileName);
void printResults(double projectGrade, double labGrade, 
                    double quizGrade, double examGrade, double finalGrade, 
                    double totalGrade, char letterGrade);

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
 * @author: Natasha Kho
 * @param: filestream file variable
 * @param: amount of assignments to iterate through
 * @return total score of one category of assignment with the lowest grade dropped
*/
double dropLowestScore(fstream& file, int iterationAmount){
    int currScore, 
        lowestScore = 0x7FFFFFFF; // this is the maximum int in hex
    double total = 0; // want to return a double for data-type math reasons later

    for(int i = 0; i < iterationAmount; i++){
        file >> currScore; // Gets score

        if(currScore <= lowestScore){ // if the previous score is lower than the current score
            lowestScore = currScore; // then, we put the previous score as the lowest score
            // cout << "LOWEST SCORE " << i << " " << lowestScore << endl;
        }
        // We add the current score to the total, regardless of how low it is
        total += currScore;
    }
    total -= lowestScore;
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
std::string getLetterGrade(double totalGrade){
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
double calculatePercentage(double grade, double total, double gradeWeight){
    return (grade/total) * gradeWeight;
}

/*
 * @author: Natasha Kho
 * @author: Emily Hsu
 * @param: score file
*/
std::string generateGradeReport(fstream& file){
    std::string garbage;
    // Amount of assignments in each category
    int labAmt        = getTotalAssignments(file);  
    int quizAmt       = getTotalAssignments(file);  
    int examAmt       = getTotalAssignments(file);
    int projectAmt    = getTotalAssignments(file);
    int finalAmt      = getTotalAssignments(file);

    // Total points possible in each category
    double labTotal     = dropLowestScore(file, labAmt);    
    double quizTotal    = dropLowestScore(file, quizAmt);   
    double examTotal    = getPoints(file, examAmt);
    double projectTotal = getPoints(file, projectAmt);
    double finalTotal   = getPoints(file, finalAmt);

    // Points earned in each category
    double labGrade     = dropLowestScore(file, labAmt); 
    double quizGrade    = dropLowestScore(file, quizAmt); 
    double examGrade    = getPoints(file, examAmt);
    double projectGrade = getPoints(file, projectAmt);
    double finalGrade   = getPoints(file, finalAmt);

    labGrade            = calculatePercentage(labGrade, labTotal, FIFTEEN_PERCENT);
    quizGrade           = calculatePercentage(quizGrade, quizTotal, FIFTEEN_PERCENT);
    examGrade           = calculatePercentage(examGrade, examTotal, FORTY_PERCENT);
    projectGrade        = calculatePercentage(projectGrade, projectTotal, TEN_PERCENT);
    finalGrade          = calculatePercentage(finalGrade, finalTotal, TWENTY_PERCENT);
    double totalGrade   = labGrade + quizGrade + examGrade
                                   + projectGrade + finalGrade;
    
    string letterGrade = getLetterGrade(totalGrade);
    // has to be split
    
    garbage = std::to_string(projectGrade) + "<" + std::to_string(labGrade) + "<" 
            + std::to_string(quizGrade) + "<" + std::to_string(examGrade) +  "<"  
            + std::to_string(finalGrade) + "<" + std::to_string(totalGrade) + "<" + (letterGrade);
    return garbage;
}

/*
 * @author: Emily Hsu
 * @author Natasha Kho (Formatting)
 * couts the report
 * @param: weighted project grade as decimal
 * @param: weighted lab grade as decimal
 * @param: weighted quiz grade as decimal
 * @param: weighted exam grade as decimal
 * @param: weighted final grade as decimal
 * @param: total grade earned as decimal
 * @param: final letter grade 
*/
void printResults(std::string inputString){
    cout << inputString;
    string inputStringCopy = inputString;
    string delimiter = "<";
    int position = inputStringCopy.find(delimiter);
    double projectGrade, labGrade, quizGrade, examGrade, finalGrade, totalGrade;
    string letterGrade;

    projectGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);

    
    labGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);


    quizGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);

    examGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);

    finalGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);


    totalGrade = std::stod(inputStringCopy.substr(0, position));
    inputStringCopy.erase(0, position + delimiter.length());
    position = inputStringCopy.find(delimiter);


    letterGrade = inputStringCopy.substr(0, position);

    cout << "=========================================================\n" 
    << "Project: "      << setw(23) << fixed << setprecision(2) << projectGrade * TO_PERCENT    << "%\n" 
    << "Lab: "          << setw(27)                             << labGrade * TO_PERCENT        << "%\n"
    << "Quiz: "         << setw(26)                             << quizGrade * TO_PERCENT       << "%\n"
    << "Exams: "        << setw(25)                             << examGrade * TO_PERCENT       << "%\n"
    << "Final Exam: "   << setw(20)                             << finalGrade * TO_PERCENT      << "%\n"
    << "Total: "        << setw(25)                             << totalGrade * TO_PERCENT      << "%\n"
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



/*
 * @author: Natasha Kho
 * @author: Emily Hsu
*/
string setNewPassword(void){
    string newPassword;
    cout << "---------------------------------------------------------\n"  
         << "Enter your new password: " << endl;
    cin  >> newPassword;
    cout << "Password changed!"
         << "\n---------------------------------------------------------\n" << endl;
    return newPassword;
}

/*
 * @author: Emily Hsu
 * @param: User's new password
*/
int userLogin(string newPassword){
    int i=0, access = 0, userSelect;
    string username, password;

    const string password1 = "abc", password2 = "123";
    cout << "---------------------------------------------------------" << endl;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "Enter your password: " << endl;
    cin >> password;

    if ((password == password1)|(password == password2)|(password == newPassword)){
        access = 1;
    }
    while(access != 1){
        cout << "---------------------------------------------------------\n" 
             << "Password is wrong, try again." << endl;
        cin >> password;
        if ((password == password1)|(password == password2)|(password == newPassword)){
            access = 1;
            break;
        }
        i++;
        if (i==2){
            cout << "=========================================================\n" 
                 << "You failed to input the correct password." 
                 << "\n=========================================================\n" 
                 << endl;
            break;
        }
    } 
    return access;
}