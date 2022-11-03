#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdint.h>
#include<math.h>

typedef union {
    float v;
    unsigned char ptr[4];
    struct {
        unsigned F : 23;
        unsigned E : 8;
        unsigned S : 1;
    };
}Float;//v and ptr have same initial address
Float x, y,f;
Float FADD0(Float A, Float B);
Float FADD1(Float A, Float B);// A>B 

int main(void)
{
    while (1)
    {
        printf("Float A:");
        scanf_s("%f", &(x.v));
        printf("Float B:");
        scanf_s("%f", &(y.v));
        //if (x.S == y.S)
        //{
        //    if (x.E < y.E)
        //    {
        //        f = FADD0(y, x);
        //    }
        //    else
        //        f = FADD0(x, y);
        //}
        //else {
            if (x.E < y.E)
            {
                f = FADD1(y, x);
            }
            else {
                f = FADD1(x, y);
            }
 

  /*      }*/
        printf("<%f>=[%d,%02x,%06x]\n", x.v, x.S, x.E, x.F);
        printf("<%f>=[%d,%02x,%06x]\n", y.v, y.S, y.E, y.F);
        printf("<%f>=[%d,%02x,%06x]\n\n", f.v, f.S, f.E, f.F);
        printf("%f  +  %f  =  %f\n\n", x.v, y.v, f.v);
    }
    return 0;
}

Float FADD0(Float A, Float B)// A>B A.s=B.s
{
    Float R;
    unsigned Ea,Eb,d,Fb,Fb1,Fa,E,F;
    R.S = A.S;
    Ea = A.E;
    Eb = B.E;
    d = Ea - Eb;
    Fb = B.F | 0x800000;
    Fb1 = Fb >> d;
    Fa = A.F | 0x800000;
    F = Fa + Fb1;
    if (F & 0x1000000)
    {
        E = Ea + 1;
        F = F >> 1;
    }
    else
    {
        E = Ea;
    }
    R.F = F;
    R.E = E;
    return R;
}

Float FADD1(Float A, Float B)// A>B 
{
    Float R;
    unsigned Ea, Eb, d, Fb, Fb1, Fa,Fa1, E, F;
    Ea = A.E;
    Eb = B.E;
    d = Ea - Eb;
    Fb = B.F | 0x800000;
    Fb1 = Fb >> d;//power need to be same
    Fa = A.F | 0x800000;
    Fa1 = (A.S) ? (~Fa + 1) : Fa;//2'scomplement
    Fb1 = (B.S) ? (~Fb1 + 1) : Fb1;//2's complement
    F = Fa1 + Fb1;
    if (F & 0x2000000)
    {
        R.S = 1;
        F = ~F + 1;
    }
    else
    {
        R.S = 0;
    }

    if (F & 0x1000000)
    {
        E = Ea + 1;
        F = F >> 1;
    }
    else
    {
        E = Ea;
        while (E > 0 && ((F & 0x800000) == 0))
        {
            E = E - 1;
            F = F << 1;
     }
    }
    R.F = F;
    R.E = E;
    return R;
}
