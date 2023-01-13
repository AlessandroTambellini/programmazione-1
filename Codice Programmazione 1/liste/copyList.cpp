struct node
{
    int value;
    node *next;
};

void copyList(node *x, node *newX)
{
    node *currNode = newX;
    for (; x != nullptr; x = x->next)
    {
        currNode->value = x->value;
        if (x->next == nullptr)
        {
            currNode->next = nullptr;
        }
        else
        {
            currNode->next = new node;
            currNode = currNode->next;
        }
    }
}