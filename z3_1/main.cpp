#include <iostream>
#include <math.h>
#include <locale>

using namespace std;


int fillMatrix(int n, int **m)
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            m[i][j] = stoi(to_string(i+1) + to_string(j+1));
    return 0;
}

int changeDiags(int n, int **m)
{
    for(int i=0;i<n;++i){
          int buf;
          buf=m[i][i];
          m[i][i]=m[i][n-1-i];
          m[i][n-1-i]=buf;
    }
    return 0;
}

int showMatrix(int n, int **m)
{
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            std::cout<<m[i][j]<<' ';
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;

}


int main()
{
    setlocale(LC_ALL, "Russian");

    wcout << L"Меняет диагонали квадратной матрицы\n\n";

    // size
    int n = 5;

    wcout << L"Введите размер матрицы\n";
    cin >> n;

    wcout << L"Начальная матрица: \n";

    // matrix
    int **m = new int*[n];
    for (int i = 0; i < n; i++) m[i] = new int[n];

    // fill matrix
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            m[i][j] = stoi(to_string(i+1) + to_string(j+1));

    showMatrix(n, m);


    changeDiags(n, m);


    wcout << L"Измененная матрица: \n";
    showMatrix(n, m);
    system("pause");
    return 0;
}





