#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


int NOD(int x, int y)
{
    if ((y == 0) || (x == 0))
        return x;
    else
        return NOD(y, x % y);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int dec;
    int M, N;
    string bitstring;
    wcout << L"Наибольший общий делитель натуральных чисел\n";
    wcout << L"Введите число m\n";
    cin >> M;
    wcout << L"Введите число n\n";
    cin >> N;


    dec = NOD(M, N);
    wcout << L"НОД двух чисел: ";
    cout << to_string(dec) << endl;
    system("pause");
    return 0;
}





