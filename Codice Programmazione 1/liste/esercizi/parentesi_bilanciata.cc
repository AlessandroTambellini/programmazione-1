#include <iostream>
#include "../pila.h"

using namespace std;

int main()
{
    char str[101];
    cout << "Inserisci parentesi: ";
    cin >> str;

    init();

    bool correctExp = true;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            int tmp;
            if (top(tmp))
            {
                pop();
            }
            else
            {
                correctExp = false;
            }
        }
    }

    if (correctExp && !pop())
    {
        cout << "The expression is correct" << endl;
    }
    else
    {
        cout << "The expression in incorrect" << endl;
    }

    deinit();

    return 0;
}