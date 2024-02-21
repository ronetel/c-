#include <iostream>

const int ROWS = 3;
const int COLS = 5;

int main() {
    setlocale(LC_ALL, "RUS");
    double arr[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        std::cout << "Введите " << COLS << " элементов для " << i + 1 << "-й строки:" << std::endl;
        for (int j = 0; j < COLS; ++j) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        double sum = 0;
        for (int j = 0; j < COLS; ++j) {
            sum += arr[i][j];
        }
        double avg = sum / COLS;
        std::cout << "Среднее арифметическое для " << i + 1 << "-й строки: " << avg << std::endl;
    }
    return 0;
}