#define _CRT_SECURE_NO_WARNINGS

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回 [-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* returnArr = (int*)malloc(sizeof(int) * 2);
    int later = 0;
    int prev = 0;

    if (numsSize == 0)
    {
        returnArr[0] = -1;
        returnArr[1] = -1;
    }

    else
    {
        while (later < numsSize)
        {
            if (nums[later] != target)
            {
                later++;
                continue;
            }

            else
            {
                prev = later;
                while (later < numsSize && nums[later] == target)
                {
                    later++;
                }
                later--;
            }

            break;
        }

        if (nums[prev] != target)
        {
            returnArr[0] = -1;
            returnArr[1] = -1;
        }

        else
        {
            returnArr[0] = prev;
            returnArr[1] = later;
        }
    }
    return returnArr;
}