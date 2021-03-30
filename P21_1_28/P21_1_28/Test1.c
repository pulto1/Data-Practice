#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。

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