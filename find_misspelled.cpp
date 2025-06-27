#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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
    while (getline(file, line)) {
        words.push_back(line);
    }

    file.close();

    return words;
}

int main() {
    string path = "wordlist.txt";
    vector<string> words = readWordsFromFile(path);

    return 0;
}
