#define _CRT_SECURE_NO_WARNINGS

//给你两个二进制字符串，返回它们的和（用二进制表示）。
//
//输入为 非空 字符串且只包含数字 1 和 0。

void reserve(char* a)
{
    int left = 0;
    int right = strlen(a) - 1;

    while (left < right)
    {
        char tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;

        left++;
        right--;
    }
}

char* addBinary(char* a, char* b)
{
    reserve(a);
    reserve(b);

    int size = strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2;
    char* c = (char*)malloc(sizeof(char) * size);

    char next = '0';
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] == '0' && b[i] == '0' && next == '0')
        {
            c[i] = '0';
            next = '0';
            i++;
            continue;
        }

        if (a[i] == '0' && b[i] == '0' && next == '1')
        {
            c[i] = '1';
            next = '0';
            i++;
            continue;
        }

        if ((a[i] == '1' && b[i] == '0' && next == '0') || (a[i] == '0' && b[i] == '1' && next == '0'))
        {
            c[i] = '1';
            next = '0';
            i++;
            continue;
        }

        if ((a[i] == '1' && b[i] == '0' && next == '1') || (a[i] == '0' && b[i] == '1' && next == '1'))
        {
            c[i] = '0';
            next = '1';
            i++;
            continue;
        }

        if (a[i] == '1' && b[i] == '1' && next == '0')
        {
            c[i] = '0';
            next = '1';
            i++;
            continue;
        }

        if (a[i] == '1' && b[i] == '1' && next == '1')
        {
            c[i] = '1';
            next = '1';
            i++;
            continue;
        }

    }

    while (a[i] != '\0' && i < strlen(a))
    {
        if (a[i] == '0' && next == '0')
        {
            c[i] = '0';
            next = '0';
            i++;
            continue;
        }

        if ((a[i] == '0' && next == '1') || (a[i] == '1' && next == '0'))
        {
            c[i] = '1';
            next = '0';
            i++;
            continue;
        }

        if (a[i] == '1' && next == '1')
        {
            c[i] = '0';
            next = '1';
            i++;
            continue;
        }
    }

    while (i < strlen(b) && b[i] != '\0')
    {
        if (b[i] == '0' && next == '0')
        {
            c[i] = '0';
            next = '0';
            i++;
            continue;
        }

        if ((b[i] == '0' && next == '1') || (b[i] == '1' && next == '0'))
        {
            c[i] = '1';
            next = '0';
            i++;
            continue;
        }

        if (b[i] == '1' && next == '1')
        {
            c[i] = '0';
            next = '1';
            i++;
            continue;
        }
    }

    if (next == '1')
    {
        c[i] = '1';
        i++;
    }

    c[i] = '\0';
    reserve(c);
    return c;
}