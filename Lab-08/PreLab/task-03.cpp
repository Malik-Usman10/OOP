#include <iostream>

using namespace std;

class IntInput {
public:
    friend istream& operator>>(istream& is, IntInput& obj) {
        return is >> obj.input;
    }
    int getValue() const {
        return input;
    }

private:
    int input;
};

int main() {
    IntInput input;
    cout << "Enter sentences :\n";
    while (!cin.eof()) 
    {
        if (cin >> input) 
        {
            cout << input.getValue() << " ";
        }
        else 
        {
            cin.clear();
            cin.ignore();
        } 
    }
     cout << "EOF character before program ends: " << EOF << endl; 
    cin.clear();
    cout << "EOF character value after program ends: " << EOF << endl;
}
