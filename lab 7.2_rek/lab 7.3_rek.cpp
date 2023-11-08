#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int N, const int Low, const int High, int i, int j) {
    if (i < N) {
        if (j < N) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, N, Low, High, i, j + 1);
            return;
        }
        else {
            Create(a, N, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int N, int i, int j) {
    if (i < N) {
        if (j < N) {
            cout << setw(4) << a[i][j];
            Print(a, N, i, j + 1);
            return;
        }
        else {
            cout << endl;
            Print(a, N, i + 1, 0);
        }
    }
}

int Sum(int** a, const int N, int i) {
    if (i < N) {
        return a[i][i] + Sum(a, N, i + 1);
    }
    return 0;
}

int main() {
    srand((unsigned)time(NULL));
    int N;
    cout << "n = ";
    cin >> N;
    cout << endl;

    int** a = new int* [N];
    for (int i = 0; i < N; i++) {
        a[i] = new int[N];
    }

    int Low = -9, High = 9;
    Create(a, N, Low, High, 0, 0);
    cout << "Матриця:" << endl;
    Print(a, N, 0, 0);

    int sum = Sum(a, N, 0);
    cout << "Sum of elements on the main diagonal: " << sum << endl;

    for (int i = 0; i < N; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}