struct node
{
    int value;
    node *next;
};

void deallocalist(node *n)
{
    node *temp;
    while (n != nullptr)
    {
        temp = n->next;
        delete n;
        n = temp;
    }
}

void deallocalist(node *n)
{
    if (n == nullptr)
        return;
    deallocalist(n->next);
    delete n;
}

void deallocalist(node *n)
{
    node *temp;
    while (n != nullptr)
    {
        temp = n;
        n = n->next;
        delete temp;
    }
}
