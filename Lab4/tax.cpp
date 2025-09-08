/*
* This program calculates the amount of tax paid
* @author Emily Hsu
* @author Natasha Kho
* Created on 9/7/2025
* Last modified 9/8/2025, 10:52 AM PST
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    const double TEN_PERCENT = 0.10,    // Multiplier for 10%
    TWELVE_PERCENT = 0.12,              // Multiplier for 12%
    TWENTY_TWO_PERCENT = 0.22,          // Multiplier for 22%
    TWENTY_FOUR_PERCENT = 0.24,         // Multiplier for 24%
    THIRTY_TWO_PERCENT = 0.32,          // Multiplier for 32%
    THIRTY_FIVE_PERCENT = 0.35,         // Multiplier for 35%
    THIRTY_SEVEN_PERCENT = 0.37;        // Multiplier for 37%

    // Define variable as double float datatype
    double tax, userIncome, standardDeduction, taxableIncome, taxAmount;    
    // Define variables as string datatype 
    string userStatus, filingStatus;    

    // Prompt user to enter gross income in dollars and store in variable userIncome 
    cout << "Enter the gross income in dollars:\n";
    cin >> userIncome;
    // Prompt user to enter filing status and store in variable userStatus
    cout << "Enter the filing status:\n";
    cin >> userStatus;

    if (userStatus == "S"){
        filingStatus = "Single";
        standardDeduction = 14600;
        if (0 <= userIncome < 11601){
            tax = TEN_PERCENT;
        } else if (11601 <= userIncome < 47151){
            tax = TWELVE_PERCENT;
        } else if (47151 <= userIncome < 100526){
            tax = TWENTY_TWO_PERCENT;
        } else if (100526 <= userIncome < 191951){
            tax = TWENTY_FOUR_PERCENT;
        } else if (191951 <= userIncome < 243726){
            tax = THIRTY_TWO_PERCENT;
        } else if (243726 <= userIncome < 609351){
            tax = THIRTY_FIVE_PERCENT;
        } else if (userIncome >= 609351){
            tax = THIRTY_SEVEN_PERCENT;
        }
    } else if (userStatus == "H"){
        filingStatus = "Head of Household";
        standardDeduction = 21900;
        if (0 <= userIncome < 16551){
            tax = TEN_PERCENT;
        } else if (16551 <= userIncome < 63101){
            tax = TWELVE_PERCENT;
        } else if (63101 <= userIncome < 100501){
            tax = TWENTY_TWO_PERCENT;
        } else if (100501 <= userIncome < 191951){
            tax = TWENTY_FOUR_PERCENT;
        } else if (191951 <= userIncome < 243701){
            tax = THIRTY_TWO_PERCENT;
        } else if (243701 <= userIncome < 609351){
            tax = THIRTY_FIVE_PERCENT;
        } else if (userIncome >= 609351){
            tax = THIRTY_SEVEN_PERCENT;
        }
    } else if (userStatus == "J"){
        filingStatus = "Married Filing Jointly";
        standardDeduction = 29200;
        if (0 <= userIncome < 23201){
            tax = TEN_PERCENT;
        } else if (23201 <= userIncome < 94301){
            tax = TWELVE_PERCENT;
        } else if (94301 <= userIncome < 201051){
            tax = TWENTY_TWO_PERCENT;
        } else if (201051 <= userIncome < 383901){
            tax = TWENTY_FOUR_PERCENT;
        } else if (383901 <= userIncome < 487451){
            tax = THIRTY_TWO_PERCENT;
        } else if (userIncome >= 487451){
            tax = THIRTY_FIVE_PERCENT;
        }
    } else if (userStatus == "P"){
        filingStatus = "Married Filing Separately";
        standardDeduction = 14600;
        if (0 <= userIncome < 11601){
            tax = TEN_PERCENT;
        } else if (11601 <= userIncome < 47151){
            tax = TWELVE_PERCENT;
        } else if (47151 <= userIncome < 100526){
            tax = TWENTY_TWO_PERCENT;
        } else if (100526 <= userIncome < 191951){
            tax = TWENTY_FOUR_PERCENT;
        } else if (191951 <= userIncome < 243726){
            tax = THIRTY_TWO_PERCENT;
        } else if (243726 <= userIncome < 365601){
            tax = THIRTY_FIVE_PERCENT;
        } else if (userIncome >= 365601){
            tax = THIRTY_SEVEN_PERCENT;
        }
    }

    if (userIncome < standardDeduction){
        standardDeduction = 0;
    }
        
    // Calculate taxable income
    taxableIncome = userIncome - standardDeduction;
    // Calculate tax amount
    taxAmount = tax * taxableIncome;

    cout << "Gross income: $" << fixed << setprecision(2) << userIncome << endl 
    << "Filing status: " << filingStatus 
    << "\nStandard deduction: $" << fixed << setprecision(2) << standardDeduction 
    << "\nTaxable income: $" << taxableIncome 
    << "\nTax amount: $" << taxAmount << endl;

}