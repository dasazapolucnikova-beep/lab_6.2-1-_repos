#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція формування масиву
void CreateRec(int* a, const int n, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < n - 1) {
        CreateRec(a, n, Low, High, i + 1);
    }
}

// Рекурсивна функція виведення масиву
void PrintRec(const int* a, const int n, int i = 0) {
    cout << setw(5) << a[i];
    if (i < n - 1) {
        PrintRec(a, n, i + 1);
    }
    else {
        cout << endl;
    }
}

// Допоміжна рекурсивна функція для обчислення суми елементів з парними індексами
int SumEvenIndicesRec(const int* a, const int n, int i = 0) {
    if (i >= n) {
        return 0;
    }
    return a[i] + SumEvenIndicesRec(a, n, i + 2);
}

// Допоміжна рекурсивна функція для обчислення кількості парних індексів
int CountEvenIndicesRec(const int n, int i = 0) {
    if (i >= n) {
        return 0;
    }
    return 1 + CountEvenIndicesRec(n, i + 2);
}

// Головна функція для обчислення середнього арифметичного
double AverageEvenIndicesRec(const int* a, const int n) {
    int count = CountEvenIndicesRec(n);
    if (count == 0) return 0.0;

    int sum = SumEvenIndicesRec(a, n);
    return static_cast<double>(sum) / count;
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 10;
    int a[n];

    CreateRec(a, n, -10, 10);

    cout << "Array a:" << endl;
    PrintRec(a, n);

    double avg = AverageEvenIndicesRec(a, n);
    cout << "Average of elements with even indices = " << fixed << setprecision(2) << avg << endl;

    return 0;
}