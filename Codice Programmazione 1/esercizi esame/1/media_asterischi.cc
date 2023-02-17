#include <iostream>
#include <fstream>

using namespace std;

int myStrlen(const char *s)
{
    int len;
    for (len = 0; s[len] != '\0'; len++)
        ;
    return len;
}

int main()
{
    fstream in, out;
    in.open("./input.txt", ios::in);
    if (in.fail())
    {
        cout << "Unable to open the file" << endl;
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int sum = 0;
    int count = 0;
    while (in >> buffer)
    {
        sum += myStrlen(buffer);
        count++;
    }
    in.close();
    int avg = sum / count;

    out.open("./input.txt", ios::out | ios::app);
    if (out.fail())
    {
        cout << "Unable to open the file" << endl;
        exit(EXIT_FAILURE);
    }

    out << '\n';
    for (int i = 0; i < avg; i++)
    {
        out << '*';
    }

    out.close();
    return 0;
}