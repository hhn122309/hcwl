#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 100
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
#define true 1
#define false 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define OPSETSIZE 7
 
typedef int Status;
typedef char Status1;
typedef int SElemType;
typedef char SElemType1;
typedef struct
{
    SElemType *base;
    SElemType  *top;
    int stacksize;
} SqStack;
typedef struct
{
    SElemType1 *base;
    SElemType1  *top;
    int stacksize;
} SqStack1;
char prior[7][7] =
{
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '<', '<', '<', '<', '<', '=', ' ',
    '>', '>', '>', '>', ' ', '>', '>',
    '<', '<', '<', '<', '<', ' ', '='
};
char OPSET[7] = { '+', '-', '*', '/', '(', ')', '#' };
 
 
Status InitStack(SqStack *S);
Status1 InitStack1(SqStack1 *S);
Status Push(SqStack *S, SElemType e);
Status1 Push1(SqStack1 *S, SElemType1 e);
Status Pop();
Status1 Pop1();
Status StackEmpty();
Status1 StackEmpty1();
Status In(Status1 c);
Status GetPos(Status1 c);
Status GetTop(SqStack S);
Status1 GetTop1(SqStack1 S);
Status1 precede(Status1 a, Status1 b);
Status Operate(Status a, Status1 theta, Status b);
Status EvaluateExpression();
Status TenPow(Status i);
 
 
 
int main()
{
    printf("%d\n",EvaluateExpression());
    return 0;
}
 
 
 
Status In(Status1 c)
{
    int i;
    for (i = 0; i < 7; i++)
        if (OPSET[i] == c)
            return true;
    return false;
}
 
Status GetPos(Status1 c)
{
    int i;
    for (i = 0; i < 7; i++)
        if (OPSET[i] == c)
            return i;
    return false;
}
 
Status GetTop(SqStack S)
{
    return *(S.top-1);
}
 
Status1 GetTop1(SqStack1 S)
{
    return *(S.top-1);
}
 
Status1 precede(Status1 a, Status1 b)
{
    return prior[GetPos(a)][GetPos(b)]; // 返回运算符比较的结果
}
 
Status Operate(Status a, Status1 theta, Status b)
{
    switch (theta)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}
 
Status EvaluateExpression()
{
    SqStack1 OPTR;                      // 运算符寄存器
    SqStack OPND;                       // 操作数寄存器
    Status a, b;
    Status1 theta, c, x;
    InitStack1(&OPTR);                  // 初始化OPTR栈
    Push1(&OPTR, '#');                  // 压栈"#"
    InitStack(&OPND);                   // 初始化OPND栈
    printf("请利用+-*/()输入一个多项式并以#结尾\n");
    c = getchar();
    while (c != '#' || GetTop1(OPTR) != '#')
    {
        if (!In(c))                     // 不是运算符则进栈
        {
            Status sum = 0, i = 0;
            SqStack S;
            InitStack(&S);
            Push(&S, c - '0');
            c = getchar();
            while(!In(c))
            {
                Push(&S, c - '0');
                c=getchar();
            }
            while(!StackEmpty(S))
            {
                Status temp;
                Pop(&S, &temp);
                sum += temp * TenPow(i++);
            }
            Push(&OPND, sum);
        }
        else
        {
            switch (precede(GetTop1(OPTR), c)) // 判断运算符栈顶运算符与读入运算符之间的优先关系
            {
            case '<':                   // 栈顶元素优先权低
                Push1(&OPTR, c);
                c = getchar();
                break;
            case '=':                   // 脱括号并接收下一字符
                Pop1(&OPTR, &x);
                c = getchar();
                break;
            case '>':                   // 退栈并将运算结果入栈
                Pop1(&OPTR, &theta);
                Pop(&OPND, &b);
                Pop(&OPND, &a);
                Push(&OPND, Operate(a, theta, b));
                break;
            }                           // switch
        }
    }                                   // while
    return GetTop(OPND);
}                                       // EvaluateExpression
 
Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof (SElemType));
    if (!S->base) exit (OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status1 InitStack1(SqStack1 *S)
{
    S->base = (SElemType1 *)malloc(STACK_INIT_SIZE*sizeof (SElemType1));
    if (!S->base) exit (OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
 
Status Push(SqStack *S, SElemType e)
{
    if (S->top - S->base >= S->stacksize) //栈满
    {
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)* sizeof(SElemType));
        if (!S->base) exit (OVERFLOW);
        S->top   = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }  // if
    *S->top++ = e;
    return OK;
}  //Push
Status1 Push1(SqStack1 *S, SElemType1 e)
{
    if (S->top - S->base >= S->stacksize) //栈满
    {
        S->base = (SElemType1 *)realloc(S->base, (S->stacksize + STACKINCREMENT)* sizeof(SElemType1));
        if (!S->base) exit (OVERFLOW);
        S->top   = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }  // if
    *S->top++ = e;
    return OK;
}  //Push
 
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == S->base)return ERROR;
    *e = *--S->top;
    return OK;
} //Pop
Status1 Pop1(SqStack1 *S, SElemType1 *e)
{
    if(S->top == S->base)return ERROR;
    *e = *--S->top;
    return OK;
} //Pop
Status StackEmpty(SqStack S)
{
    if (S.base == S.top)
        return TRUE;
    return FALSE;
}
Status1 StackEmpty1(SqStack1 S)
{
    if (S.base == S.top)
        return TRUE;
    return FALSE;
}
 
Status TenPow(Status i)
{
    Status sum = 1;
    while(i--)
        sum*=10;
    return sum;
}