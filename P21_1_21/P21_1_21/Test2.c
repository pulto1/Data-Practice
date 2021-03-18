#define _CRT_SECURE_NO_WARNINGS

//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。


bool isLongPressedName(char* name, char* typed)
{
    while (*name)
    {
        if (*name != *typed)
            return false;

        while (*name == *typed)
        {
            if (*name == *(name + 1))
            {
                name++;
                typed++;
                if (*name != *typed)
                    return false;
            }

            else
            {
                typed++;
            }
        }
        name++;
    }

    if (*typed != '\0')
        return false;

    return true;
}