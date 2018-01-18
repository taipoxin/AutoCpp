#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


bool isCmnDigit(int a, int b, int c)
{
    int a_ = a % 2;
    return a_ == b % 2 && c % 2 == a_;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    bool res;
    int a,b,c;
    wcout << L"Проверка одинаковой четности 3 целых чисел\n";
    wcout << L"Введите первое число\n";
    cin >> a;
    wcout << L"Введите второе число\n";
    cin >> b;
    wcout << L"Введите третье число\n";
    cin >> c;

    res = isCmnDigit(a,b,c);
    wcout << L"Все 3 числа одной четности?\n";
    wcout << (res ? L"Правда" : L"Ложь");
    cout  << endl;
    system("pause");
    return 0;
}





