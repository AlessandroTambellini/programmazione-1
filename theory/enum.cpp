#include <iostream>

using namespace std;

/* It provides a way to define and group integral constants.
It also makes the code easy to maintain and less complex.
It is also helpful for code documentation and readability purposes.*/

enum Taste
{
    vanilla,
    chocolate,
    butterscotch,
};

enum CarSpeed
{
    Roadster = 400,
    LaFerrari = 372,
    Cayman = 293,
    Veyron = 408,
};

enum MobilePriorities
{
    Display = 1,
    Camera = 2,
    Storage = 4,
};

int main()
{
    /* Ice cream */

    int choosenTaste;
    cout << "Choose the taste of your ice cream: ";
    cin >> choosenTaste;

    switch (choosenTaste)
    {
    case vanilla:
        cout << "You choose the vanilla taste" << endl;
        break;

    case chocolate:
        cout << "You choose the chocolate taste" << endl;
        break;

    case butterscotch:
        cout << "You choose the butterscotch taste" << endl;
        break;

    default:
        cout << "Sorry, the choosen taste is not avaiable" << endl;
        break;
    }

    /* Car speed */

    int choosenSpeed;
    cout << "Guess the speed of the Ferrari LaFerrari: ";
    cin >> choosenSpeed;

    if (choosenSpeed == LaFerrari)
    {
        cout << "You guessed it!" << endl;
    }
    else
    {
        cout << "Bad answer :(" << endl;
    }

    /* Mobile Priorities */

    int mobileChoice = Camera | Display;
    cout << "Mobile choice: " << mobileChoice << endl;

    return 0;
}