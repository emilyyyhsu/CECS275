#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#include "calcScores.h"

int main(void){
    fstream input;
    input.open("scores.txt");
    printResults(generateGradeReport(input));
}