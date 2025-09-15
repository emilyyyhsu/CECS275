#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

const int QUIZ_AMOUNT = 7;
const int LAB_AMOUNT = 20;
const int MIDTERM_AMOUNT = 2;
const int PROJECT_AMOUNT = 1;
const int FINAL_EXAM_AMOUNT = 1;
const int MAX_QUIZ_SCORE = 10;
const int MAX_LAB_SCORE = 5;
const int MAX_MIDTERM_SCORE = 50;
const int MAX_PROJECT_SCORE = 100;
const int MAX_FINAL_EXAM_SCORE = 100;

void generateScores(std::ofstream& out, int amount); 
void generateMaxScores(std::ofstream& out, int maxScore, int amount);