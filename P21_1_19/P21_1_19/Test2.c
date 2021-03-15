#define _CRT_SECURE_NO_WARNINGS

//����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��
//
//��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ�������������磬121 �ǻ��ģ��� 123 ���ǡ�


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