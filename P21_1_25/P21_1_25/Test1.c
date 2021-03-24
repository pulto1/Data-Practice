#define _CRT_SECURE_NO_WARNINGS

//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* newArr = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int next = 1;
    int curSum = 0;
    int end = digitsSize - 1;

    while (end >= 0)
    {
        curSum = digits[end] + next;
        next = 0;
        if (curSum < 10)
        {
            newArr[end] = curSum;
            next = 0;
        }

        else
        {
            next = 1;
            newArr[end] = 0;
        }

        end--;
    }

    if (next == 1)
    {
        int i = digitsSize - 1;
        while (i >= 0)
        {
            newArr[i + 1] = newArr[i];
            i--;
        }

        newArr[0] = 1;
        *returnSize = digitsSize + 1;
    }

    else
    {
        *returnSize = digitsSize;
    }
    return newArr;
}