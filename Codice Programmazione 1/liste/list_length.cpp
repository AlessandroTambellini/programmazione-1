struct nodo
{
    int valore;
    nodo *next;
};

// lista lineare
int length(nodo *s)
{
    int len = 0;
    for (; s != nullptr; s = s->next)
    {
        len++;
    }
    return len;
}

// ricorsiva
int recLength(nodo *s)
{
    if (s == nullptr)
        return 0;
    return 1 + length(s->next);
}

// lista circolare
int circularLength(nodo *s, nodo *x)
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

// lista circolare --> is not right, to redo
int lengthV2(nodo *s)
{
    if (s == nullptr)
    {
        return 0;
    }

    nodo x = *s;
    int len = 1;
    for (; s != &x; s = s->next)
    {
        len++;
    }

    return len;
}