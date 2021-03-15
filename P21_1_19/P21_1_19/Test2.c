#define _CRT_SECURE_NO_WARNINGS

//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。


bool isPalindrome(int x)
{

    if (x < 0)
        return false;

    int retX = x;
    unsigned int invertX = 0;


    while (retX)
    {
        invertX = invertX * 10 + (retX % 10);
        retX /= 10;
    }

    if (x == invertX)
        return true;

    else
        return false;
}