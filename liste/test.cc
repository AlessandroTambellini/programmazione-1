#include <iostream>
#include "list.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    node *L1 = new node;
    /*     for (int i = 0; i < 1; i++)
        {
            int d = rand() % 100;

            node *t = new node;
            t->value = d;
            t->next = L1;
            L1 = t;
            if (i == 5)
            {
                x = t;
            }
        } */

    /*     cout << "La lista L1 creata e':" << endl;
        print(L1); */

    /*     node *L2 = NULL;
        for (int i = 0; i < 10; i++)
        {
            int d = rand() % 100;

            node *t = new node;
            t->value = d;
            t->next = L2;
            L2 = t;
        }
        cout << "La lista L2 creata e':" << endl;
        print(L2);

        deleteList(L2);
        deleteList(L1); */
}