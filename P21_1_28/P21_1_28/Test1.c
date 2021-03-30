#define _CRT_SECURE_NO_WARNINGS

//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

bool isPalindrome(char* s)
{
    while (!isdigit(*s) && !isalpha(*s) && *s != '\0')
    {
        s++;
    }

    int left = 0;
    int right = strlen(s) - 1;

    if (right == -1 || right == 0)
        return true;

    bool flag = true;

    while (left < right)
    {
        if ((isdigit(s[left]) || isalpha(s[left])) && (isdigit(s[right]) || isalpha(s[right])))
        {
            if (toupper(s[left]) == toupper(s[right]))
            {
                left++;
                right--;
            }

            else
            {
                flag = false;
            }
        }

        else
        {
            if (!isdigit(s[left]) && !isalpha(s[left]))
                left++;

            if (!isdigit(s[right]) && !isalpha(s[right]))
                right--;
        }

        if (flag == false)
            break;
    }

    return flag;
}