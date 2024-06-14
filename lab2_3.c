#include <8051.h>

char direction = 0;
int main()
{
    while(1)
    {
        if(direction == 0 && P2_1 == 0)
            P3 = 2;
        else if(P2_1 == 0)
            P3 = 1;
        else
            P3 = 0;

        direction = P2_0;
    }
}