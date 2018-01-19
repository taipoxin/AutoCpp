#include <iostream>
#include <ctime>

using namespace std;


int showMatrix(int n, int **m)
{
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<m[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    return 0;

}



int main()
{
    setlocale(LC_ALL, "Russian");

    wcout << L"Ищет максимульную подматрицу, состоящую из нулей\n\n";

    // size
    int m = 5;

    wcout << L"Введите размер матрицы\n";
    cin >> m;

    wcout << L"Начальная матрица: \n";

    srand (time(0) );
    int arr[m][m];

    // fill matrix
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
            cout<< arr[i][j]<< " ";
        }
        cout<< endl;
    }

    // alg
    int col=0, i, j, i1, j1, tmp, tmp1;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
        {
          if(arr[i][j]!=1)
          {
              tmp=0;
              for(j1=j; j1<m && arr[i][j1]!=1; j1++)
              {
                  tmp1=0;
                  for(i1=i; i1<m && arr[i1][j1]!=1; i1++)
                      tmp1++;
                  if(!tmp)
                      tmp=tmp1;
                  else
                  {
                      if(tmp>tmp1)
                          tmp=tmp1;
                  }
                    if(col<tmp*(j1-j+1))
                        col=tmp*(j1-j+1);
              }
          }
        }
    // здесь в переменной col максимальное значение площади

    wcout << L"Площадь максимальной подматрицы из нулей равна ";
    cout << to_string(col);

    return 0;
}