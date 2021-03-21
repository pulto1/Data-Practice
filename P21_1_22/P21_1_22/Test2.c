#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

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