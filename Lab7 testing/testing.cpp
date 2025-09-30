
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void generateGradeArray(void);
int generateAssignmentAmount(int maxAssignments);
int generateScores(int maxPossibleScore);

// make function to randomize this, i think
const int MAX_QUIZZES = 7;
const int MAX_LABS = 20;
const int MAX_MIDTERMS = 3;
const int PROJECT_AMOUNT = 1;
const int FINAL_EXAM_AMOUNT = 1;
const int MAX_ASSIGNMENTS_DROPPED = 2;
const int MAX_QUIZ_SCORE = 10;
const int MAX_LAB_SCORE = 5;
const int MAX_MIDTERM_SCORE = 50;
const int MAX_PROJECT_SCORE = 100;
const int MAX_FINAL_EXAM_SCORE = 100;

int main(void){
    for(int i=0; i<40; i++){
        generateGradeArray();
    }
    
    return 0;
}

/*
 * @author: Emily Hsu
 * @param: file to write to
 * @param: maximum number of assignments possible
 * Generates the number of assignments for each category
*/
int generateAssignmentAmount(int maxAssignments){
    int min = 1, numAssignments = 0;
    return numAssignments = min + rand() % (maxAssignments - min);
}

/*
 * @author: Natasha Kho
 * @param: file to write to
 * @param: amount of iterations
 * @param: maximum points user can get on an assignment
 * Generates the scores the user actually got
 */
int generateScores(int maxPossibleScore){
    int min = maxPossibleScore - 5, max = maxPossibleScore, score;
    return score = min + rand() % (max - min + 1);
}

void generateGradeArray(void){
    int i;
    int num_labs = generateAssignmentAmount(MAX_LABS);
    int num_quizzes = generateAssignmentAmount(MAX_QUIZZES);
    int num_midterms = generateAssignmentAmount(MAX_MIDTERMS);

    vector<vector<int>> student;

    vector<int> num_assignments = {num_labs, num_quizzes, num_midterms, PROJECT_AMOUNT, FINAL_EXAM_AMOUNT};
    
    vector<int> dropped_assignments;
    int dropped_labs = generateAssignmentAmount(MAX_ASSIGNMENTS_DROPPED);
    int dropped_quizzes = generateAssignmentAmount(MAX_ASSIGNMENTS_DROPPED);
    dropped_assignments.push_back(dropped_labs);
    dropped_assignments.push_back(dropped_quizzes);
    for(i=0; i<3; i++){
        dropped_assignments.push_back(0);
    }

    vector<int> max_scores;
    num_labs -= dropped_labs;
    num_quizzes -= dropped_quizzes;
    for(i=0;i<num_labs;i++){
        max_scores.push_back(MAX_LAB_SCORE);
    }for(i=0;i<num_quizzes;i++){
        max_scores.push_back(MAX_QUIZ_SCORE);
    }for(i=0;i<num_midterms;i++){
        max_scores.push_back(MAX_MIDTERM_SCORE);
    }
    max_scores.push_back(MAX_PROJECT_SCORE);
    max_scores.push_back(MAX_FINAL_EXAM_SCORE);

    vector<int> user_scores;
    for(i=0;i<num_labs;i++){
        user_scores.push_back(generateScores(MAX_LAB_SCORE));
    } for(i=0;i<num_quizzes;i++){
        user_scores.push_back(generateScores(MAX_QUIZ_SCORE));
    } for(i=0;i<num_midterms;i++){
        user_scores.push_back(generateScores(MAX_MIDTERM_SCORE));
    }
    user_scores.push_back(generateScores(MAX_PROJECT_SCORE));
    user_scores.push_back(generateScores(MAX_FINAL_EXAM_SCORE));
    
    student.push_back(num_assignments);
    student.push_back(dropped_assignments);
    student.push_back(max_scores);
    student.push_back(user_scores);

    for (const auto& row : student){
        for(int element : row){
            cout << element << " ";
        } 
    cout << endl;
    }
}