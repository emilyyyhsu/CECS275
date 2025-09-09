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
    double standardDeduction, taxableIncome, userIncome, income, taxAmount;   
    // Define variables as string datatype 
    string userStatus, filingStatus;    

    // Prompt user to enter gross income in dollars and store in variable userIncome 
    cout << "Enter the gross income in dollars:\n";
    cin >> userIncome;
    // Prompt user to enter filing status and store in variable userStatus
    cout << "Enter the filing status:\nS - Single\nH - Head of Household\nJ - Married Filing Jointly\nP - Married Filing Separately\n";
    cin >> userStatus;
    userStatus = userStatus;

    if (userStatus == "S"){
        filingStatus = "S - Single";
        standardDeduction = 14600;
        taxAmount = TEN_PERCENT*11600;
        income = userIncome - standardDeduction - 11600;
        if ((0 < income) && (income <= 35550)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*35550;
            income -= 35550;
            if ((0 < income) && (income <= 53375)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*53375;
                income -= 53375;
                if ((0 < income) && (income <= 91425)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*91425;
                    income -= 91425;
                    if((0 < income) && (income <= 51775)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*51775;
                        income -= 51775;
                        if((0 < income) && (income <= 365625)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*365625;
                            income -= 365625;
                            if(income >= 0){
                                taxAmount += THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    } else if (userStatus == "H"){
        filingStatus = "H - Head of Household";
        standardDeduction = 23625;
        taxAmount = TEN_PERCENT* 16550;
        income = userIncome - standardDeduction - 16550;
        if ((0 < income) && (income <= 46550)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*46550;
            income -= 46550;
            if ((0 < income) && (income <= 37400)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*37400;
                income -= 37400;
                if ((0 < income) && (income <= 91450)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*91450;
                    income -= 91450;
                    if ((0 < income) && (income <= 51750)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*51750;
                        income -= 51750;
                        if ((0 < income) && (income <= 365650)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*365650;
                            income -= 365650;
                            if(income > 0){
                                taxAmount = taxAmount + THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    } else if (userStatus == "J"){
        filingStatus = "J - Married Filing Jointly";
        standardDeduction = 29200;
        taxAmount = TEN_PERCENT*23200;
        income = userIncome - standardDeduction - 23200;
            if ((0 < income) && (income <= 71100)){
                taxAmount += TWELVE_PERCENT*71100;
                income -= 71100;
                if ((0 < income) && (income <= 106750)){
                    taxAmount += TWENTY_TWO_PERCENT*income;
                } else {
                    taxAmount += TWENTY_TWO_PERCENT*106750;
                    income -= 106750;
                    if ((0 < income) && (income <= 182850)){
                        taxAmount += TWENTY_FOUR_PERCENT*income;
                    } else {
                        taxAmount += TWENTY_FOUR_PERCENT*182850;
                        income -= 182850;
                        if((0 < income) && (income <= 103550)){
                            taxAmount += THIRTY_TWO_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_TWO_PERCENT*103550;
                            income -= 103550;
                            if((0 < income) && (income <= 243750)){
                                taxAmount += THIRTY_FIVE_PERCENT*income;
                            } else {
                                taxAmount += THIRTY_FIVE_PERCENT*243750;
                                income -= 243750;
                                if(income > 0){
                                    taxAmount += THIRTY_SEVEN_PERCENT*income;
                                }
                            }
                        }
                    }
                }
            }
        } else if (userStatus == "P"){
        filingStatus = "P - Married Filing Separately";
        standardDeduction = 15750;
        taxAmount = TEN_PERCENT*11600;
        income = userIncome - standardDeduction - 11600;
        if ((0 < income) && (income <= 35550)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*35550;
            income -= 35550;
            if ((0 < income) && (income <= 53375)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*53375;
                income -= 53375;
                if ((0 < income) && (income <= 91425)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*91425;
                    income -= 91425;
                    if((0 < income) && (income <= 51775)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*51775;
                        income -= 51775;
                        if((0 < income) && (income <= 121875)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*121875;
                            income -= 121875;
                            if(income > 0){
                                taxAmount = taxAmount + THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    }
    if (userIncome < standardDeduction){
            standardDeduction = 0;
            taxAmount = TEN_PERCENT*userIncome;
    }

    // Calculate taxable income
    taxableIncome = userIncome - standardDeduction;

    cout << "Gross income: $" << fixed << setprecision(2) << userIncome << endl 
    << "Filing status: " << filingStatus 
    << "\nStandard deduction: $" << fixed << setprecision(2) << standardDeduction 
    << "\nTaxable income: $" << taxableIncome 
    << "\nTax amount: $" << taxAmount << endl;

}