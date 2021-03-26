#define _CRT_SECURE_NO_WARNINGS

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//
//你可以按任意顺序返回答案。
/*
* Note: The returned array must be malloced, assume caller calls free().
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* returnArr = (int*)malloc(sizeof(int) * 2);
    int i1 = 0;
    int i2 = 0;

    while (i1 < numsSize)
    {
        i2 = i1 + 1;
        while (i2 < numsSize)
        {

            if (nums[i1] + nums[i2] == target)
                break;

            else
                i2++;
        }

        if (i2 != numsSize)
            break;
        i1++;
    }

    *returnSize = 2;
    returnArr[0] = i1;
    returnArr[1] = i2;

    return returnArr;
}