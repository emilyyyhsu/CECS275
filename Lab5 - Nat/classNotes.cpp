#include "classNotes.h"

using namespace std;

// function prototypes
void generateScores(ofstream& out, int amount, int maxPossibleScore); 
void generateMaxScores(ofstream& out, int maxScore, int amount);

int main(){
    ofstream out;
    out.open("randomlyGenerated.txt");
    // srand(time(0)); // time() makes it actually random
    // cout << rand() % 30 << endl;  // %21 fives you 0-20
    // to generate between a range:
    // int min = 0, max = 101;
    // for(int i = 0; i < 20; i++){
    //     out << min + rand() % (max - min + 1) << " ";
    // }
    
    // Generates amount of each assignment in each category
    out << LAB_AMOUNT << " " 
        << QUIZ_AMOUNT << " " 
        << MIDTERM_AMOUNT << " " 
        << PROJECT_AMOUNT << " " 
        << FINAL_EXAM_AMOUNT << endl;

    // Generate max scores
    generateMaxScores(out, MAX_LAB_SCORE, LAB_AMOUNT);
    generateMaxScores(out, MAX_QUIZ_SCORE, QUIZ_AMOUNT);
    generateMaxScores(out, MAX_MIDTERM_SCORE, MIDTERM_AMOUNT);
    generateMaxScores(out, MAX_PROJECT_SCORE, PROJECT_AMOUNT);
    generateMaxScores(out, MAX_FINAL_EXAM_SCORE, FINAL_EXAM_AMOUNT);

    out << endl;

    generateScores(out, LAB_AMOUNT, MAX_LAB_SCORE); // Labs
    generateScores(out, QUIZ_AMOUNT, MAX_QUIZ_SCORE); // Quizzes
    generateScores(out, MIDTERM_AMOUNT, MAX_MIDTERM_SCORE); // Midterms
    generateScores(out, PROJECT_AMOUNT, MAX_MIDTERM_SCORE); // Projects
    generateScores(out, FINAL_EXAM_AMOUNT, MAX_FINAL_EXAM_SCORE); // Final

    out.close();
    cout << "File generated!" << endl;
    return 0;
}

void generateMaxScores(ofstream& out, int maxScore, int amount){
    for(int i = 0; i < amount; i++){
        out << maxScore << " ";
    }
}

void generateScores(ofstream& out, int amount, int maxPossibleScore){
    int min = 0, max = maxPossibleScore;
    for(int i = 0; i < amount; i++){
        out << min + rand() % (max - min + 1) << " ";
    }
    
}