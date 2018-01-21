#include <iostream>
#include <stdlib.h>
#include <locale>


using namespace std;


int stonum(char *str)
{
    int n=0,k=1;
    while (*str)
    {
        if (*str=='-') k=-1;
        if (*str=='+') k=1;
        if ((*str >= '0') && (*str <= '9')) n=10*n+*str-'0';
        str++;
    }
    n*=k;
    return n;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    wcout << L"Введите строку цифр: \n";


    char *str=(char*)malloc(10*sizeof(char));

    cin >>str;

    wcout << L"Число полученное в результате обработки: \n";
    int d = stonum(str);
    cout << to_string(d);
    return 0;
}
