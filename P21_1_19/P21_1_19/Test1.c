#define _CRT_SECURE_NO_WARNINGS

//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�
//������Թ��ɣ����� true �����򷵻� false��
//
//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)


typedef char SLDateType;
typedef struct SeqList
{
    SLDateType* a;
    int size;
}SeqList;

//˳���ĳ�ʼ��
void SeqListInit(SeqList* ps, int size)
{
    ps->a = (SLDateType*)malloc(size * sizeof(SLDateType));
    ps->size = 0;
}

//˳��������
void SeqListDestory(SeqList* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
}

//˳����β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
    int start = pos;
    while (start < ps->size - 1)
    {
        ps->a[start] = ps->a[start + 1];
        ++start;
    }

    ps->size--;
}


bool canConstruct(char* ransomNote, char* magazine)
{

    int size1 = strlen(ransomNote);
    int size2 = strlen(magazine);

    if (size1 > size2)
        return false;

    SeqList ra;
    SeqListInit(&ra, size1 + 1);

    while (*ransomNote)
    {
        SeqListPushBack(&ra, *ransomNote);
        ransomNote++;
    }
    SeqListPushBack(&ra, '\0');

    SeqList ma;
    SeqListInit(&ma, size2 + 1);

    while (*magazine)
    {
        SeqListPushBack(&ma, *magazine);
        magazine++;
    }

    SeqListPushBack(&ma, '\0');

    for (int i = 0; i < ra.size - 1; i++)
    {
        for (int j = 0; j < ma.size - 1; j++)
        {
            if (ra.a[i] == ma.a[j])
            {
                SeqListErase(&ra, i);
                i--;
                SeqListErase(&ma, j);
                break;
            }
        }
    }

    if (ra.size == 1)
    {
        SeqListDestory(&ra);
        SeqListDestory(&ma);
        return true;
    }


    else
    {
        SeqListDestory(&ra);
        SeqListDestory(&ma);
        return false;
    }
}