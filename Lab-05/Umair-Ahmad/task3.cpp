#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getSentence(vector<string>& sentences, int count) {
    if (count <= 0) 
    {
        return; 
    }
    string sentence;
    cout << "Enter sentence " << count << ": ";
    getline(cin, sentence); 
    sentences.push_back(sentence);

    getSentence(sentences, count - 1);
}

void displaySentences(const vector<string>& sentences, int index) {
    cout << sentences[index] << endl;
    displaySentences(sentences, index + 1); 
}

int main() {
    int numSentences;
    cout << "Enter the number of sentences: ";
    cin >> numSentences;
    cin.ignore();

    vector<string> sentences;
    getSentence(sentences, numSentences);

    cout << "All sentences:" << endl;
    displaySentences(sentences, 0);

    return 0;
}
