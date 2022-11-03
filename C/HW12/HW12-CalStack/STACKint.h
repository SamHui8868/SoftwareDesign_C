
#pragma once
typedef struct {

	int buf[16];
	int sp;
}STACKint;

void STACKint_initial(STACKint* p);
int isSTACKintempty(STACKint* p);
int isSTACKintfull(STACKint* p);
int pushint(STACKint* p, int c);
int popint(STACKint* p);