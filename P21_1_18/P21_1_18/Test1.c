#define _CRT_SECURE_NO_WARNINGS

//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//����Լ������������ظ�Ԫ�ء�

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