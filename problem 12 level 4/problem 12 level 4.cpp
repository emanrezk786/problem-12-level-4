#include <iostream>

using namespace std;

struct SDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;


    int NumberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

SDate DateAddDays(short Days , SDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;

}

short ReadDay()
{
    short Day;
    cout << "\n Please Enter a Day ?";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\n Please Enter a Month ?";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\n Please Enter a Year ?";
    cin >> Year;
    return Year;
}

SDate ReadFullDate()
{
    SDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "\n How Many Days To Add ? ";
    cin >> Days;
    return Days;
}

int main()
{
    SDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Days, Date);
    cout << "\n Date After Adding [" << Days << "] Days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    cout << endl;
    return 0;

}



