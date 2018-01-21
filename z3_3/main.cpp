#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

//#define ROW 6
//#define COL 5

using namespace std;

int min(int a, int b, int c)
{
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

int main()
{

    /*
    int matrix[ROW][COL] = {
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1}};

    */

    setlocale(LC_ALL, "Russian");

    wcout << L"Ищет максимульную подматрицу, состоящую из нулей\n\n";

    // size
    int m = 5;

    wcout << L"Введите размер матрицы\n";
    cin >> m;
    int ROW = m;
    int COL = m;

    wcout << L"Начальная матрица: \n";

    srand (time(0) );
    int matrix[m][m];

    // fill matrix
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < m; j++)
        {
            matrix[i][j] = rand() % 2;
            cout<< matrix[i][j]<< " ";
        }
        cout<< endl;
    }



    int output[ROW][COL] = {0};
    int i, j;
    int max = 1;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (matrix[i][j] == 0)
                output[i][j] = 1;
        }
    }

    for (i = 1; i < ROW; i++) {
        for (j = 1; j < COL; j++) {
            if (output[i][j]) {
                output[i][j] = min(output[i-1][j-1], output[i-1][j], output[i][j-1]) + 1;
                if (output[i][j] > max)
                    max = output[i][j];
            }
        }
    }

    wcout << L"\nМаксимальный размер стороны квадратной подматрицы, состоящей из нулей, равен ";
    cout << to_string(max) << endl;
    system("pause");
    return 0;
}