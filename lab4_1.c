#include <8051.h>

char get_digit_representation(char digit)
{
    switch(digit)
    {
        case 0: return 0b11000000; // 0
        case 1: return 0b11111001; // 1
        case 2: return 0b10100100; // 2
        case 3: return 0b10110000; // 3
        case 4: return 0b10011001; // 4
        case 5: return 0b10010010; // 5
        case 6: return 0b10000010; // 6
        case 7: return 0b11111000; // 7
        case 8: return 0b10000000; // 8
        case 9: return 0b10010000; // 9
    }
}

int main()
{
    P3 = 0;
    while(1)
    {

        P0 = 0b11111111;
        P0_0 = 0;

        if(P0_5 == 0)
            P1 = get_digit_representation(0);

        P0 = 0b11111111;
        P0_1 = 0;

        if(P0_6 == 0)
            P1 = get_digit_representation(7);

        if(P0_5 == 0)
        P1 = get_digit_representation(8);

        if(P0_4 == 0)
        P1 = get_digit_representation(9);

        P0 = 0b11111111;
        P0_2 = 0;

        if(P0_6 == 0)
            P1 = get_digit_representation(4);

        if(P0_5 == 0)
        P1 = get_digit_representation(5);

        if(P0_4 == 0)
        P1 = get_digit_representation(6);


        P0 = 0b11111111;
        P0_3 = 0;   

        if(P0_6 == 0)
            P1 = get_digit_representation(1);

        if(P0_5 == 0)
        P1 = get_digit_representation(2);

        if(P0_4 == 0)
        P1 = get_digit_representation(3);
    }
}