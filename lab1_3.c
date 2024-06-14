#include <8051.h>

char current = 0b10000000;
char x;
char direction = 1;
int main()
{
    while(1)
    {
        P1 = ~current;
        if(direction == 1)
        {
            current = current >> 1;
            if(current == 0b00000001)
                direction = 0;
        }
        else
        {
            current = current << 1;
            if(current == 0b10000000)
                direction = 1;
        }
    }
}