
#include <iostream>
#include<stdio.h>
#include"STACK.h"
#include"STACKint.h"
#include<string.h>
#include<stdlib.h>

  STACK op_stk;//stack of operand ,stack of op
 STACKint opnd_stk;
int priority(char op);
int calculate(char op, int opnd1, int opnd2);
void print_Stacks(void);
int step;
int main()
{
    int i;
    char c,opnd1,opnd2;
    char r;
    char buf[] = "3+2*6-7";
    STACKint_initial(&opnd_stk);
    STACK_initial(&op_stk);
    step = 1;
    printf("Calculate:");
    for(i=0;buf[i];i++)
    printf("%c", buf[i]);
    printf("\n\n");
    for (i = 0; buf[i]; i++)
    {
        if (i % 2==0)
        {
            pushint(&opnd_stk, (buf[i]-48));
            print_Stacks();
        }
        else {
            while (1) {
                  if (isSTACKempty(&op_stk))
                  {
                    push(&op_stk, buf[i]);
                    print_Stacks();
                    break;
                  }
                  else {
                    c = pop(&op_stk);
                    if (priority(c)<priority(buf[i]))
                    {
                        push(&op_stk,c);
                        push(&op_stk, buf[i]);
                        print_Stacks();
                        break;
                    }
                    else {
                        opnd2 = popint(&opnd_stk);
                        opnd1 = popint(&opnd_stk);
                        r = calculate(c, opnd1, opnd2);
                        pushint(&opnd_stk, r);
                        print_Stacks();
                     
                          }
                   }
            }
            }
                }
    opnd2 = popint(&opnd_stk);
    opnd1 = popint(&opnd_stk);
    r = calculate(pop(&op_stk), opnd1, opnd2);
    pushint(&opnd_stk, r);
     print_Stacks();
     printf("RESULT>>>>>>>>>>>");
     for (i = 0; buf[i]; i++)
     printf(" %c ", buf[i]);
     printf("   =  %d", popint(&opnd_stk));
            }
        



int priority(char op)
{
    int i = 0, v;
    const char* ops = "+-*/";
    int pv[] = { 1,1,2,2,-1 };
    v = -1;
    for (i = 0; ops[i] && ops[i] != op; i++);
    v = pv[i];
    return v;
}
int calculate(char op, int opnd1, int opnd2)
{
    int v = 0;

    switch (op) {
    case '+':
        v = opnd1 + opnd2;
        break;
    case '-':
        v = opnd1 - opnd2;
        break;
    case '*':
        v = opnd1 *opnd2;
        break;
    case '/':
        v = opnd1 / opnd2;
        break;
    }
    return v;
}
void print_Stacks(void)
{
    int i;
    printf("STEP[%d]\n",step);
    step++;
    printf("op_stk=[");
    for (i = 15; i >= op_stk.sp; i--)
        printf("%c, ", op_stk.buf[i]);
    printf("]\n");
    printf("opnd_stk=[");
    for (i = 15; i >= opnd_stk.sp; i--)
        printf("%d, ", opnd_stk.buf[i]);

    printf("]\n\n");

}




