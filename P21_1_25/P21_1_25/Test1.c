#define _CRT_SECURE_NO_WARNINGS

//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* newArr = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int next = 1;
    int curSum = 0;
    int end = digitsSize - 1;

    while (end >= 0)
    {
        curSum = digits[end] + next;
        next = 0;
        if (curSum < 10)
        {
            newArr[end] = curSum;
            next = 0;
        }

        else
        {
            next = 1;
            newArr[end] = 0;
        }

        end--;
    }

    if (next == 1)
    {
        int i = digitsSize - 1;
        while (i >= 0)
        {
            newArr[i + 1] = newArr[i];
            i--;
        }

        newArr[0] = 1;
        *returnSize = digitsSize + 1;
    }

    else
    {
        *returnSize = digitsSize;
    }
    return newArr;
}