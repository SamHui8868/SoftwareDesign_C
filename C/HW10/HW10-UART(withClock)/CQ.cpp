#include"CQ.h"

void CQ_initial(CQueue* p)
{

	p->front = p->tail = 0;
}

int isCQempty(CQueue* p)
{
	if (p->front == p->tail)return 1;
	return 0;
}

char insertCQ(CQueue* p, char c)
{
	p->buf[p->tail] = c;
	p->tail = (p->tail + 1) & 0x0FF;
	return c;
}

char deleteCQ(CQueue* p)
{
	char c;
	if (isCQempty(p) == 1)return 0;
	c = p->buf[p->front];
	p->front=(p->front+1) & 0x0FF;
	return c;
}
