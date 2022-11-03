#include"STACK.h"

void STACK_initial(STACK* p)
{
	int i;
	for (i = 0; p->buf[i];i++)
	{
		p->buf[i] = 0x00;
	}
	p->sp = 16;
}

int isSTACKempty(STACK* p)
{
	if (p->sp == 16)return 1;
	return 0;
}

int isSTACKfull(STACK* p)
{
	if (p->sp == 0)return 1;
	return 0;
}

char push(STACK* p, char c)
{
	if (isSTACKfull(p) == 1)return 0;

	(*p).buf[--(p->sp)] = c;
	return c;
}
char pop(STACK* p)
{
	char c;
	if (isSTACKempty(p) == 1)return 0;
	c = (*p).buf[(p->sp)++];
	return c;
}
