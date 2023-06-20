#define _CRT_SECURE_NO_WARNINGS

#include "FileFunctions.h"

char* create_file_pointer() {

    FILE* filePtr;
    static char fileName[100];

    cout << "Введіть назву файлу: ";
    cin >> fileName;

    filePtr = fopen(fileName, "w");

    if (filePtr == nullptr) {

        cout << "Файл не створено, виникла помилка" << endl;
        return nullptr;

    }

    else {

        cout << "Файл створено успішно" << endl;
        fclose(filePtr);
        return _strdup(fileName);

    }

}

void create_file_stream(string& fileNameStr) {

    cout << "Введіть назву файлу: ";
    cin >> fileNameStr;

    ofstream fileStream(fileNameStr);

    if (!fileStream.is_open()) {

        cout << "Помилка створення файлу!" << endl;
        return;

    }

    cout << "Файл успішно створено!" << endl;
    fileStream.close();

}

void append_file_ptr(char* fileName) {

    FILE* filePtr;
    char ch;
    string line[100];
    int i = 0;
    filePtr = fopen(fileName, "a");

    if (filePtr == NULL) {

        cout << "Помилка відкриття файлу" << endl;
        return;

    }

    else {

        cout << "\nВведіть текст (натисніть CTRL+D щоб закінчити ввід):\n";

        while ((ch = getchar()) != 4) {

            line[i] += ch;

            if (ch == '\n') 
                i++;
            
        }

        for (int j = 1; j <= i; j++) 
            fprintf(filePtr, "%s", line[j].c_str());
        
    }

    fclose(filePtr);

}

void append_file_str(const string& fileName) {

    string line;
    char ch;
    ofstream fout(fileName, ios::app);

    if (!fout.is_open()) {

        cerr << "Помилка відкриття файлу \"" << fileName << "\"" << endl;
        return;

    }

    else {

        cout << "\nВведіть текст (натисніть CTRL+D щоб закінчити ввід):\n";
        cin.ignore();

        while ((ch = getchar()) != 4) {

            if (ch == '\n') {

                fout << line << '\n';
                line.clear();

            }

            else 
                line += ch;
            
        }

        if (!line.empty()) 
            fout << line;
        
        fout.close();
    }
}

void read_file_ptr(char* fileNamePtr) {

    FILE* file = fopen(fileNamePtr, "r+");
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file))
        cout << buffer;
    
    fclose(file);
    cout << "\n";

}

void read_file_str(const string& fileName) {

    ifstream inFile(fileName);
    string line;

    while (getline(inFile, line)) 
        cout << line << endl;
    
    inFile.close();
}
