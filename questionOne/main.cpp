//---------------------------------------------------------------------
//
// Name:    Muhammed Berkay Ermiş
//
// Course:  Programming for Engineering, Fall, 2020
//
// Purpose: General description of what the program does.  This program
//          should take the year as an input and it should print the
//          12 months calendar as an output.
//
//---------------------------------------------------------------------

#include <iostream>
#include<iomanip>

using namespace std;

//---------------------------------------------------------------------
// Function Prototypes
// ---------------------------------------------------------------------
bool leapOrNot(int);
string monthName(int);
int numberOfDaysInCalendar (int , int );
int dayNumber(int);
void printCalendar(int);

//---------------------------------------------------------------------
// Main Function
// ---------------------------------------------------------------------
int main() {

int year;
cout<<"Enter a year in format yyyy: "<<endl;
cin>>year;

printCalendar(year);
return 0;
}


//---------------------------------------------------------------------
// dayNumber function returns the first day of the given year
// params:(year)
// year parameter is the parameter which is taken by user
// ---------------------------------------------------------------------
int dayNumber(int year)
{
    // Algorithm which shows the first day of a year
    int days = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return days; //returns the days
}

//---------------------------------------------------------------------
// leapOrNot function checks the given year is whether a leap year or not with respect to the conditions
// params:(year)
// year parameter is the parameter which is taken by user.
// ---------------------------------------------------------------------
bool leapOrNot(int year){
    if ((year%4 == 0 && year%100 != 0) || (year % 400 == 0)) return true;
    else return false;
}

//---------------------------------------------------------------------
// monthName function keeps the 12 month names and returns the month name according to the parameter
// params:(monthNumber)
// monthNumber is a number between 1 and 12(inclusive)
// ---------------------------------------------------------------------
string monthName(int monthNumber)
{
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };

    return (months[monthNumber]);
}


//---------------------------------------------------------------------
// numberOfDaysInCalendar function returns the number of days for the given month and year
// params:(monthNumber,year)
// monthNumber is a number between 1 and 12(inclusive) and year is taken by user
// ---------------------------------------------------------------------
int numberOfDaysInCalendar (int monthNumber, int year)
{
    // January
    if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4 || monthNumber == 6 || monthNumber == 7 ||
            monthNumber == 9 || monthNumber == 11)
        return (31);

    // February
    if (monthNumber == 1)
    {
        if (leapOrNot(year))
            return (29);
        else
            return (28);
    }
    else
        return (30);

}

//---------------------------------------------------------------------
// printCalendar function prints the calendar with respect to the year
// params:(year)
// year is taken by user
// ---------------------------------------------------------------------
void printCalendar(int year){

    int currentDay = dayNumber(year);
    for(int i=0; i<12; i++){
        int totalNumOfDays = numberOfDaysInCalendar(i,year);
        cout<<endl<<"           "<<monthName(i)<<" "<<year<<endl;
        cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        cout<<" ____________\n";
        int tab;
        for (tab = 0; tab < currentDay; tab++){
            cout<<"     ";
        }
        for(int numDays=1; numDays<=totalNumOfDays; numDays++){
            cout<<setw(5)<<numDays;
            if (++tab > 6)
            {
                tab = 0;
                cout<<endl;
            }
        }
        if (tab) cout<<endl;
        currentDay = tab;
    }
}