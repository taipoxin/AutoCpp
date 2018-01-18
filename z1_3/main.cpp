#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


int bin_to_dec(string binary)
{
    int decimal = 0;
    for (char i : binary) {
        if (i == '1') {
            decimal = decimal * 2 + 1;
        }
        else if (i == '0') {
            decimal = decimal * 2;
        }
        else {
            // Stop parsing decimal if a non 0/1 character seen.
            break;
        }
    }
    return decimal;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int dec;
    string bitstring;
    wcout << L"Перевод двоичного числа в десятиричное\n";
    wcout << L"Введите число в двоичной форме\n";
    cin >> bitstring;

    dec = bin_to_dec(bitstring);
    wcout << L"Десятеричная форма: ";
    cout << to_string(dec) << endl;
    system("pause");
    return 0;
}





