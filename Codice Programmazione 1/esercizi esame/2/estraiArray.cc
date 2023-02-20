#include <iostream>

#define MAXVALUE 100
#define MAXSIZE 100

using namespace std;

struct tree
{
    int info;
    tree *left;
    tree *right;
};

void insert(tree *&result, const int num)
{
    if (result == NULL)
    {
        result = new tree;
        result->info = num;
        result->left = NULL;
        result->right = NULL;
    }
    else if (result->info > num)
    {
        insert(result->left, num);
    }
    else
    {
        insert(result->right, num);
    }
}

tree *crea_tree(const int num)
{
    tree *result = NULL;
    for (int i = 0; i < num; i++)
    {
        insert(result, rand() % MAXVALUE);
    }
    return result;
}

void print_tree(const tree *root)
{
    if (root != NULL)
    {
        print_tree(root->right);
        std::cout << ' ' << root->info;
        print_tree(root->left);
    }
}

void delete_tree(tree *&root)
{
    if (root != NULL)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = NULL;
    }
}

void print_array(const int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

/* void get_len(tree *t, int &len1, int &len2)
{
    if (t == NULL)
    {
        return;
    }
    get_len(t->right, len1, len2);
    if (t->info % 2 == 0)
    {
        len1++;
    }
    else
    {
        len2++;
    }
    get_len(t->left, len1, len2);
}

void estrai_aux(tree *t, int *a1, int *a2, int &i1, int &i2)
{
    if (t == NULL)
    {
        return;
    }
    estrai_aux(t->left, a1, a2, i1, i2);
    if (t->info % 2 == 0)
    {
        a1[i1] = t->info;
        i1++;
    }
    else
    {
        a2[i2] = t->info;
        i2++;
    }
    estrai_aux(t->right, a1, a2, i1, i2);
}

void estrai(tree *t, int *&a1, int *&a2, int &len1, int &len2)
{
    get_len(t, len1, len2);
    a1 = new int[len1];
    a2 = new int[len2];
    int i1 = 0;
    int i2 = 0;
    estrai_aux(t, a1, a2, i1, i2);
}
 */

void get_len(tree *t, int &len1, int &len2)
{
    if (t == nullptr)
    {
        return;
    }
    get_len(t->right, len1, len2);
    if (t->info % 2 == 0)
    {
        len1++;
    }
    else
    {
        len2++;
    }
    get_len(t->left, len1, len2);
}

void estrai_aux(tree *t, int *&a1, int *&a2, int &idx1, int &idx2)
{
    if (t == nullptr)
    {
        return;
    }

    estrai_aux(t->right, a1, a2, idx1, idx2);
    if (t->info % 2 == 0)
    {
        a1[idx1] = t->info;
        idx1++;
    }
    else
    {
        a2[idx2] = t->info;
        idx2++;
    }
    estrai_aux(t->left, a1, a2, idx1, idx2);
}

void estrai(tree *t, int *&a1, int *&a2, int &len1, int &len2)
{
    get_len(t, len1, len2);
    // allocate space for arrays
    a1 = new int[len1];
    a2 = new int[len2];
    int idx1 = 0;
    int idx2 = 0;
    estrai_aux(t, a1, a2, idx1, idx2);
}

int main(int argc, char **argv)
{
    srand(0);
    tree *root = crea_tree(rand() % MAXSIZE);
    cout << "Initial tree content: ";
    print_tree(root);
    cout << endl;

    int len1 = 0, len2 = 0;
    int *a1;
    int *a2;

    estrai(root, a1, a2, len1, len2);

    delete_tree(root);

    cout << "A1 = ";
    print_array(a1, len1);

    cout << "A2 = ";
    print_array(a2, len2);

    return 0;
}
