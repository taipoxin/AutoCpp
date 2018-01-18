#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


string dec_to_bin(int dec)
{
    string bitstring;
    while (dec > 0 )
    {
        int bit      = dec % 2 ;
        int quotient = dec / 2 ;
        bitstring = to_string(bit) + bitstring;
        dec = quotient;
    }
    return bitstring;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int dec;
    string bitstring;
    wcout << L"Перевод десятеричного числа в двоичное\n";
    wcout << L"Введите число в десятеричной форме\n";
    cin >> dec;

    bitstring = dec_to_bin(dec);
    wcout << L"Двоичная форма: ";
    cout << bitstring << endl;
    system("pause");
    return 0;
}





