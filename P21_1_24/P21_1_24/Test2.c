#define _CRT_SECURE_NO_WARNINGS

//给你一个整数数组 nums，请编写一个能够返回数组 “中心下标” 的方法。
//
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果数组不存在中心下标，返回 - 1 。如果数组有多个中心下标，应该返回最靠近左边的那一个。
//
//注意：中心下标可能出现在数组的两端。

int pivotIndex(int* nums, int numsSize)
{
    int sumArr = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)//求数组所有元素的和
    {
        sumArr += nums[i];
    }

    int leftSum = 0;
    for (i = 0; i < numsSize; i++)//判断，以当前元素下标为i的元素为轴，判断左右两边元素和是否相等。
    {
        if ((leftSum * 2) == (sumArr - nums[i])) //左右和相等，左和*2等于总和减轴
            return i;

        leftSum += nums[i];
    }

    return -1;
}