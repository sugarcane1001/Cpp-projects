/*
Given any date from year 0000 to 9999, this program will tell which day was it.
*/

#include <iostream>
using namespace std;

int January = 1;
int February = 2;
int March = 3;
int April = 4;
int May = 5;
int June = 6;
int July = 7;
int August = 8;
int September = 9;
int October = 10;
int November = 11;
int December = 12;

bool isLeapYear(int year){
    if (year%400==0 || (year%4==0 && year%100!=0)) return true;
    else return false;
}

int getCenturyValue(int year){
    int century, remainder;
    century = year/100;
    remainder = (century%4);
    return 2*(3-remainder);
}

int getYearValue(int year){
    int yearvalue, last2digit;
    last2digit = year%100;
    yearvalue = (last2digit)/4;
    return (last2digit + yearvalue);
}

int getMonthValue(int month, int year){
    int result;
    if (month==January){
        if (isLeapYear(year)) result=6;
        else result=0;
    }
    else if (month== February){
        if (isLeapYear(year)) result=2;
        else result=3;
    }
    else if (month==March) result=3;
    else if (month==April) result=6;
    else if (month==May) result=1;
    else if (month==June) result=4;
    else if (month==July) result=6;
    else if (month==August) result=2;
    else if (month==September) result=5;
    else if (month==October) result=0;
    else if (month==November) result=3;
    else if (month==December) result=5;
    return result;
}

int main(){
    int month, day, year;
    cout << "Enter month (1-12):" << endl;
    cin >> month;
    cout << "Enter day (1-31):" << endl;
    cin >> day;
    cout << "Enter year (0000-9999):" << endl;
    cin >> year;

    int total = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue (year));
    int dayOfWeek = total%7;

    cout << month << "/" << day << "/" << year << " is a ";
    if (dayOfWeek==0) cout << "Sunday";
    else if (dayOfWeek==1) cout << "Monday";
    else if (dayOfWeek==2) cout << "Tuesday";
    else if (dayOfWeek==3) cout << "Wednesday";
    else if (dayOfWeek==4) cout << "Thursday";
    else if (dayOfWeek==5) cout << "Friday";
    else if (dayOfWeek==6) cout << "Saturday";
    cout << endl;
    
    return 0;
}
