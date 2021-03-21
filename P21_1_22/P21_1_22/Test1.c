#define _CRT_SECURE_NO_WARNINGS

//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int i = 0;
    while (nums[i] < 0)
    {
        nums[i] *= -1;
        i++;
        if (i == numsSize)
            break;
    }

    int* sortArr = (int*)malloc(sizeof(int) * numsSize);

    int later = i;
    int prev = i - 1;
    i = 0;
    while (later < numsSize && prev >= 0)
    {
        if (nums[prev] < nums[later])
        {
            sortArr[i] = nums[prev] * nums[prev];
            prev--;
            i++;
        }

        else
        {
            sortArr[i] = nums[later] * nums[later];
            later++;
            i++;
        }
    }

    if (later == numsSize)
    {
        while (prev >= 0)
        {
            sortArr[i] = nums[prev] * nums[prev];
            prev--;
            i++;
        }
    }

    if (prev == -1)
    {
        while (later < numsSize)
        {
            sortArr[i] = nums[later] * nums[later];
            later++;
            i++;
        }
    }
    return sortArr;
}