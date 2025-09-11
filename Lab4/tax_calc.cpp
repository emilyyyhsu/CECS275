#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    ifstream input;
    input.open("data.txt");
    char status;
    double grossIncome;

    while(input >> status >> grossIncome){
        cout << "S - Single" << endl;
        cout << "J - Married Jointly" << endl;
        cout << "Enter your filing status: " << status << endl;
        if (status == 'S' || status == 's'){
            cout << "Your filing status is: Single" << endl;\
            cout << "Your gross income is: $" << fixed << setprecision(2) << grossIncome << endl;
        } else if (status == 'J' || status == 'j'){
            cout << "Your filing status is: Married Jointly" << endl;
        } else {
            cout << "Invalid status" << endl;
        }
    }
    input.close();
    return 0;
}