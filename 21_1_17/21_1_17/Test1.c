#define _CRT_SECURE_NO_WARNINGS

//ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����

char * toLowerCase(char * str)
{
	char* start = str;

	while (*str)
	{
		*str = tolower(*str);
		str++;
	}

	return start;
}