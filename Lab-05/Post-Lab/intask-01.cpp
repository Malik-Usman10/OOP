#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Encryption 
{
public:
    Encryption(int numLines) 
        : paragraph(new string[numLines]), numLines(numLines), keys(numLines) {}

    ~Encryption() {
        delete[] paragraph;
    }

 void insertParagraphs() 
 {
        for (int i = 0; i < numLines; i++) 
        {
            cout << "Enter line " << i + 1 << ": ";
            cin.ignore();
            getline(cin, paragraph[i]);

            int key;
            cout << "Enter key for line " << i + 1 << ": ";
            while (!(cin >> key)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid key. Please enter a valid integer key: ";
            }
            keys[i] = key;
        }
    }

    void encrypt() 
    {
        for (int i = 0; i < numLines; i++) 
        {
            for (char& ch : paragraph[i])
             {
                if (isalnum(ch)) 
                {
                    int ascii = ch + keys[i];
                    if (ascii > 122 || (ascii > 90 && ascii < 97)) 
                    {
                        ascii -= 26;  
                    }
                    ch = static_cast<char>(ascii);
                }
            }
        }
    }

    void decrypt() 
    {
        for (int i = 0; i < numLines; i++) 
        {
            for (char& ch : paragraph[i]) 
            {
                if (isalnum(ch)) 
                {
                    int ascii = ch - keys[i];
                    if (ascii < 65 || (ascii < 97 && ascii > 90)) 
                    {
                        ascii += 26; 
                    }
                    ch = static_cast<char>(ascii);
                }
            }
        }
    }

    void displaylines() 
    {
        for (int i = 0; i < numLines; i++) 
        {
            cout << paragraph[i] << endl;
        }
    }

private:
    string* paragraph;
    int numLines;
    vector<int> keys;
};

int main() 
{
    try 
    {
        int numLines;
        cout << "Enter number of lines in a Paragraph: ";
        cin >> numLines;

        Encryption encryption(numLines);
        encryption.insertParagraphs();

        cout << "\nEncrypted Paragraph:\n";
        encryption.encrypt();
        encryption.displaylines();

        cout << "\nDecrypted Paragraph:\n";
        encryption.decrypt();
        encryption.displaylines();
    } catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

}
