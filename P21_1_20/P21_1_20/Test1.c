#define _CRT_SECURE_NO_WARNINGS

//给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

int lengthOfLastWord(char* s)
{

    while (*s == ' ')
    {
        s++;
    }

    if (*s == '\0')
        return 0;

    char* fast = s;
    char* slow = s;

    while (*fast)
    {
        if (*fast == ' ')
        {
            int count = 0;
            while (*fast == ' ')
            {
                count++;
                fast++;
            }

            if (*fast != '\0')
            {
                slow = fast;
            }

            else
            {
                slow += count;
            }

        }

        else
        {
            fast++;
        }

    }

    return strlen(slow);
}