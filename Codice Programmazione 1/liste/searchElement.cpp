struct node
{
    int value;
    node *next;
};

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