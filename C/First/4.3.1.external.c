#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP   100  //操作数或运算符的最大长度
#define NUMBER  '0' //标识找到一个数
#define NAME    'n'

int getch();
void ungetch(int);

int getop(char[]);
void push(double);
double pop(void);

void clear();
void mathfnc(char s[]);
void ungets(char s[]);

int main()
{
    int type, var = 0;
    double op1, op2, v;
    char s[MAXOP];

    double variable[26] = {0.0};

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
            {
                variable[var - 'A'] = pop();
            }
            else
            {
                printf("error: no variable name\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '?':   /* print top element of the stack */
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':   /* duplicate top element of the stack */
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':   /* swap the top two elements */
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
            {
                push(variable[type - 'A']);
            }
            else if (type == 'v')
            {
                push(v);
            }
            printf("error: unkown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}

#define MAXVAL 100  //栈vol的最大深度

int sp = 0;         //下一个空闲的栈位置
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop()
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

//获得下一个运算符或数值操作数
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
        {
            ungetch(c);
        }
        if (strlen(s) > 1)
        {
            return NAME;
        }
        else
        {
            return c;
        }
    }
    if (!isdigit(c) && c!= '.' && c!= '-')
    {
        return c;
    }
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

//取一个字符
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//把字符压回到输入中
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else{
        buf[bufp++] = c;
    }
}

void clear()
{
    sp = 0;
}

void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0)
    {
        push(cos(pop()));
    }
    else if (strcmp(s, "exp") == 0)
    {
        push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
    {
        printf("error: %s not supported\n", s);
    }
}

/* push string back onto the input */
void ungets(char s[])
{
    int len = strlen(s);
    void ungetch(int);
    while (len > 0)
    {
        ungetch(s[--len]);
    }
}
