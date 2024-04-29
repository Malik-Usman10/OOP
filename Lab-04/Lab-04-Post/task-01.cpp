#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Time 
{
public:
    Time(int hour, int minute) : hours(hour), minutes(minute) 
    {
        cout << "Time constructor for " << hours << ":" << minutes << endl;
    }

    ~Time() 
    {
        cout << "Time destructor for " << hours << ":" << minutes << endl;
    }

    void displayTime() const 
    { 
        cout << hours << ":" << minutes << endl;
    }

private:
    int hours;
    int minutes;
};

class Date 
{
public:
    
    Date(int day, int month, int year) : day(day), month(month), year(year) 
    {
        cout << "Date constructor for " << day << "/" << month << "/" << year << endl;
    }

    ~Date() 
    {
        cout << "Date destructor for " << day << "/" << month << "/" << year << endl;
    }
    void displayDate() const {  
        cout << day << "/" << month << "/" << year;
    }

private:
    int day;
    int month;
    int year;
};


class Event 
{
public:
    Event(string name, const Time& time, const Date& date) : eventName(name), eventTime(time), eventDate(date) 
    {
        cout << "Event constructor for " << eventName << endl;
    }

    ~Event() 
    {
        cout << "Event destructor for " << eventName << endl;
    }

  void printEventData(string searchCriteria) const 
  {
        if (getEventName() == searchCriteria) 
        { 
            cout << eventName << " occurs on ";
            eventDate.displayDate();
            cout << " at ";
            eventTime.displayTime();
            cout << endl;
        }
    }
    string getEventName() const { return eventName; }

private:
    string eventName;
    Time eventTime;
    Date eventDate; 
};

int main() 
{
    string name;
     int hour, minute, day, month, year;
    vector<Event> events;

    while (true) 
    {
        int choice;
        do 
        {
            cout << "\nChoose an action:\n";
            cout << "1: Add another event\n";
            cout << "2: Display event detail\n";
            cout << "3: Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        switch (choice) 
        {
            case 1:
                cout << "Enter event name ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter event time (hour minute): ";
                cin >> hour >> minute;

                cout << "Enter event date (day month year): ";
                cin >> day >> month >> year;
                events.push_back(Event(name, Time(hour, minute), Date(day, month, year)));
                break;
            case 2: 
            {
                string searchCriteria;
                cout << "Enter event name: ";         // not able to make search with date.
                cin.ignore();
                getline(cin, searchCriteria);

                bool found = false;  
                for (const Event& event : events) 
                {
                    if (event.getEventName() == searchCriteria)
                    {
                        event.printEventData(searchCriteria);
                        found = true;
                        break;
                    }
                }
                if (!found) 
                {
                    cout << "No Event with this Name" << endl;
                }
                break;
            }
            case 3:
                return 0;
        }
    }
    return 0;
}

