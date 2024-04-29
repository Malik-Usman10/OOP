#include <iostream>
using namespace std;

class Job
{
private:
    int deadline;

public:
    Job(int deadl)
    {
        deadline = deadl;
    }

    int getDeadline()
    {
        return deadline;
    }
};

int main()
{

    Job job1(89);
    Job job2(71);
    Job job3(66);
    Job job4(78);
    Job job5(94);
    Job job6(41);
    Job job7(64);
    Job job8(12);
    Job job9(67);
    Job job10(10);

    Job jobs[] = {job1, job2, job3, job4, job5, job6, job7, job8, job9, job10};

    int earliest = 100;
    int secondEarliest = 100;
    for (int i = 0; i < 10; ++i)
    {
        int currentDeadline = jobs[i].getDeadline();
        if (currentDeadline < earliest)
        {
            secondEarliest = earliest;
            earliest = currentDeadline;
        }
        else if (currentDeadline < secondEarliest)
        {
            secondEarliest = currentDeadline;
        }
    }

    cout << "Earliest Deadlines: " << earliest << endl;
    cout << "Second Earliest Deadlines: " << secondEarliest << endl;

    return 0;
}
