#define _CRT_SECURE_NO_WARNINGS

#include "Mask.h"

string reverse_word(const string& word) {

    string reversed_word;

    for (int i = word.length() - 1; i >= 0; --i) 
        reversed_word += word[i];
    
    return reversed_word;

}

bool match_mask(const string& word, const string& mask) {

    bool flag = true;
    string reversed_word, reversed_mask;

    if (word.length() < mask.length())
        flag = false;
    
    else {

        reversed_word = reverse_word(word);
        reversed_mask = reverse_word(mask);

        for (size_t i = 0; i < reversed_mask.length(); ++i) {

            if (reversed_mask[i] != '*' && reversed_mask[i] != reversed_word[i]) {

                flag = false;
                break;

            }

        }

    }

    return flag;

}

void filter_words(vector<string>& words, const string& mask) {

    auto it = words.begin();

    while (it != words.end()) {

        if (match_mask(*it, mask)) 
            it = words.erase(it);
        
        else 
            ++it;
        
    }
}

vector<string> split_line(const string& line) {

    vector<string> words;
    string word;

    for (const auto& c : line) {

        if (c == ' ' || c == ',' || c == '.') {

            if (!word.empty()) {

                words.push_back(word);
                word.clear();

            }

        }

        else 
            word += c;
        
    }

    if (!word.empty())
        words.push_back(word);
    
    return words;

}

void mask_in_file_str(string filename, string outputFile) {

    vector<string> words;
    ifstream inFile(filename);
    ofstream outFile(outputFile, ios::app);

    if (!inFile.is_open()) {

        cout << "Помилка відкриття файлу" << filename << endl;
        return;

    }

    string line;
    string mask;

    cout << "Введіть маску (як приклад \"*ня\"): ";
    cin >> mask;
    cin.ignore();

    while (getline(inFile, line)) {

        words = (split_line(line));
        filter_words(words, mask);

        for (const auto& word : words)
            outFile << word << ' ';
        
        outFile << '\n';

    }

    inFile.close();
    outFile.close();

}

void mask_in_file_ptr(char* fileName, char* outputFileName) {

    FILE* inFile = fopen(fileName, "r");
    FILE* outFile;

    if (inFile == NULL) {

        cout << "Помилка відкриття файлу" << endl;
        return;

    }

    string line;
    string mask;
    vector <string> words;

    cout << "Введіть маску (як приклад \"*ня\")" << endl;
    cin >> mask;

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), inFile)) {

        printf("%s", buffer);
        cout << buffer;

        string line(buffer);

        words = (split_line(line));
        filter_words(words, mask);

        for (const auto& word : words) 
            cout << word << endl;
        
        outFile = fopen(outputFileName, "a");

        for (const auto& word : words) 
            fprintf(outFile, "%s ", word.c_str());
        
        fclose(outFile);

    }

    fclose(inFile);

}

void longest_word_str(const string& infilename, const string& outfilename) {

    ifstream inFile(infilename);
    ofstream outFile(outfilename, ios::app);
    string line;
    vector<string> words;
    string word;

    while (getline(inFile, line)) {

        words = (split_line(line));

        auto maxIt = max_element(words.begin(), words.end(),[](const string& a, const string& b) {

            return a.length() < b.length();

        });

        if (maxIt != words.end()) {

            string longestWord = *maxIt;
            words.erase(maxIt);
            words.insert(words.begin(), longestWord);

        }

        for (const auto& word : words)
            outFile << word << ' ';
        
        outFile << '\n';

    }

    inFile.close();
    outFile.close();

}

void longest_word_ptr(char* infilename, char* outfilename) {

    FILE* inFile = fopen(infilename, "r");
    FILE* outFile;
    string line;
    vector<string> words;
    string word;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), inFile)) {

        string line(buffer);
        words = (split_line(line));

        auto maxIt = max_element(words.begin(), words.end(), [](const string& a, const string& b) {

            return a.length() < b.length();

        });

        if (maxIt != words.end()) {

            string longestWord = *maxIt;
            words.erase(maxIt);
            words.insert(words.begin(), longestWord);

        }

        outFile = fopen(outfilename, "a");

        for (const auto& word : words) 
            fprintf(outFile, "%s ", word.c_str(), "\n");
        
        fclose(outFile);

    }

    fclose(inFile);
}
