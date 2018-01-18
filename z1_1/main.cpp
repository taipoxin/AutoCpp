#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


double square(double A)
{
    double r, S;
    r = A * sqrt(2);
    S = M_PI * r * r;
    return S;
}



int main()
{
    setlocale(LC_ALL, "Russian");

    int A;
    double S;
    string result;
    wcout << L"Вычисление площади круга, описанного вокруг квадрата со стороной A\n";
    wcout << L"Введите длину стороны A\n";
    cin >> A;
    S = square(A);
    wcout << L"Площадь круга: ";
    cout << to_string(S) << endl;


    system("pause");
    return 0;
}





