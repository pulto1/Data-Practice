#define _CRT_SECURE_NO_WARNINGS

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;
    int* NewArr = (int*)malloc(sizeof(int) * ASize);

    int begin = 0;
    int end = ASize - 1;
    int i = 0;
    for (i = 0; i < ASize; i++)
    {
        if (A[i] % 2 == 0)
        {
            NewArr[begin] = A[i];
            begin++;
        }

        else
        {
            NewArr[end] = A[i];
            end--;
        }
    }

    return NewArr;
}