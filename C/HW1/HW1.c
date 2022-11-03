
#include <stdio.h>
void StrPtr(char *text)
{
    int i;
    while(*text!='\0')
    {
         putchar(*text);
         text++;
    }


}
int main(void) {
    char text[3]="12"
    const char *name="           **       \n"
                     "           **          **\n";
    StrPtr(name);
    printf("     **************   **\n");
    printf("     **************  ***********\n");
    printf("                    ************\n");
    printf("       *********   **     **\n");
    printf("       *********  **      **\n");
    printf("                          **\n");
    printf("       ********* ******************\n");
    printf("       ********* *******************\n");
    printf("                          **\n");
    printf("      ***********         **\n");
    printf("      ***********         **\n");
    printf("      *        **         **\n");
    printf("      *        **         **\n");
    printf("      ***********         **\n");
    printf("      ***********         **\n");
    printf("\n");
    printf("          **                   \n");
    printf("        **  **                \n");
    printf("      **      **           ***\n");
    printf("    **          **        ************\n");
    printf("  **             **      ************\n");
    printf(" **    *********        ***       **\n");
    printf("       *********       ************\n");
    printf("          **          ****      **\n");
    printf("          **         ***       **\n");
    printf("       *********    ***       ** \n");
    printf("       *********                  \n");
    printf("          **         *************\n");
    printf("      **  **  **     *************\n");
    printf("       ** ** **      **         **\n");
    printf("        *******      **         **\n");
    printf("   ***************** *************\n");
    printf("   ***************** *************\n");
    printf("                           \n");
    printf("                 **        \n");
    printf("                 **        \n");
    printf("            ************  \n");
    printf("           **************  \n");
    printf("              ********     \n");
    printf("             **  **  **    \n");
    printf("            **   **   **   \n");
    printf("           **    **    **   \n");
    printf("                            \n");
    printf("        **                **        \n");
    printf("        **                **         \n");
    printf("   ************      ************      \n");
    printf("  **************    **************\n");
    printf("     ********          ********       \n");
    printf("    **  **  **        **  **  **         \n");
    printf("   **   **   **      **   **   **       \n");
    printf("  **    **    **    **    **    **        \n");
    printf("                                \n");
    return 0;
}
