#include <iostream>

using namespace std;

int main()
{
    const char *str1 = "Random"; // allocated in the heap

    /*     const char *p = "haha";
        char q = *p;
        std::cout << "&q = " << &q << std::endl; //&q = h
        std::cout << "q  = " << q << std::endl; */

    char foo[20];

    foo[1] = '_';
    foo[19] = '\0';
    cout << foo << endl;

    char myword1[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // string literals (as myword2) always have a null character ('\0') automatically appended at the end.
    // Thus myword2 has a fixed size of 6 chars
    char myword2[] = "Hello";

    // Thus both the myword[] declared above have size 6

    // !!! Because string literals are regular arrays, they have the same restrictions as these,
    // and cannot be assigned values

    char response[80];
    cout << "Write how are you now: ";
    cin >> response;

    cout << "Your response was: " << response << endl;

    /* Strings have a dynamic size determined during runtime,
    while the size of arrays is determined on compilation, before the program runs */

    return 0;
}