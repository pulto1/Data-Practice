//给定一个整数数组，判断是否存在重复元素。
//
//如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

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
                if (a[end] > tmp)
                {
                    int ret = a[end + gap];
                    a[end + gap] = a[end];
                    a[end] = ret;
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

bool containsDuplicate(int* nums, int numsSize)
{
    ShellSort(nums, numsSize);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }

    }

    return false;
}