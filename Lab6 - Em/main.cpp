/*
 * This program calculates your grades
 * @author: Natasha Kho
 * @author: Emily Hsu
 * Created on: 2025-09-11
 * Last Modified: 2025-09-15
 * Reference: 
*/
#include "calcScores.h"

int main (void){
    fstream inFile;
    int userSelect;
    string fileName;
    inFile.open("text.txt");
    printMenu(userSelect);
    generateReport(fileName);
}
