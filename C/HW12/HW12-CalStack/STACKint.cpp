#include"STACKint.h"

void STACKint_initial(STACKint* p)
{
	int i;
	for (i = 0; p->buf[i]; i++)
	{
		p->buf[i] = 0;
	}
	p->sp = 16;
}

int isSTACKintempty(STACKint* p)
{
	if (p->sp == 16)return 1;
	return 0;
}

int isSTACKintfull(STACKint* p)
{
	if (p->sp == 0)return 1;
	return 0;
}

int pushint(STACKint* p, int c)
{
	if (isSTACKintfull(p) == 1)return 0;

	(*p).buf[--(p->sp)] = c;
	return c;
}
int popint(STACKint* p)
{
	int c;
	if (isSTACKintempty(p) == 1)return 0;
	c = (*p).buf[(p->sp)];
	(*p).buf[(p->sp)] = 0x00;
	(p->sp)++;
	return c;
}