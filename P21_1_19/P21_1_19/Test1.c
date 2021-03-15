#define _CRT_SECURE_NO_WARNINGS

//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
//如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)


typedef char SLDateType;
typedef struct SeqList
{
    SLDateType* a;
    int size;
}SeqList;

//顺序表的初始化
void SeqListInit(SeqList* ps, int size)
{
    ps->a = (SLDateType*)malloc(size * sizeof(SLDateType));
    ps->size = 0;
}

//顺序表的销毁
void SeqListDestory(SeqList* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
}

//顺序表的尾插
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