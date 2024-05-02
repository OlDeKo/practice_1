#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    double tmp, d;
    cout << "Введите размерность матрицы:\n";
    cout << "n = ";
    cin >> n;
    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n]; }
    cout << "Введите матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; } }
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp; } } }
    cout << "\nМатрица:\n\n";
    cout.precision(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(8);
            cout << fixed << a[i][j] << " "; }
        cout << "\n"; }
    d = 1;
    for (int i = 0; i < n; i++) { d *= a[i][i]; }
    cout << fixed << "\nОпределитель: " << d << "\n";
    for (int i = 0; i < n; i++) { delete[] a[i]; }
    delete[] a;
    system("pause");}