#include<stdio.h>
#include<stdlib.h>

int GCD(int A, int B);
int main(int argc, char* argv[])
{
	int i,n,A,B;
	
	printf("ARGC=%d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d]=<%s>\n", i, argv[i]);

	}
	if (argc != 3)
	{
		printf("Ussage:GCD A B\n");
		exit(0);   
	}
	sscanf_s(argv[1], "%d", &A);
	sscanf_s(argv[2], "%d", &B);

	n = GCD(A, B);
	printf("GCD(%d,%d)=%d\n", A, B, n);
	 
	return 0;
}

int GCD(int A, int B)
{
	if (B == 0)return A;
	return GCD(B, A % B);

}