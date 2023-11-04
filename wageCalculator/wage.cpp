/*
Given input from the user, this program calculates gross pay, amount of deductions, and net pay based on hours worked and hourly wage.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int hours;
    double gross_pay, hourly_wage, amount_deduction, net_pay;

    cout << "How many hours did you work?\n";
    cin >> hours;

    if(hours < 0){
        cout << "You have entered a negative number for worked hour.\n";
        cout << "Terminating the program.\n";
        return 0;
    }
    cout << "How much do you make per hour?\n";
    cin >> hourly_wage;
    while (hourly_wage < 0){
        cout << "Your hourly wage is less than 0. Please try again:\n";
        cin >> hourly_wage;
    }
    if(hours <= 40) gross_pay = hours*hourly_wage;
    else gross_pay = 40*hourly_wage + (hours-40)*hourly_wage*1.5;

    if (gross_pay <= 100.00) amount_deduction = gross_pay*0.02;
    else if (gross_pay > 100.00 && gross_pay <= 500.00) amount_deduction = gross_pay*0.05;
    else amount_deduction = gross_pay*0.09;

    net_pay = gross_pay - amount_deduction;

    cout << fixed << setprecision(2);
    cout << "Wage Calculator\n";
    cout << "Hours Worked" << setw(22) << hours << endl;
    cout << "Hourly Wage" << setw(23) << hourly_wage << endl;
    cout << setfill('-') << setw(34) << "-" << endl;
    cout << setfill(' ');
    cout << "Gross Pay" << setw (25) << gross_pay << endl;
    cout << "Deductions" << setw (24) << amount_deduction << endl;
    cout << setfill('-') << setw(34) << "-" << endl;
    cout << setfill(' ');
    cout << "Net Pay" << setw (27) << net_pay << endl;

    return 0;
}
