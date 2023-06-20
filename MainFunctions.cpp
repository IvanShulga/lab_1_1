#include "MainFunctions.h"

int set_mode(int argc, char** argv) {

    if (argc != 3)
        return 0;

    string variant{ argv[1] },
        mode{ argv[2] };

    if (variant != "-mode")
        return 0;

    if (mode == "FilePointer")
        return 1;

    else if (mode == "FileStream")
        return 2;

    else
        return 0;

}

int program(int argc, char** argv) {

    int variant;
    variant = 1;
    char* fileNamePtr = nullptr;
    char* outputFileName_1 = nullptr;
    char* outputFileName_2 = nullptr;
    string fileNameStr, outputFile_1, outputFile_2;

    int mode = set_mode(argc, argv);

    if (mode == 1) {

        cout << "Варіант роботи з файлами: FilePointer" << endl;

        while (variant != 0) {

            show_menu();

            cout << "Обери варіант роботи з файлами: ";
            cin >> variant;

            switch (variant) {

            case 0:
                break;

            case 1:

                fileNamePtr = create_file_pointer();
                append_file_ptr(fileNamePtr);

                cout << "\nУ файл доданий такий текст:" << endl;
                read_file_ptr(fileNamePtr);

                break;

            case 2:

                cout << "\nВміст початкового файлу:" << endl;
                read_file_ptr(fileNamePtr);

                cout << "\nВміст проміжного файлу:" << endl;
                read_file_ptr(outputFileName_1);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_ptr(outputFileName_2);

                break;

            case 3:

                cout << "Введи назву файлу: ";
                cin >> fileNamePtr;

                cout << "\nВміст файлу:" << endl;
                read_file_ptr(fileNamePtr);
                append_file_ptr(fileNamePtr);

                cout << "\nОновлений вміст файлу:" << endl;
                read_file_ptr(fileNamePtr);

                break;

            case 4:

                cout << "Перша частина завдання." << endl << endl;

                cout << "Як назвати новий файл для виведення без слова-маски?" << endl;
                outputFileName_1 = create_file_pointer();
                mask_in_file_ptr(fileNamePtr, outputFileName_1);

                cout << "\nВміст початкового файлу:" << endl;
                read_file_ptr(fileNamePtr);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_ptr(outputFileName_1);

                cout << "Друга частина завдання." << endl << endl;

                cout << "Як назвати новий файл для виведення тексту з переміщенням найдовшого слова?" << endl;
                outputFileName_2 = create_file_pointer();
                longest_word_ptr(outputFileName_1, outputFileName_2);

                cout << "\nВміст початкового файлу:" << endl;
                read_file_ptr(outputFileName_1);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_ptr(outputFileName_2);

                break;

            }

        }

    }

    else if (mode == 2) {

        cout << "Варіант роботи з файлами : FileStream" << endl;
        while (variant != 0) {

            show_menu();

            cout << "Обери варіант роботи з файлами: ";
            cin >> variant;

            switch (variant) {

            case 0:
                break;

            case 1:

                create_file_stream(fileNameStr);
                append_file_str(fileNameStr);

                cout << "\nУ файл доданий такий текст:" << endl;
                read_file_str(fileNameStr);

                break;

            case 2:

                cout << "\nВміст початкового файлу:" << endl;
                read_file_str(fileNameStr);

                cout << "\nВміст проміжного файлу:" << endl;
                read_file_str(outputFile_1);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_str(outputFile_2);

                break;

            case 3:

                cout << "Введи назву файлу: ";
                cin >> fileNameStr;

                cout << "\nВміст файлу:" << endl;
                read_file_str(fileNameStr);
                append_file_str(fileNameStr);

                cout << "\nОновлений вміст файлу:" << endl;
                read_file_str(fileNameStr);

                break;

            case 4:

                cout << "Перша частина завдання." << endl << endl;

                cout << "Як назвати новий файл для виведення без слова-маски?" << endl;
                create_file_stream(outputFile_1);
                mask_in_file_str(fileNameStr, outputFile_1);

                cout << "\nВміст початкового файлу:" << endl;
                read_file_str(fileNameStr);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_str(outputFile_1);

                cout << "Друга частина завдання." << endl << endl;

                cout << "Як назвати новий файл для виведення тексту з переміщенням найдовшого слова?" << endl;
                create_file_stream(outputFile_2);
                longest_word_str(outputFile_1, outputFile_2);

                cout << "\nВміст початкового файлу:" << endl;
                read_file_str(outputFile_1);

                cout << "\nВміст кінцевого файлу:" << endl;
                read_file_str(outputFile_2);

                break;

            }

        }

    }

    else
        cout << "Помилка режиму роботи з файлом!" << endl;

    return 0;

}

void show_menu() {

    cout << endl << "Оберіть:\n1 для створення нового файлу\n2 для всіх файлів\n3 для того, щоб додати текст у файл\n4 для виконання програми"
        << "\n0 для завершення програми" << endl;

    cout << setw(45) << setfill('-') << "-" << endl;

}
