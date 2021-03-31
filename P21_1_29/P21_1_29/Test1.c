#define _CRT_SECURE_NO_WARNINGS

//����һ���������� nums ������Ҫ�ҳ�һ�� ���������� �����������������������������ô�������鶼���Ϊ��������
//
//�����ҳ���������� ��� �����飬��������ĳ��ȡ�


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