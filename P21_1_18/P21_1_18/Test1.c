#define _CRT_SECURE_NO_WARNINGS

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。

int searchInsert(int* nums, int numsSize, int target)
{
	int i = 0;

	for (i = 0; i < numsSize; i++)
	{
		if (target <= nums[i])
			return i;
	}

	return i;
}