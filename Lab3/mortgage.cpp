/*
* This program calculates the monthly payment of a home mortgage
* @author Emily Hsu
* @author Natasha Kho
* Created on 9/2/2025
* Last modified 9/3/2025, 7:31 PM PST
*/

#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    const unsigned int MONTHS_PER_YEAR = 12;       // Number of months in a year
    const double PERCENTAGE_TO_DECIMAL = 0.01;     // Multiplier to convert a percentage to a decimal

    int annualInterestRate, loanTerm, totalNumberOfPayments;              // Define variables as integer datatype
    double userLoan, monthlyInterestRate, monthlyMortgagePayment, totalInterest;    // Define variables as double float datatype 

    // Prompt user to enter loan amount (principle) in dollars and store in variable userLoan
    std::cout << "How much money would you like to borrow?\n";
    std::cin >> userLoan;
    // Prompt user to enter the annual interest rate as a percentage and store in variable annualInterestRate
    std::cout << "What is the current market rate?\n";
    std::cin >> annualInterestRate;
    // Prompt user to enter the loan term in years and store in variable loanTerm
    std::cout << "How long would you like to pay off the loan?\n";
    std:: cin >> loanTerm;

    // Calculate the monthly interest rate 
    monthlyInterestRate = (annualInterestRate*PERCENTAGE_TO_DECIMAL)/MONTHS_PER_YEAR;
    // Calculate the monthly mortgage payment 
    monthlyMortgagePayment = userLoan * (monthlyInterestRate*std::pow(1+monthlyInterestRate, loanTerm * MONTHS_PER_YEAR))/(std::pow(1+monthlyInterestRate, loanTerm * MONTHS_PER_YEAR)-1);
    // Calculate the total interest paid 
    totalInterest = (monthlyMortgagePayment * MONTHS_PER_YEAR * loanTerm) - userLoan;
    // Calculate the total number of payments 
    totalNumberOfPayments = MONTHS_PER_YEAR * loanTerm;

    // Print statement displaying the loan amount, interest rate, loan term, total interest paid, 
    // total number of payments, and monthly payment
    std::cout << "Loan amount: $" << std::fixed << std::setprecision(2) << userLoan << endl     // Ensure that values are displayed in fixed-point notation
    << "Interest rate: " << annualInterestRate << "%" << endl                                         // and to 2 decimal points 
    << "Loan term: " << loanTerm << " years" << endl 
    << "Total interest paid: $" << std::fixed << std::setprecision(2) << totalInterest 
    << "\nTotal number of payments: " << totalNumberOfPayments
    << "\nMonthly payment: $" << monthlyMortgagePayment ;

    return 0;
}