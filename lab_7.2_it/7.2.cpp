#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Функція для заповнення матриці випадковими значеннями
void Create(int** a, const int rows, const int cols, const int Low, const int High);

// Функція для виведення матриці на екран
void Print(int** a, const int rows, const int cols);

// Функція для заміни місцями максимального і мінімального елементів у рядку
void SwapMaxMinInRow(int* row, const int cols);

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    int Low = 7; // Нижня межа випадкових чисел
    int High = 65; // Верхня межа випадкових чисел
    int rows, cols;

    cout << "rows = "; cin >> rows; // Введення кількості рядків
    cout << "cols = "; cin >> cols; // Введення кількості стовпців

    // Створення двовимірного динамічного масиву
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    Create(a, rows, cols, Low, High); // Заповнення матриці випадковими значеннями
    Print(a, rows, cols); // Виведення початкової матриці

    // Заміна місцями максимального і мінімального елементів у кожному рядку
    for (int i = 0; i < rows; i++) {
        SwapMaxMinInRow(a[i], cols);
    }

    cout << "Modified matrix:" << endl;
    Print(a, rows, cols); // Виведення зміненої матриці

    // Звільнення пам'яті, виділеної під масив
    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція для заповнення матриці випадковими значеннями у межах [Low, High]
void Create(int** a, const int rows, const int cols, const int Low, const int High) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці на екран
void Print(int** a, const int rows, const int cols) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для знаходження та заміни місцями максимального і мінімального елементів у рядку
void SwapMaxMinInRow(int* row, const int cols) {
    int minIndex = 0;
    int maxIndex = 0;

    // Пошук індексів мінімального і максимального елементів у рядку
    for (int j = 1; j < cols; j++) {
        if (row[j] < row[minIndex])
            minIndex = j;
        if (row[j] > row[maxIndex])
            maxIndex = j;
    }

    // Заміна місцями мінімального і максимального елементів
    int temp = row[minIndex];
    row[minIndex] = row[maxIndex];
    row[maxIndex] = temp;
}
