#include <8051.h>


char direction = 0;
int main()
{
    while(1)
    {
        if(direction == 0)
            P3 = 2;
        else
            P3 = 1;

        for(char i = 1; i < 120; i++) {}

        direction = !direction;
    }
}