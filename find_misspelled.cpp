#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

string toLowerCase(const string& str) {
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

void printUnmatchedWords(const vector<string>& words, const vector<string>& badWords) {
    unordered_set<string> wordSet(words.begin(), words.end());

    cout << "Words in badWords not found in wordlist.txt:\n";
    for (const string& word : badWords) {
        string lowerWord = toLowerCase(word);
        if (wordSet.find(lowerWord) == wordSet.end()) {
            cout << lowerWord << endl;
        }
    }
}

/// @brief This function reads a file 
/// @param filename relative path 
/// @return vector of words
vector<string> readWordsFromFile(const string& filename) {
    ifstream file(filename);
    vector<string> words;
    string line;

    // return empty vector if file cannot be found
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        return words;  
    }

    // loop through each line in the text file and append to vector
    while(getline(file, line)) {
        if (!line.empty()) {
            words.push_back(toLowerCase(line));
        }
    }

    file.close();

    return words;
}

int main() {
    string path = "wordlist.txt";
    string path2 = "badWords.txt";
    vector<string> words = readWordsFromFile(path);
    vector<string> badWords = readWordsFromFile(path2);
    printUnmatchedWords(words, badWords);

    return 0;
}
