#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Job 
{
private: 
    int deadline;

public: 
    Job(int dead1) : deadline(dead1){}
    int getDeadline()
    const 
    {
        return deadline;
        
    }
    void setDeadline(int dead1)
    {
        deadline = dead1;
    }

};

int main()
{
    vector<Job> jobs = 
    {
        Job(5),
        Job(2),
        Job(4),
        Job(8),
        Job(1),
        Job(3),
        Job(6),
        Job(7),
        Job(10),
        Job(11),
        Job(9),


    };
    cout << "JObs with deadlines:" << endl;
    for (const auto& job: jobs) 
    {
        cout << "Deadline: " << job.getDeadline() << endl;        
    }
    
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b)
    {
        return a.getDeadline() < b.getDeadline();
    });

    cout << "\n Two earlist jobs: " << endl;
    cout << "1. Deaddline: "<< jobs[0].getDeadline() << endl;
    cout << "1. Deaddline: "<< jobs[1].getDeadline() << endl;
    return 0;
}

