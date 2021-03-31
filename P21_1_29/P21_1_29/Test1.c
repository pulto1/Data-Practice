#define _CRT_SECURE_NO_WARNINGS

//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
//请你找出符合题意的 最短 子数组，并输出它的长度。


int getMax(int* a, int left, int right)
{
    int max = a[left];
    for (int i = left + 1; i <= right; i++)
    {
        if (max < a[i])
            max = a[i];
    }

    return max;
}

int getMin(int* a, int left, int right)
{
    int min = a[left];
    for (int i = left + 1; i <= right; i++)
    {
        if (min > a[i])
            min = a[i];
    }

    return min;
}

int findUnsortedSubarray(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        int min = getMin(nums, left, right);

        if (nums[left] == min)
            left++;
        else
            break;
    }

    while (left <= right)
    {
        int max = getMax(nums, left, right);

        if (nums[right] == max)
            right--;
        else
            break;
    }

    return right - left + 1;
}