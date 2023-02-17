#include <iostream>
#include <time.h>

using namespace std;

void initializeArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        *(arr + i) = rand() % 10;
    }
}

bool isSubArray(int *parentArr, int *childArr, int parentDim, int childDim, int currParentIdx = 0, int currChildIdx = 0)
{
    if (currParentIdx == parentDim)
    {
        return false;
    }
    if (currChildIdx > 0 && parentArr[currParentIdx] != childArr[currChildIdx])
    {
        return false;
    }
    if (childArr[currChildIdx] == parentArr[currParentIdx])
    {
        currChildIdx++;
        if (currChildIdx == childDim)
        {
            return true;
        }
    }
    currParentIdx++;
    return isSubArray(parentArr, childArr, parentDim, childDim, currParentIdx, currChildIdx);
}

int main()
{
    srand(time(NULL));
    int len1 = rand() % 100 + 1;
    int len2 = rand() % 100 + 1;
    int *parentArr;
    int *childArr;
    int parentDim = 0, childDim = 0;
    if (len1 >= len2)
    {
        parentArr = new int[len1];
        childArr = new int[len2];
        parentDim = len1;
        childDim = len2;
    }
    else
    {
        parentArr = new int[len2];
        childArr = new int[len1];
        parentDim = len2;
        childDim = len1;
    }
    initializeArray(parentArr, parentDim);
    initializeArray(childArr, childDim);

    if (isSubArray(parentArr, childArr, parentDim, childDim))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}