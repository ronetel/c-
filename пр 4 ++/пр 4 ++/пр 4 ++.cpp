#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

using namespace std;

void reverse(std::string & word) {
        reverse(word.begin(), word.end());
    }

void removeVowels(string & word) {
        word.erase(std::remove_if(word.begin(), word.end(),
            [](char c) { return string("аеёиоуыэюяАЕЁИОУЫЭЮЯ").find(c) != string::npos; }), word.end());
    }

void removeConsonants(string & word) {
        word.erase(std::remove_if(word.begin(), word.end(),
            [](char c) { return string("бвгджзйклмнпрстфхцчшщьъБВГДЖЗЙКЛМНПРСТФХЦЧШЩЬЪ").find(c) != string::npos; }), word.end());
    }

void shuffle(string & word) {
        random_device rd;
        mt19937 g(rd());
        shuffle(word.begin(), word.end(), g);
    }

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    string word;
    cout << "Введите слово: ";
    cin >> word;
    int choice;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Перевернуть слово" << endl;
        cout << "2. Удалить гласные буквы" << endl;
        cout << "3. Удалить согласные буквы" << endl;
        cout << "4. Перемешать буквы в слове" << endl;
        cout << "Введите ваш выбор (1-4, 0 для выхода): ";
        cin >> choice;

        switch (choice) {
            case 1:
            reverse(word.begin(), word.end());
            cout << "Перевернутое слово: " << word << endl;
            break;
            case 2:
            removeVowels(word);
            cout << "Слово без гласных: " << word << endl;
            break;
            case 3:
            removeConsonants(word);
            cout << "Слово без согласных: " << word << endl;
            break;
            case 4:
            shuffle(word.begin(), word.end(), std::mt19937(std::random_device()()));
            cout << "Перемешанное слово: " << word << endl;
            break;
            case 0:
            cout << "Завершение программы." << endl;
            break;
            
        }
    } while (choice != 0);

    return 0;
}