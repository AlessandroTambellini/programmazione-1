#include <iostream>

using namespace std;

float division(float a, float b)
{
    if (b == 0)
    {
        cout << "Cannot divide by 0." << endl;
        exit(1);
    }
    return a / b;
}

float mul(float a, float b)
{
    return a * b;
}

float sub(float a, float b)
{
    return a - b;
}

float sum(float a, float b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    cout << argv[0] << endl
         << argv[1] << endl
         << argv[2] << endl
         << argv[3] << endl
         << argv[4] << endl;
    if (argc != 4)
    {
        cout << "Numero di argomenti errato." << endl;
        exit(1);
    }

    float num1 = atof(argv[1]);
    float num2 = atof(argv[3]);
    float res;

    switch (argv[2][0])
    {
    case '+':
        res = sum(num1, num2);
        break;
    case '-':
        res = sub(num1, num2);
        break;
    case 'x':
        res = mul(num1, num2);
        break;
    case '/':
        res = division(num1, num2);
    }

    cout << "Operation result: " << res << endl;

    return 0;
}