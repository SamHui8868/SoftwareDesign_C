#pragma once
typedef struct {

	char buf[16];
	int sp;
}STACK;

void STACK_initial(STACK* p);
int isSTACKempty(STACK* p);
int isSTACKfull(STACK* p);
char push(STACK* p, char c);
char pop(STACK* p);
