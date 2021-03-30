#define _CRT_SECURE_NO_WARNINGS

//给定一组字符，使用原地算法将其压缩。
//
//压缩后的长度必须始终小于或等于原数组长度。
//
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//
//在完成原地修改输入数组后，返回数组的新长度。

char IntToChar(int dec)
{
    char ret;

    if (dec == 0)
        ret = '0';
    if (dec == 1)
        ret = '1';
    if (dec == 2)
        ret = '2';
    if (dec == 3)
        ret = '3';
    if (dec == 4)
        ret = '4';
    if (dec == 5)
        ret = '5';
    if (dec == 6)
        ret = '6';
    if (dec == 7)
        return '7';
    if (dec == 8)
        ret = '8';
    if (dec == 9)
        ret = '9';

    return ret;
}

int compress(char* chars, int charsSize)
{
    int cur = 0;
    int prev = -1;
    int returnSize = 0;
    int flag = 0;
    while (cur < charsSize)
    {

        chars[++prev] = chars[cur];
        returnSize++;

        int count = 0;
        while (cur < charsSize && chars[prev] == chars[cur])
        {
            count++;
            cur++;
        }
        int ret = count;
        int tmp = 0;

        count = 0;

        while (ret > 0)
        {
            count = (count * 10) + (ret % 10);
            ret /= 10;
            tmp++;
        }

        if (count != 1 || tmp > 1)
        {
            int dec = 0;
            while (tmp--)
            {
                chars[++prev] = IntToChar(count % 10);
                returnSize++;
                count /= 10;
            }
        }
        flag++;
    }

    return returnSize;
}