#include <iostream>
#include <fstream>
#include "crypt.h"
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Wrong number of parameters" << endl;
        exit(1);
    }

    fstream in, out;

    in.open(argv[1], ios::in);
    if (in.fail())
    {
        cout << "Error trying to open " << argv[1] << endl;
        exit(1);
    }

    out.open(argv[2], ios::out);
    if (out.fail())
    {
        cout << "Error trying to open " << argv[2] << endl;
        exit(1);
    }

    int choice;
    cout << "Enter 0 if you want to crypt the msg, enter 1 if you want to decrypt the msg: ";
    cin >> choice;
    if (choice != 0 && choice != 1)
    {
        cout << "Wrong input number" << endl;
        exit(1);
    }

    int cryptKey = atoi(argv[3]);
    char buffer[256];
    while (in >> buffer)
    {
        choice == 0 ? crypt(buffer, cryptKey) : decrypt(buffer, cryptKey);
        out << buffer << ' ';
    }
    out << "encryption key: " << cryptKey;

    in.close();
    out.close();

    return 0;
}