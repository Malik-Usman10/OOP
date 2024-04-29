#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sentenceInput(vector<string>& sentences, int count) 
{
    if (count <= 0) 
    {
        return; 
    }
    string sentence;
    cout << "Enter sentence " << count << ": ";
    getline(cin, sentence); 
    sentences.push_back(sentence);

    sentenceInput(sentences, count - 1);
}

void showSentences(const vector<string>& sentences, int index) {
    if (index >= sentences.size()) {
        return; 
    }

    cout << sentences[index] << endl;
    showSentences(sentences, index + 1); 
}

int main() {
    int numSentences;
    cout << "Enter the number of sentences: ";
    cin >> numSentences;
    cin.ignore();

    vector<string> sentences;
    sentenceInput(sentences, numSentences);

    cout << "All sentences:" << endl;
    showSentences(sentences, 0);
}
