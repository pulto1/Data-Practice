#define _CRT_SECURE_NO_WARNINGS

//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��

void Swap(char* x, char* y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

char* reverseOnlyLetters(char* S)
{
    int left = 0;
    int right = strlen(S) - 1;

    while (left < right)
    {
        if (isalpha(S[left]) && isalpha(S[right]))
        {
            Swap(&S[left], &S[right]);
            left++;
            right--;
        }

        else
        {
            if (isalpha(S[left]) == 0)
            {
                left++;
            }

            if (isalpha(S[right]) == 0)
            {
                right--;
            }
        }
    }

    return S;
}