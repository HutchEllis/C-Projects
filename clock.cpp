

#include <iostream>
using namespace std;
class militaryTime;

enum AMPM
{
    AM,
    PM
} ampm;

class Time
{
public:
    int hour;
    int min;
    int sec;

    virtual void addHour() = 0;
    virtual void addMin() = 0;
    virtual void addSec() = 0;
};

class standardTime : public Time
{
public:
    standardTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
        ampm = AM;
    }

    void addHour()
    {
        if (hour == 12)
        {
            hour = 1;
        }
        else
        {
            hour += 1;
        }
        if (hour == 12)
        {
            ampm = ampm == AM ? PM : AM;
        }
    }
    void addMin()
    {
        if (min == 59)
        {
            min = 0;
            addHour();
        }
        else
        {
            min += 1;
        }
    }
    void addSec()
    {
        if (sec == 59)
        {
            sec = 0;
            addMin();
        }
        else
        {
            sec += 1;
        }
    }

    friend void displayTime(const standardTime &, const militaryTime &);
};

class militaryTime : public Time
{
public:
    militaryTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }

    void addHour()
    {
        if (hour == 23)
        {
            hour = 0;
        }
        else
        {
            hour += 1;
        }
    }
    void addMin()
    {
        if (min == 59)
        {
            min = 0;
            addHour();
        }
        else
        {
            min += 1;
        }
    }
    void addSec()
    {
        if (sec == 59)
        {
            sec = 0;
            addMin();
        }
        else
        {
            sec += 1;
        }
    }

    friend void displayTime(const standardTime &, const militaryTime &);
};
// Displays the both clocks
void displayTime(const standardTime &clock12, const militaryTime &clock24)
{
    cout << "***************************   ***************************\n";
    cout << "*      12-HOUR CLOCK      *   *      24-HOUR CLOCK      *\n";
    cout << "*      ";
    if (clock12.hour < 10)
        cout << "0";
    cout << clock12.hour << ":";
    if (clock12.min < 10)
        cout << "0";
    cout << clock12.min << ":";
    if (clock12.sec < 10)
        cout << "0";
    cout << clock12.sec;
    if (ampm == AM)
        cout << " A M";
    else
        cout << " P M";
    cout << "       *   *      ";
    if (clock24.hour < 10)
        cout << "0";
    cout << clock24.hour << ":";
    if (clock24.min < 10)
        cout << "0";
    cout << clock24.min << ":";
    if (clock24.sec < 10)
        cout << "0";
    cout << clock24.sec;
    cout << "           *\n";
    cout << "***************************   ***************************\n\n";
}

int main()
{
    standardTime time_12_Clock(11, 11, 11);
    militaryTime time_24_Clock(11, 11, 11);
    displayTime(time_12_Clock, time_24_Clock);
    while (true)
    {
        // prints menu to user
        cout << "**************************\n";
        cout << "* 1 - Add One Hour       *\n";
        cout << "* 2 - Add One Minute     *\n";
        ;
        cout << "* 3 - Add One Second     *\n";
        cout << "* 4 - Exit Program       *\n";
        cout << "**************************\n";

        int choice;
        cin >> choice;

        switch (choice)
        {

        // adds an hour
        case 1:
            time_12_Clock.addHour();
            time_24_Clock.addHour();
            displayTime(time_12_Clock, time_24_Clock);
            break;

        // adds a minute
        case 2:
            time_12_Clock.addMin();
            time_24_Clock.addMin();
            displayTime(time_12_Clock, time_24_Clock);
            break;

        // adds a second
        case 3:
            time_12_Clock.addSec();
            time_24_Clock.addSec();
            displayTime(time_12_Clock, time_24_Clock);
            break;

        // exits program
        case 4:
            exit(1);
        }
    }
}
