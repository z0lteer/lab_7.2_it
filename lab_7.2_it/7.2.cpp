#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// ������� ��� ���������� ������� ����������� ����������
void Create(int** a, const int rows, const int cols, const int Low, const int High);

// ������� ��� ��������� ������� �� �����
void Print(int** a, const int rows, const int cols);

// ������� ��� ����� ������ ������������� � ���������� �������� � �����
void SwapMaxMinInRow(int* row, const int cols);

int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����
    int Low = 7; // ����� ���� ���������� �����
    int High = 65; // ������ ���� ���������� �����
    int rows, cols;

    cout << "rows = "; cin >> rows; // �������� ������� �����
    cout << "cols = "; cin >> cols; // �������� ������� ��������

    // ��������� ����������� ���������� ������
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    Create(a, rows, cols, Low, High); // ���������� ������� ����������� ����������
    Print(a, rows, cols); // ��������� ��������� �������

    // ����� ������ ������������� � ���������� �������� � ������� �����
    for (int i = 0; i < rows; i++) {
        SwapMaxMinInRow(a[i], cols);
    }

    cout << "Modified matrix:" << endl;
    Print(a, rows, cols); // ��������� ������ �������

    // ��������� ���'��, ������� �� �����
    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// ������� ��� ���������� ������� ����������� ���������� � ����� [Low, High]
void Create(int** a, const int rows, const int cols, const int Low, const int High) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// ������� ��� ��������� ������� �� �����
void Print(int** a, const int rows, const int cols) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// ������� ��� ����������� �� ����� ������ ������������� � ���������� �������� � �����
void SwapMaxMinInRow(int* row, const int cols) {
    int minIndex = 0;
    int maxIndex = 0;

    // ����� ������� ���������� � ������������� �������� � �����
    for (int j = 1; j < cols; j++) {
        if (row[j] < row[minIndex])
            minIndex = j;
        if (row[j] > row[maxIndex])
            maxIndex = j;
    }

    // ����� ������ ���������� � ������������� ��������
    int temp = row[minIndex];
    row[minIndex] = row[maxIndex];
    row[maxIndex] = temp;
}
