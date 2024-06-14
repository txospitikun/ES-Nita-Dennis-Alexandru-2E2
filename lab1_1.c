#include <8051.h>

char even = 0;
int main()
{
    while(1)
    {
        if(even == 0)
        {
            P1_0 = 1;
            P1_1 = 0;
            P1_2 = 1;
            P1_3 = 0;
            P1_4 = 1;
            P1_5 = 0;
            P1_6 = 1;
            P1_7 = 0;

            //sau

            P1 = 0b10101010;

            even = 1;
        }
        else
        {
            P1_0 = 0;
            P1_1 = 1;
            P1_2 = 0;
            P1_3 = 1;
            P1_4 = 0;
            P1_5 = 1;
            P1_6 = 0;
            P1_7 = 1;

            // sau

            P1 = 0b01010101;

            even = 0;
        }
    }
}