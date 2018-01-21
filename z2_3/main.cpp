#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


int task(int p, int k, int t)
{
    int year;
    /*
    p = 100; // первоначальный объем
    k = 15; // годовой прирост
    t = 20; // годовой план заготовки
     */
    year = 1;

    if ((p*k)/100 >= t)
    {
        wcout << L"Бесконечно можно пилить\n";
    }
    else
    {
        while ((p + (p*k) / 100 - t) > 0)
        {
            p = p + (p*k) / 100 - t;
            year++;
        }
        wcout << L"Лес будет полностью вырублен через ";
        cout << to_string(year);
        wcout << L" лет\n";
    }
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    wcout << L"Задача на вырубку леса\n";
    int p,k,t;

    wcout << L"Введите обьем в кубометрах\n";
    cin >> p;
    wcout << L"Введите годовой прирост в процентах\n";
    cin >> k;
    wcout << L"Введите план заготовки в кубометрах\n";
    cin >> t;

    task(p, k, t);
    system("pause");
    return 0;
}





