struct node
{
    int value;
    node *next;
};

// inserire elemento nel mezzo
void insertNode(node *v1, node *v2)
{
    v2->next = v1->next;
    v1->next = v2;
}

// inserire elemento in testa
void insertFirstNode(node *s, int v)
{
    node *n = new node;
    n->value = v;
    n->next = s;
    s = n;
}

void insertFirstNodeV2(node *&s, int v)
{
    node *n = new node;
    n->value = v;
    n->next = s;
    s = n;
}

node *insertFirstNodeV3(node *s, int v)
{
    node *n = new node;
    n->value = v;
    n->next = s;

    return n;
}

// inserire elemento in coda
void insertLastNode(node *&p, int n)
{
    node *r = new node;
    r->value = n;
    r->next = nullptr;

    if (p != nullptr)
    {
        node *q = p;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = r;
    }
    else
    {
        p = r;
    }
}

// rimuovere elemento
node *removeNode(node *x)
{
    node *y = x->next;
    x->next = y->next;
    y->next = nullptr;

    return y; // Lo ritorno per poter essere deallocato
    /*
        es:
        node *t = removeNode(x);
        delete t; // !
    */
}