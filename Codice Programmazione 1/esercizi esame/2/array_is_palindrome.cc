#include <iostream>

using namespace std;

bool isPalindrome(int *arr, int end, int start = 0)
{
    if (start >= end)
    {
        return true;
    }
    if (arr[start] != arr[end])
    {
        return false;
    }
    else
    {
        end--;
        start++;
        return isPalindrome(arr, end, start);
    }
}

int main()
{
    int dim = 0;
    cout << "Input a sequence of numbers." << endl
         << "Specify the dimension: " << endl;
    cin >> dim;

    if (dim < 0)
    {
        cout << "The length of the sequence cannot be negative" << endl;
        exit(EXIT_FAILURE);
    }

    int *arr = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        cin >> arr[i];
    }

    if (isPalindrome(arr, dim - 1))
    {
        cout << "The sequence of numbers is palindrome" << endl;
    }
    else
    {
        cout << "The sequence of numbers is NOT palindrome" << endl;
    }
    return 0;
}