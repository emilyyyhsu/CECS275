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
    const double TEN_PERCENT = 0.10,                // Multiplier for 10%
    TWELVE_PERCENT = 0.12,                          // Multiplier for 12%
    TWENTY_TWO_PERCENT = 0.22,                      // Multiplier for 22%
    TWENTY_FOUR_PERCENT = 0.24,                     // Multiplier for 24%
    THIRTY_TWO_PERCENT = 0.32,                      // Multiplier for 32%
    THIRTY_FIVE_PERCENT = 0.35,                     // Multiplier for 35%
    THIRTY_SEVEN_PERCENT = 0.37;                    // Multiplier for 37%
    const long STANDARD_DEDUCTION_SINGLE = 14600,   // Standard deduction for a single household
    SINGLE_BRACKET1 = 11600,                        // 10% bracket for single
    SINGLE_BRACKET2 = 35550,                        // 12% bracket for single
    SINGLE_BRACKET3 = 53375,                        // 22% bracket for single
    SINGLE_BRACKET4 = 91425,                        // 24% bracket for single
    SINGLE_BRACKET5 = 51775,                        // 32% bracket for single
    SINGLE_BRACKET6 = 365625,                       // 35% bracket for single
    STANDARD_DEDUCTION_HOUSEHOLD = 23625,           // Standard deduction for head of household
    HOUSEHOLD_BRACKET1 = 16550,                     // 10% bracket for head of household
    HOUSEHOLD_BRACKET2 = 46550,                     // 12% bracket for head of household
    HOUSEHOLD_BRACKET3 = 37400,                     // 22% bracket for head of household
    HOUSEHOLD_BRACKET4 = 91450,                     // 24% bracket for head of household
    HOUSEHOLD_BRACKET5 = 51750,                     // 32% bracket for head of household
    HOUSEHOLD_BRACKET6 = 365650,                    // 35% bracket for head of household
    STANDARD_DEDUCTION_JOINT = 29200,               // Standard deduction for married filing jointly
    JOINT_BRACKET1 = 23200,                         // 10% bracket for married filing jointly
    JOINT_BRACKET2 = 71100,                         // 12% bracket for married filing jointly
    JOINT_BRACKET3 = 106750,                        // 22% bracket for married filing jointly
    JOINT_BRACKET4 = 182850,                        // 24% bracket for married filing jointly
    JOINT_BRACKET5 = 103550,                        // 32% bracket for married filing jointly
    JOINT_BRACKET6 = 243750,                        // 35% bracket for married filing jointly
    STANDARD_DEDUCTION_SEPARATE = 15750,            // Standard deduction for married filing separately
    SEPARATE_BRACKET1 = 11600,                      // 10% bracket for married filing separately
    SEPARATE_BRACKET2 = 35550,                      // 12% bracket for married filing separately
    SEPARATE_BRACKET3 = 53375,                      // 22% bracket for married filing separately
    SEPARATE_BRACKET4 = 91425,                      // 24% bracket for married filing separately
    SEPARATE_BRACKET5 = 51775,                      // 32% bracket for married filing separately
    SEPARATE_BRACKET6 = 121875;                     // 35% bracket for married filing separately

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

    // Calculate the tax amount for Single
    if (userStatus == "S"){
        filingStatus = "S - Single";
        standardDeduction = STANDARD_DEDUCTION_SINGLE;
        taxAmount = TEN_PERCENT*SINGLE_BRACKET1;
        income = userIncome - standardDeduction - SINGLE_BRACKET1;
        if ((0 < income) && (income <= SINGLE_BRACKET2)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*SINGLE_BRACKET2;
            income -= SINGLE_BRACKET2;
            if ((0 < income) && (income <= SINGLE_BRACKET3)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*SINGLE_BRACKET3;
                income -= SINGLE_BRACKET3;
                if ((0 < income) && (income <= SINGLE_BRACKET4)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*SINGLE_BRACKET4;
                    income -= SINGLE_BRACKET4;
                    if((0 < income) && (income <= SINGLE_BRACKET5)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*SINGLE_BRACKET5;
                        income -= SINGLE_BRACKET5;
                        if((0 < income) && (income <= SINGLE_BRACKET6)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*SINGLE_BRACKET6;
                            income -= SINGLE_BRACKET6;
                            if(income >= 0){
                                taxAmount += THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    // Calculate the tax amount for Head of Household
    } else if (userStatus == "H"){
        filingStatus = "H - Head of Household";
        standardDeduction = STANDARD_DEDUCTION_HOUSEHOLD;
        taxAmount = TEN_PERCENT* HOUSEHOLD_BRACKET1;
        income = userIncome - standardDeduction - HOUSEHOLD_BRACKET1;
        if ((0 < income) && (income <= HOUSEHOLD_BRACKET2)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*HOUSEHOLD_BRACKET2;
            income -= HOUSEHOLD_BRACKET2;
            if ((0 < income) && (income <= HOUSEHOLD_BRACKET3)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*HOUSEHOLD_BRACKET3;
                income -= HOUSEHOLD_BRACKET3;
                if ((0 < income) && (income <= HOUSEHOLD_BRACKET4)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*HOUSEHOLD_BRACKET4;
                    income -= HOUSEHOLD_BRACKET4;
                    if ((0 < income) && (income <= HOUSEHOLD_BRACKET5)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*HOUSEHOLD_BRACKET5;
                        income -= HOUSEHOLD_BRACKET5;
                        if ((0 < income) && (income <= HOUSEHOLD_BRACKET6)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*HOUSEHOLD_BRACKET6;
                            income -= HOUSEHOLD_BRACKET6;
                            if(income > 0){
                                taxAmount = taxAmount + THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    // Calculate the tax amount for Married Filing Jointly
    } else if (userStatus == "J"){
        filingStatus = "J - Married Filing Jointly";
        standardDeduction = STANDARD_DEDUCTION_JOINT;
        taxAmount = TEN_PERCENT*JOINT_BRACKET1;
        income = userIncome - standardDeduction - JOINT_BRACKET1;
            if ((0 < income) && (income <= JOINT_BRACKET2)){
                taxAmount += TWELVE_PERCENT*JOINT_BRACKET2;
                income -= JOINT_BRACKET2;
                if ((0 < income) && (income <= JOINT_BRACKET3)){
                    taxAmount += TWENTY_TWO_PERCENT*income;
                } else {
                    taxAmount += TWENTY_TWO_PERCENT*JOINT_BRACKET3;
                    income -= JOINT_BRACKET3;
                    if ((0 < income) && (income <= JOINT_BRACKET4)){
                        taxAmount += TWENTY_FOUR_PERCENT*income;
                    } else {
                        taxAmount += TWENTY_FOUR_PERCENT*JOINT_BRACKET4;
                        income -= JOINT_BRACKET4;
                        if((0 < income) && (income <= JOINT_BRACKET5)){
                            taxAmount += THIRTY_TWO_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_TWO_PERCENT*JOINT_BRACKET5;
                            income -= JOINT_BRACKET5;
                            if((0 < income) && (income <= JOINT_BRACKET6)){
                                taxAmount += THIRTY_FIVE_PERCENT*income;
                            } else {
                                taxAmount += THIRTY_FIVE_PERCENT*JOINT_BRACKET6;
                                income -= JOINT_BRACKET6;
                                if(income > 0){
                                    taxAmount += THIRTY_SEVEN_PERCENT*income;
                                }
                            }
                        }
                    }
                }
            }
        // Calculate tax amount for Married Filing Separately
        } else if (userStatus == "P"){
        filingStatus = "P - Married Filing Separately";
        standardDeduction = STANDARD_DEDUCTION_SEPARATE;
        taxAmount = TEN_PERCENT*SEPARATE_BRACKET1;
        income = userIncome - standardDeduction - SEPARATE_BRACKET1;
        if ((0 < income) && (income <= SEPARATE_BRACKET2)){
            taxAmount += TWELVE_PERCENT*income;
        } else {
            taxAmount += TWELVE_PERCENT*SEPARATE_BRACKET2;
            income -= SEPARATE_BRACKET2;
            if ((0 < income) && (income <= SEPARATE_BRACKET3)){
                taxAmount += TWENTY_TWO_PERCENT*income;
            } else {
                taxAmount += TWENTY_TWO_PERCENT*SEPARATE_BRACKET3;
                income -= SEPARATE_BRACKET3;
                if ((0 < income) && (income <= SEPARATE_BRACKET4)){
                    taxAmount += TWENTY_FOUR_PERCENT*income;
                } else {
                    taxAmount += TWENTY_FOUR_PERCENT*SEPARATE_BRACKET4;
                    income -= SEPARATE_BRACKET4;
                    if((0 < income) && (income <= SEPARATE_BRACKET5)){
                        taxAmount += THIRTY_TWO_PERCENT*income;
                    } else {
                        taxAmount += THIRTY_TWO_PERCENT*SEPARATE_BRACKET5;
                        income -= SEPARATE_BRACKET5;
                        if((0 < income) && (income <= SEPARATE_BRACKET6)){
                            taxAmount += THIRTY_FIVE_PERCENT*income;
                        } else {
                            taxAmount += THIRTY_FIVE_PERCENT*SEPARATE_BRACKET6;
                            income -= SEPARATE_BRACKET6;
                            if(income > 0){
                                taxAmount = taxAmount + THIRTY_SEVEN_PERCENT*income;
                            }
                        }
                    }
                }
            }
        }
    // Calculate tax amount if user's gross income is less than standard deduction
    }if (userIncome < standardDeduction){
            standardDeduction = 0;
            taxAmount = TEN_PERCENT*userIncome;
    }
    // Calculate taxable income
    taxableIncome = userIncome - standardDeduction;

    // Output message displaying gross income, filing status, standard deduction, taxable income, and tax amount
    cout << "Gross income: $" << fixed << setprecision(2) << userIncome << endl     // use fixed and setprecision to show 2 decimal points
    << "Filing status: " << filingStatus 
    << "\nStandard deduction: $" << fixed << setprecision(2) << standardDeduction 
    << "\nTaxable income: $" << taxableIncome 
    << "\nTax amount: $" << taxAmount << endl;

}