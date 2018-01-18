#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


void shift(int * a, int s, int size)
{
    //s = size - s; // если добавить это, то сдвиг будет идти "вправо"
    reverse(a, a + s);
    reverse(a + s, a + size);
    reverse(a, a + size);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    wcout << L"Сдвинуть элементы массива на n позиций влево\n";
    wcout << L"Введите размер массива\n";
    // size
    int size;

    cin >> size;


    int n;
    wcout << L"Введите количество позиций для сдвига\n";
    cin >> n;

    int a[size];

    for(int i = 0; i < size; ++i) {
        a[i] = rand() % 9;
    }

    wcout << L"Начальный массив: \n";

    copy(a, a + size, ostream_iterator<int>(cout, " "));
    cout << endl;

    // сдвиг влево
    shift(a, n, 10);

    wcout << L"Сдвинутый массив: \n";

    copy(a, a + size, ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return 0;
}



