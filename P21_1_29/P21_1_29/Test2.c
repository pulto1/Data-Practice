#define _CRT_SECURE_NO_WARNINGS

//根据 逆波兰表示法，求表达式的值。
//
//有效的算符包括  + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//
//
//说明：
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
    STDataType* _a;
    int _top;		// 栈顶
    int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
    assert(ps);

    ps->_a = (STDataType*)malloc(4 * sizeof(STDataType));
    ps->_capacity = 4;
    ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
    assert(ps);

    if (ps->_capacity == ps->_top)
    {
        ps->_capacity *= 2;
        STDataType* ret = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
        if (ret == NULL)
        {
            free(ps);
            ps = NULL;
            exit(-1);
        }

        else
        {
            ps->_a = ret;
        }
    }

    ps->_a[ps->_top] = data;
    ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
    assert(ps);
    assert(ps->_top != 0);

    ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(ps->_top != 0);

    return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
    assert(ps);

    return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
    assert(ps);

    return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
    free(ps->_a);
    ps->_a = NULL;
}


int evalRPN(char** tokens, int tokensSize)
{
    Stack st;
    StackInit(&st);

    int i = 0;
    while (i < tokensSize)
    {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i][1] != '\0'))
        {
            int j = 0;
            int dec = 0;
            while (tokens[i][j] != '\0')
            {
                dec = atoi(tokens[i]);
                j++;
            }

            StackPush(&st, dec);
        }

        else
        {
            int num1 = StackTop(&st);
            StackPop(&st);
            int num2 = StackTop(&st);
            StackPop(&st);

            if (tokens[i][0] == '+')
            {
                StackPush(&st, num1 + num2);
            }

            if (tokens[i][0] == '-')
            {
                StackPush(&st, num2 - num1);
            }

            if (tokens[i][0] == '*')
            {
                StackPush(&st, num2 * num1);
            }

            if (tokens[i][0] == '/')
            {
                StackPush(&st, num2 / num1);
            }
        }
        i++;
    }
    int sum = StackTop(&st);
    StackDestroy(&st);

    return sum;
}