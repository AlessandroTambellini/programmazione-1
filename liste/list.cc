#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

void print(node *s)
{
    int i = 0;
    while (s != nullptr)
    {
        cout << "Elemento " << i++ << " = " << s->value << endl;
        s = s->next;
    }
}

int length(node *s)
{
    int result = 0;

    for (; s != nullptr; s = s->next)
        result++;
    return result;
}

int recLength(node *s)
{
    if (s == nullptr)
        return 0;
    return 1 + length(s->next);
}

int circularLength(node *s, node *x)
{
    int l = 0;
    if (s != nullptr)
    {
        l = 1;
        for (s = s->next; s != x; s = s->next)
        {
            l++;
        }
    }

    return l;
}

int findBiggestValue(node *x)
{
    int biggestValue = -1;
    for (; x != nullptr; x = x->next)
    {
        if (x->value > biggestValue)
        {
            biggestValue = x->value;
        }
    }

    return biggestValue;
}

int findSmallestValue(node *x)
{
    if (x == nullptr)
    {
        return -1;
    }

    int smallestValue = x->value;
    for (; x != nullptr; x = x->next)
    {
        if (x->value < smallestValue)
        {
            smallestValue = x->value;
        }
    }

    return smallestValue;
}

int searchElement(node *x, int guess)
{
    for (; x != nullptr; x = x->next)
    {
        if (x->value == guess)
        {
            return 1;
        }
    }

    return 0;
}

void generateList(node *&x, int len)
{
    if (x != nullptr)
    {
        x = nullptr;
    }
    for (int i = 0; i < len; i++)
    {
        int v = rand() % 100;
        node *t = new node;
        t->value = v;
        t->next = x;
        x = t;
    }
}

void deleteList(node *&s)
{
    // Alla fine la lista e' vuota. Passaggio per riferimento.
    while (s != nullptr)
    {
        // Salvo il valore del node corrente
        // cout << "deleting node with value: " << s->value << endl;
        node *t = s;
        s = s->next;
        delete t;
    }
}

void recDeleteList(node *&s)
{
    if (nullptr == s)
    {
        return;
    }
    else
    {
        recDeleteList(s->next);
        delete s; // pay attention! It doesn't became a nullptr
    }
}

void insertLastNode(node *&s, int v)
{
    node *n = new node;
    n->value = v;
    n->next = NULL;

    // Se la lista e' vuota, allora s dovra' puntare al nuovo node
    if (nullptr == s)
    {
        s = n;
    }
    else
    {
        // Cerco l'ultimo elemento, q->next qui e' lecito perche' siamo
        // sicuri che s e' diverso da nullptr
        node *q = s;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = n;
    }
}

void insertFirstNode(node *&s, int v)
{
    node *n = new node;
    n->value = v;
    n->next = s;
    s = n;
}

// how does it works: starting from the first node it goes on until it finds a node whose value is greater than int v.
// So v is placed before this node
void insertBefore(node *&s, int v)
{
    if ((nullptr == s) || (s->value >= v))
    {
        // s->value e' lecito. Se arrivo qui vuol dire che primo disgiunto
        // era falso, e quindi s diverso da nullptr
        insertFirstNode(s, v);
    }
    else
    {
        node *q = s;

        while ((q->next != nullptr) && (q->next->value <= v))
        {
            // Qui siamo sicuri che q != NULL, inoltre se prima condizione
            // e' soddisfatta possiamo accedere al campo value del node
            // successvo. Infatti e' diverso da NULL
            q = q->next;
        }
        node *r = new node;
        r->value = v;
        r->next = q->next;
        q->next = r;
    }
}

void removeFirstNode(node *&s)
{
    if (s != nullptr)
    {
        node *t = s;
        s = s->next;
        delete t;
    }
}

