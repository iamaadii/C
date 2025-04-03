#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int asso(char c)
{
    if (c == '^')
        return 1;
    else
        return 0;
}

void infixToPostfix(char s[])
{
    char postfix[MAX_SIZE];
    int j = 0;
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top >= 0 && (prec(s[i]) <= prec(stack[top]) && asso(s[i]) == 0))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("postfix : %s\n", postfix);
}

int main()
{
    char infix[MAX_SIZE];
    printf("enter infix expression : ");
    scanf("%s", infix);
    infixToPostfix(infix);
}
