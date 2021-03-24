#define _CRT_SECURE_NO_WARNINGS

//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (a[end] < tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}

				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

int thirdMax(int* nums, int numsSize)
{
	ShellSort(nums, numsSize);
	int thirdMax = nums[0];
	int count = 2;
	int i = 0;
	while (i < numsSize && count > 0)
	{
		if (thirdMax == nums[i])
		{
			i++;
		}

		else
		{
			thirdMax = nums[i];
			count--;
			i++;
		}
	}

	if (count == 0)
		return nums[i - 1];

	return nums[0];
}