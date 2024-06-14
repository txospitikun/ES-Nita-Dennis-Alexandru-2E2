#include <8051.h>

char x;
int main()
{
    while(1)
    {
        x = P2;
        P1 = x;
    }
}