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

char getKeyPadValue()
{
    P0 = 0b11111110;
    if(P0_5 == 0)
        return 0;
    
    P0 = 0b11111101;
    if(P0_6 == 0)
        return 7;
    if(P0_5 == 0)
        return 8;
    if(P0_4 == 0)
        return 9;

    P0 = 0b11111011;
    if(P0_6 == 0)
        return 4;
    if(P0_5 == 0)
        return 5;
    if(P0_4 == 0)
        return 6;

     P0 = 0b11110111;
    if(P0_6 == 0)
        return 1;
    if(P0_5 == 0)
        return 2;
    if(P0_4 == 0)
        return 3;

    return 99;
    
}
// state-uri 8 -> first pressed, first released, second pressed, second release.. si tot asa
int main()
{
    char state = 0;
    char cnt = 0;

    char first_digit = 0;
    char second_digit = 0;
    char third_digit = 0;
    char forth_digit = 0;

    while(state != 7)
        switch(state)
        {
            case 0:
                
                while((first_digit = getKeyPadValue()) == 99) {}
                state = 1;
                break;
            case 1:
                while((getKeyPadValue()) != 99) {}
                    state = 2;
                break;
            case 2:
                while((second_digit = getKeyPadValue()) == 99) {}
                state = 3;
                break;
            case 3:
                while((getKeyPadValue()) != 99) {}
                    state = 4;
                break;
            case 4:
                while((third_digit = getKeyPadValue()) == 99) {}
                state = 5;
                break;
            case 5:
                while((getKeyPadValue()) != 99) {}
                    state = 6;
                break;
            case 6:
                while((forth_digit = getKeyPadValue()) == 99) {}
                state = 7;
                break;
        }

    while(1)
    {
        P3_3 = cnt & 1;
        P3_4 = (cnt >> 1) & 1;

        cnt = cnt + 1;
        if(cnt == 4)
            cnt = 0;

        switch(cnt)
        {
            case 0:
                P1 = get_digit_representation(first_digit);
                break;
            case 1:
                P1 = get_digit_representation(forth_digit);
                break;
            case 2:
                P1 = get_digit_representation(third_digit);
                break;
            case 3:
                P1 = get_digit_representation(second_digit);
                break;
        }
    }
}