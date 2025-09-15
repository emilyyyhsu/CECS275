/*
 * This program calculates your grades
 * @author: Natasha Kho
 * @author: Emily Hsu
 * Created on: 2025-09-11
 * Last Modified: 2025-09-12
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
            TWENTY_PERCENT = 0.20;

// Converts fractional value to percentage
const int TO_PERCENT = 100;
const double GradeA = 0.90,
             GradeB = 0.80,
             GradeC = 0.70,
             GradeD = 0.60;

int main(){
    // User input variables
    string username, password, filename;

    // Variables for reading file
    int score;
    fstream file;

    // Amount of assignments in each category
    int labAmount, quizAmount, midtermAmount, projectAmount, finalExamAmount;

    // Points earned in each category
    double projectGrade = 0, labGrade = 0, quizGrade = 0, 
    examOneGrade = 0, examTwoGrade = 0, finalExamGrade = 0; 
    
    // Points possible in each category
    double totalGrade = 0, labTotal = 0, quizTotal = 0, 
    examTotal = 0, projectTotal = 0, finalExamTotal = 0;

    char letterGrade;

    // Prompt user for username, password, and grade file
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter grade file: ";
    cin >> filename;

    file.open(filename);
    // If user doens't input valid file, keep prompting until they do
    while(file.fail()){
        cout << "Error opening file. Please enter a valid grade file: ";
        cin >> filename;
        file.open(filename);
    }

    // =============================================
    // First line of file
    // Contains amount of assignments in each category
    file >> labAmount >> quizAmount >> midtermAmount 
         >> projectAmount >> finalExamAmount;
 
    // =============================================
    // Second line of file
    // 20
    for(int i = 0; i < labAmount; i++){
        file >> score;
        labTotal += score;
    }

    // 7
    for(int i = 0; i < quizAmount; i++){
        file >> score;
        quizTotal += score;
    }
    // 2
    for(int i = 0; i < midtermAmount; i++){
        file >> score;
        examTotal += score;
    }
    // 1
    for(int i = 0; i < projectAmount; i++){
        file >> score;
        projectTotal += score;
    }

    // 1
    file >> score;
    finalExamTotal += score;

    // =============================================
    // Second line of file
    // Adds numbers together for actual score
    score = 0;
    for(int i = 0; i < labAmount; i++){
        file >> score;
        labGrade += score;
    }

    score = 0;
    for(int i = 0; i < quizAmount; i++){
        file >> score;
        quizGrade += score;
    }

    score = 0;
    file >> score;
    examOneGrade += score;

    score = 0;
    file >> score;
    examTwoGrade += score;
    
    score = 0;
    for(int i = 0; i < projectAmount; i++){
        file >> score;
        projectGrade += score;
    }

    score = 0;
    file >> score;
    finalExamGrade += score;

    // =============================================

    // Calculate total grade based on weights
    labGrade = (labGrade/labTotal) * FIFTEEN_PERCENT;
    quizGrade = (quizGrade/quizTotal) * FIFTEEN_PERCENT;
    examOneGrade = (examOneGrade/(examTotal/midtermAmount)) * TWENTY_PERCENT;
    examTwoGrade = (examTwoGrade/(examTotal/midtermAmount)) * TWENTY_PERCENT;
    projectGrade = (projectGrade/projectTotal) * TEN_PERCENT; 
    finalExamGrade = (finalExamGrade/finalExamTotal) * TWENTY_PERCENT;
    totalGrade = labGrade + quizGrade + examOneGrade + examTwoGrade 
                + projectGrade + finalExamGrade;

    // Determine letter grade
    if (totalGrade >= GradeA) {
        letterGrade = 'A';
    } else if (totalGrade >= GradeB){
        letterGrade = 'B';
    } else if (totalGrade >= GradeC){
        letterGrade = 'C';
    } else if (totalGrade >= GradeD){
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    // Output results
    cout << "=========================================================\n"
    << fixed << setprecision(2) << "Hello " << username << "!\n"
    << "Project: " <<  projectGrade * TO_PERCENT / TEN_PERCENT << "%\n"
    << "Labs: " << labGrade * TO_PERCENT / FIFTEEN_PERCENT << "%\n"
    << "Quiz: " << quizGrade * TO_PERCENT / FIFTEEN_PERCENT << "%\n"
    << "Exam 1: " << examOneGrade * TO_PERCENT / TWENTY_PERCENT << "%\n"
    << "Exam 2: " << examTwoGrade * TO_PERCENT / TWENTY_PERCENT << "%\n"
    << "Final Exam: " << finalExamGrade * TO_PERCENT / TWENTY_PERCENT << "%\n"
    << "Total: " << totalGrade * TO_PERCENT << "%\n"
    << "Final Letter Grade: " << letterGrade << endl;
}