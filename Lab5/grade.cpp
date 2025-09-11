#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    ifstream userScores;
    userScores.open("grade.txt");
    string username, password, maxPossibleScores, actualScores, letterGrade;
    int i, lab, quiz;
    double labScore, quizScore, midterm1, midterm2, projectScore, finalExam, totalGrade;


    while(userScores >> lab >> quiz >> midterm1 >> midterm2 >> projectScore >> finalExam){
        cout << "Enter your username:\n" << username << endl;
        cout << "Enter your password:\n" << password << endl;
        if (getline(userScores, maxPossibleScores)){
            if (getline(userScores, actualScores)){
                for(i = 0; i < 41; i= i + 2){
                    lab = actualScores[i];
                    labScore += lab;                
                    for(i = 40; i < 53; i = i + 2){
                        quiz = actualScores[i];
                        quizScore += quiz;
                    }                    
                }
                
            }
        }
    }
    labScore = labScore*0.15;
    quizScore = quizScore*0.15;
    midterm1 = actualScores[54]*0.20;
    midterm2 = actualScores[56]*0.20;
    projectScore = actualScores[58]*0.10;
    finalExam = actualScores[60]*0.20;

    totalGrade = labScore + quizScore + midterm1 + midterm2 + projectScore + finalExam;
    
    if (totalGrade >= 90) {
        letterGrade = 'A';
    } else if (totalGrade >= 80){
        letterGrade = 'B';
    } else if (totalGrade >= 70){
        letterGrade = 'C';
    } else if (totalGrade >= 60){
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }
    
    cout << fixed << setprecision(2) << labScore << " " << quizScore << " " << midterm1 << " " << midterm2 << " " << projectScore << " " << finalExam << " " << totalGrade << endl << letterGrade;
}