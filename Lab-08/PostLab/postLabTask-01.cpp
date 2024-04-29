#include <iostream>
using namespace std;

class Time {
private:
    int second;
    int minute;
    int hour;

public:
    Time() : second(0), minute(0), hour(0) {}
    Time(int h, int m, int s) : second(s), minute(m), hour(h) {}
    Time(const Time& copy) : second(copy.second), minute(copy.minute), hour(copy.hour) {}
    ~Time() {}

    void Display() const 
    {
        cout << hour << ":" << minute << ":" << second;
    }

    Time operator+(const Time& copy) const 
    {
        Time timeAdd;
        timeAdd.second = second + copy.second;
        timeAdd.minute = minute + copy.minute;
        timeAdd.hour = hour + copy.hour;

        if (timeAdd.second >= 60) 
        {
            timeAdd.second -= 60;
            timeAdd.minute++;
        }
        if (timeAdd.minute >= 60) 
        {
            timeAdd.minute -= 60;
            timeAdd.hour++;
        }
        if (timeAdd.hour >= 24) 
        {
            timeAdd.hour -= 24;
        }
        return timeAdd;
    }

    Time operator-(const Time& copy) const 
    {
        Time timeSub;
        timeSub.second = second - copy.second;
        timeSub.minute = minute - copy.minute;
        timeSub.hour = hour - copy.hour;

        if (timeSub.second < 0) 
        {
            timeSub.second += 60;
            timeSub.minute--;
        }
        if (timeSub.minute < 0) 
        {
            timeSub.minute += 60;
            timeSub.hour--;
        }
        if (timeSub.hour < 0) 
        {
            timeSub.hour += 24;
        }
        return timeSub;
    }

    friend ostream& operator<<(ostream& os, const Time& time) 
    {
        os << time.hour << ":" << time.minute << ":" << time.second;
        return os;
    }

    friend istream& operator>>(istream& is, Time& time) 
    {
        is >> time.hour >> time.minute >> time.second;
        return is;
    }

};


class Date {
private:
    int day;
    int mounth;
    int year;
    Time time;

public:
    Date() : day(1), mounth(1), year(2000), time() {}
    Date(int d, int m, int y, const Time& t) : day(d), mounth(m), year(y), time(t) {}
    Date(const Date& copy) : day(copy.day), mounth(copy.mounth), year(copy.year), time(copy.time) {}
    ~Date() {}

    void Display() const 
    {
        cout << time << ", " << day << "-" << mounth << "-" << year;
    }

    Date operator+(const Date& copy) const 
    {
        Date dateAdd;
        dateAdd.day = day + copy.day;
        dateAdd.mounth = mounth + copy.mounth;
        dateAdd.year = year + copy.year;
        dateAdd.time = time + copy.time;
        if (dateAdd.day > 30) 
        {
            dateAdd.day -= 30;
            dateAdd.mounth++;
        }
        if (dateAdd.mounth > 12 ) 
        {
            dateAdd.mounth -= 12;
            dateAdd.year++;
        }
        return dateAdd;
    }

    Date operator-(const Date& copy) const 
    {
        Date dateSub;
        dateSub.day = day - copy.day;
        dateSub.mounth = mounth - copy.mounth;
        dateSub.year = year - copy.year;
        dateSub.time = time - copy.time;
        if (dateSub.day < 0) 
        {
            dateSub.day +=30;
            dateSub.mounth--;
        }
        if (dateSub.mounth < 0) 
        {
            dateSub.mounth += 12;
            dateSub.year--;
        }
        if (dateSub.year < 0) 
        {
            dateSub.year -= dateSub.year;
        }
        return dateSub;
    }

    friend ostream& operator<<(ostream& os, const Date& date) 
    {
        os << date.time << ", " << date.day << "-" << date.mounth << "-" << date.year;
        return os;
    }

    friend istream& operator>>(istream& is, Date& date) 
    {
        is >> date.time >> date.day >> date.mounth >> date.year;
        return is;
    }
};

int main() 
{   int hourOne, hourTwo ,minutesOne, minutesTwo, secondsOne,secondsTwo, dayOne, dayTwo, mounthOne,mounthTwo, yearsOne, yearsTwo;
    cout << "Enter the TimeOne in Formate {hour minutes seconds}: ";
    cin >> hourOne >> minutesOne >> secondsOne;

    cout << "Enter the TimeTwo in Formate {hour minutes seconds}: ";
    cin >> hourTwo >> minutesTwo >> secondsTwo;

    Time timeOne(hourOne, minutesOne, secondsOne);
    Time timeTwo(hourTwo, minutesTwo, secondsTwo);

    cout << "Time 1: " << timeOne << endl;
    cout << "Time 2: " << timeTwo << endl;

    Time timeAddition = timeOne + timeTwo;
    cout << "TimeAddition: " << timeAddition << endl;

    Time timeSubtraction = timeOne - timeTwo;
    cout << "timeSubtraction: " << timeSubtraction << endl;

    cout << "-------------------------------------------------------\n";
    
    cout << "Enter the DateOne in Formate {Day Mounth Year}: ";
    cin >> dayOne >> mounthOne >> yearsOne;

    cout << "Enter the TimeTwo in Formate {Day Mounth Year}: ";
    cin >> dayTwo >> mounthTwo >> yearsTwo;

    Date dateOne(dayOne, mounthOne, yearsOne, timeOne);
    Date dateTwo(dayTwo, mounthTwo, yearsTwo, timeTwo);

    cout << "DateOne: " << dateOne << endl;
    cout << "DateTwo: " << dateTwo << endl;

    Date dateAddtion = dateOne + dateTwo;
    cout << "DateAddition: " << dateAddtion << endl;

    Date dateSubtration = dateOne - dateTwo;
    cout << "DateSubtraction: " << dateSubtration << endl;
}