// remove node with the specified value
void removeNode(node *&p, int v)
{
    if (p != nullptr)
    {
        node *q = p;
        if (q->value == v)
        {
            p = p->next;
            delete q;
        }
        else
        {
            while (q->next != nullptr)
            {
                if (q->next->value == v)
                {
                    node *r = q->next;
                    q->next = q->next->next;
                    delete r;
                    return;
                }
                if (q->next != nullptr)
                {
                    q = q->next;
                }
            }
        }
    }
}

// Reverse con side effect sulla lista originaria, the side effect is
// just the first node remains
node *reverse(node *x)
{
    node *t;
    node *y = x;
    node *r = nullptr;

    while (y != nullptr)
    {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}

// Costruzione della lista rovesciata costruendo una lista nuova ==> senza side effect
node *copyReverse(node *x)
{
    node *r = nullptr;

    while (x != nullptr)
    {
        node *t = new node;
        t->value = x->value;
        t->next = r;
        r = t;
        x = x->next;
    }
    return r;
}

// Ricerca e ritorna l'elemento n-esimo se esite ==> se provi a stamparlo
// stamperai la lista da questo elemento fino in fondo alla lista
node *getNthNode(node *s, int nth)
{
    if (nth < 0)
    {
        return nullptr;
    }
    int i;
    for (i = 0;
         ((i < nth) && (s != nullptr));
         i++)
    {
        s = s->next;
    }
    return s;
}

// Ritornare il node che precede un node x. s è il primo nodo
node *prevNode(node *s, node *x)
{
    if (s == x)
    {
        return x;
    }
    if ((nullptr == s) && (nullptr == s->next)) // why?
    {
        return nullptr;
    }

    node *t = s;       // node precedente al node corrente che sto cercando,
                       // inizializzato al primo elemento della lista
    node *l = s->next; // node che uso per scorrere la lista,
                       // inizializzato al secondo elemento della
                       // lista.

    while ((l != nullptr) && (l != x))
    {
        // Modifico l e t per rispettare il loro significato, ovvero che t
        // punta l node che precede l
        t = l;
        l = l->next;
    }
    // raggiunto ultimo elemento e non c'e' nulla
    if (l == nullptr)
    {
        return nullptr;
    }
    return t;
}

node *concat(node *s1, node *s2)
{
    if (nullptr == s1)
    {
        return s2;
    }
    if (nullptr == s2)
    {
        return s1;
    }

    node *p = s1;

    while ((p != nullptr) && (p->next != nullptr))
    {
        p = p->next;
    }

    p->next = s2;

    return s1;
}

node *recConcat(node *s1, node *s2)
{
    if (nullptr == s1)
    {
        return s2;
    }
    s1->next = recConcat(s1->next, s2);
    return s1;
}

node *copySequence(node *s)
{
    if (nullptr == s)
    {
        return nullptr;
    }
    node *t = new node;
    t->value = s->value;
    t->next = copySequence(s->next);
    return t;
}

// attacca insieme 2 sottosequenze di liste
node *concatSubsequences(node *s1, node *s2)
{
    if (nullptr == s1)
    {
        return copySequence(s2);
    }
    if (nullptr == s2)
    {
        return copySequence(s1);
    }

    node *cs1 = copySequence(s1);
    node *cs2 = copySequence(s2);

    node *p;

    for (p = cs1; ((p != nullptr) && (p->next != nullptr)); p = p->next)
        ;

    p->next = cs2;

    return cs1;
}

node *recConcatSubsequences(node *s1, node *s2)
{
    if (nullptr == s1)
    {
        return copySequence(s2);
    }
    node *t = new node;
    t->value = s1->value;
    t->next = recConcatSubsequences(s1->next, s2);
    return t;
}

node *removeNextNode(node *&x)
{
    if (nullptr == x || nullptr == x->next)
    {
        return nullptr;
    }
    node *y = x->next;
    if (y->next != nullptr)
    {
        x->next = y->next;
        y->next = nullptr;
    }
    else
    {
        x->next = nullptr;
    }

    return y;
}