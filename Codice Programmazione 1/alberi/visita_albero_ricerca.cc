#include <iostream>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

typedef node *albero;

/*
Questa è la versione ricorsiva dello stampo dei valori in ordine crescente
di un albero binario di ricerca.
La versione iterativa è molto più complessa
*/
void visit(albero t)
{
    /* !Important Tip!
        instead of writing t == nullptr, writing in this way if you forgot an =,
        the compiler is gonna throw an error. If you swap the terms of the equality
        that's not the case
    */
    if (nullptr == t)
    {
        return;
    }
    visit(t->left);
    cout << t->value << ' ';
    visit(t->right);
}