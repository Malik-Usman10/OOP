#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[256];
    int counts[256] = {0};

    cout << "Enter a string: ";
    cin.getline(str, sizeof(str));

    for (int i = 0; i < strlen(str); i++) 
    {
        counts[str[i]]++;
    }

    for (int i = 0; i < 256; i++) 
    {
        if (counts[i] > 0 && isprint(i)) 
        {
            cout.put(static_cast<char>(i));
            cout << ": " << counts[i] << endl;
        }
    }
    return 0;
}
