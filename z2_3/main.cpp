#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


int task()
{
    int p, k, t, year;
    p = 100; // первоначальный объем
    k = 15; // годовой прирост
    t = 20; // годовой план заготовки
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
    task();
    system("pause");
    return 0;
}





