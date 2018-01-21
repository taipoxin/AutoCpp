#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> sta;

bool checkString(string str)
{
    int n = str.length();
    for(int i = 0; i < str.length(); ++i)
    {
        //если скобка открывающая, то помещаем её в стек
        if ((str[i] =='(') || (str[i] =='{') || (str[i] =='['))
            sta.push(str[i]);
        //если не открывающая
        else if ((str[i] ==')') || (str[i] =='}') || (str[i] ==']'))
        {
            //если стек пуст, значит скобочная последовательность неправильная
            if(sta.size() == 0)
                return false;
            //берём последнюю открывающую скобку
            char c = sta.top();
            sta.pop();

            //если тип последней открывающей скобки не совпадает с текущей закрывающей,
            // то скобочная последовательность неправильная
            if (
                    (c == '(' && str[i] != ')') ||
                    (c == '{' && str[i] != '}') ||
                    (c == '[' && str[i] != ']'))
                return false;
        }
    }
    //если после обработки строки остались незакрытые скобки,
    // то скобочная последовательность неправильная
    return (sta.size() == 0);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    int oper;
    wcout <<  L"Check the parenthes.\n";
    wcout <<  L"Enter the string: (for example, (20-5)/(6/2) ) \n";
    getline ( cin, str ); //заполняем строку
    if(checkString(str)) wcout << L"Parenthes are correctly placed!" << endl; //проверяем на коррекность скобок
    else wcout << L"Parenthes are incorrectly placed!" << endl;
}