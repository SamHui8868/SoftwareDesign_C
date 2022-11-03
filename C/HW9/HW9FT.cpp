// test.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include <windows.h>

void hello(void);
void goodbye(void);
void EXIT(void);
void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2);
void multiplyMatrices(int first[][10], int second[][10], int multResult[][10], int r1, int c1, int r2, int c2);
void display(int mult[][10], int r1, int c2);
void MATRIXMUL(void);
void ADDER(void);
typedef struct {
	const char* cmdname;
	void (*f)(void);
}CmdTBL;

CmdTBL CT[5] = { {"CMD1",hello},
				{"CMD2",goodbye},
				{"CMD3",EXIT} ,
             {"CMD4",MATRIXMUL},
             {"CMD5",ADDER} };

void hello(void)
{
	printf("hello \n");
}
void goodbye(void)
{
	printf("goodbye \n");
}
void EXIT(void)
{
	exit(0);
}
int main()
{
    int x;
    x=1;
    char a[10];
while(1){
            scanf("%s", a);
        if (!strcmp(a, CT[0].cmdname))
            CT[0].f();
        else if (!strcmp(a, CT[1].cmdname))
            CT[1].f();
        else if (!strcmp(a, CT[2].cmdname))
            CT[2].f();
       else  if (!strcmp(a, CT[3].cmdname))
            CT[3].f();
       else  if (!strcmp(a, CT[4].cmdname))
            CT[4].f();
        else
            printf("CMD not found\n");


}

}


    void MATRIXMUL(void) {
        int first[10][10], second[10][10], mult[10][10], r1, c1, r2, c2;
        printf("Enter rows and column for the first matrix: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter rows and column for the second matrix: ");
        scanf("%d %d", &r2, &c2);

        // Taking input until columns of the first matrix is equal to the rows of the second matrix
        while (c1 != r2) {
            printf("Error! Enter rows and columns again.\n");
            printf("Enter rows and columns for the first matrix: ");
            scanf("%d%d", &r1, &c1);
            printf("Enter rows and columns for the second matrix: ");
            scanf("%d%d", &r2, &c2);
        }

        // Function to take matrices data
        enterData(first, second, r1, c1, r2, c2);

        // Function to multiply two matrices.
        multiplyMatrices(first, second, mult, r1, c1, r2, c2);

        // Function to display resultant matrix after multiplication.
        display(mult, r1, c2);

    }

    void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2) {
        printf("\nEnter elements of matrix 1:\n");

        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) {
                printf("Enter a%d%d: ", i + 1, j + 1);
                scanf("%d", &first[i][j]);
            }
        }
        printf("\nEnter elements of matrix 2:\n");

        for (int i = 0; i < r2; ++i) {
            for (int j = 0; j < c2; ++j) {
                printf("Enter b%d%d: ", i + 1, j + 1);
                scanf("%d", &second[i][j]);
            }
        }
    }

    void multiplyMatrices(int first[][10], int second[][10], int mult[][10], int r1, int c1, int r2, int c2) {

        // Initializing elements of matrix mult to 0.
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                mult[i][j] = 0;
            }
        }

        // Multiplying first and second matrices and storing in mult.
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                for (int k = 0; k < c1; ++k) {
                    mult[i][j] += first[i][k] * second[k][j];
                }
            }
        }
    }

    void display(int mult[][10], int r1, int c2) {

        printf("\nOutput Matrix:\n");
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                printf("%d  ", mult[i][j]);
                if (j == c2 - 1)
                    printf("\n");
            }
        }
    }
void ADDER(void)
{
  int x, y, z;

  printf("Enter two numbers to add\n");
  scanf("%d%d", &x, &y);

  z = x + y;

  printf("Sum of the numbers = %d\n", z);

}
