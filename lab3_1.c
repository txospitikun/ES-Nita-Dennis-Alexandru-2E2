#include <8051.h>

// fac totu in main de acum

int main()
{
    char number = 1;

    int cnt = 0;

    char zero  = 0b11000000;  // 0 ---- cel mai din dreapta e Px_0 si cel mai din stanga e Px_7
    char one   = 0b11111001;  // 1
    char two   = 0b10100100;  // 2
    char three = 0b10110000;  // 3
    char four  = 0b10011001;  // 4
    char five  = 0b10010010;  // 5
    char six   = 0b10000010;  // 6
    char seven = 0b11111000;  // 7
    char eight = 0b10000000;  // 8
    char nine  = 0b10010000;  // 9
   
    while(1)
    {
        P3_3 = cnt & 1;
        P3_4 = (cnt >> 1) & 1;

        cnt = cnt + 1;
        if(cnt == 4)
            cnt = 0;

        switch(number)
        {
            case 0:
                P1 = zero;
                break;
            case 1:
                P1 = one;
                break;
            case 2:
                P1 = two;
                break;
            case 3:
                P1 = three;
                break;
            case 4:
                P1 = four;
                break;
            case 5:
                P1 = five;
                break;
            case 6:
                P1 = six;
                break;
            case 7:
                P1 = seven;
                break;  
            case 8:
                P1 = eight;
                break;
            case 9:
                P1 = nine;
                break;
        }
    }
}