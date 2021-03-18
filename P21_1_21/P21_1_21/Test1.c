//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

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