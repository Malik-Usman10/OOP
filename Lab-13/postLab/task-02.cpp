#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Rubric 
{
private:
    int regno;
    double clearity;
    double completeness;
    double accuracy;
    double time;
    double total_marks;
public:
    void setRubricData() 
    {
        cout << "Enter regno: ";
        cin >> regno;
        cout << "Enter clearity (0-2): ";
        while (!(cin >> clearity) || clearity < 0 || clearity > 2) 
        {
            cout << "Invalid clearity. Please enter a value between 0 and 2: ";
            cin.clear();
        }
        cout << "Enter completeness (0-3): ";
        while (!(cin >> completeness) || completeness < 0 || completeness > 3) 
        {
            cout << "Invalid completeness. Please enter a value between 0 and 3: ";
            cin.clear();
        }
        cout << "Enter accuracy (0-3): ";
        while (!(cin >> accuracy) || accuracy < 0 || accuracy > 3) 
        {
            cout << "Invalid accuracy. Please enter a value between 0 and 3: ";
            cin.clear();
        }
        cout << "Enter time (0-2): ";
        while (!(cin >> time) || time < 0 || time > 2) 
        {
            cout << "Invalid time. Please enter a value between 0 and 2: ";
            cin.clear();
        }
        totalMarks = clearity + completeness + accuracy + time;
    }

    void printRubricData() 
    {
        cout << "Registration Number: " << regno << endl;
        cout << "Clearity: " << clearity << endl;
        cout << "Completeness: " << completeness << endl;
        cout << "Accuracy: " << accuracy << endl;
        cout << "Time: " << time << endl;
        cout << "Total Marks: " << total_marks << endl;
    }

    void writeToFile(ofstream& file) 
    {
        file << regno << " " << clearity << " " << completeness << " " << accuracy << " " << time << " " << total_marks << " \n";
    }

    void readFromFile(ifstream& file) 
    {
        file >> regno >> clearity >> completeness >> accuracy >> time >> total_marks;
    }
};

int main() 
{
    Rubric rubric1, rubric2, rubric3;

    rubric1.setRubricData();
    rubric2.setRubricData();
    rubric3.setRubricData();

    ofstream file("rubric.txt");
    rubric1.writeToFile(file);
    rubric2.writeToFile(file);
    rubric3.writeToFile(file);
    file.close();

    ifstream readFile("rubric.txt");
    Rubric rubric4, rubric5, rubric6;
    rubric4.readFromFile(readFile);
    rubric5.readFromFile(readFile);
    rubric6.readFromFile(readFile);
    readFile.close();

    cout << "Rubric 4:" << endl;
    rubric4.printRubricData();
    cout << endl;

    cout << "Rubric 5:" << endl;
    rubric5.printRubricData();
    cout << endl;

    cout << "Rubric 6:" << endl;
    rubric6.printRubricData();
    cout << endl;
}