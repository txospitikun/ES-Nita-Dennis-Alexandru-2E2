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
    // 1234
    int number = 234;
    char first_digit, second_digit, third_digit, forth_digit;
    first_digit = second_digit = third_digit = forth_digit = 0;

    while(number > 999) {number -= 1000; first_digit += 1;}
    while(number > 99) {number -= 100; second_digit += 1;}
    while(number > 9) {number -= 10; third_digit += 1;}
    while(number > 0) {number -= 1; forth_digit += 1;}

    char current_display = 0;


    while(1)
    {
        // afisez numerele unul dupa altul
        if(first_digit != 0 && current_display == 3)
        {
            P3_3 = 1;
            P3_4 = 1;
            P1 = get_digit_representation(first_digit);
            current_display = 2;
        } 
        else if(second_digit != 0 && current_display == 2)
        {
            P3_3 = 0;
            P3_4 = 1;
            P1 = get_digit_representation(second_digit);
            current_display = 1;
        } 
        else if(third_digit != 0 && current_display == 1)
        {
            P3_3 = 1;
            P3_4 = 0;
            P1 = get_digit_representation(third_digit);
            current_display = 0;
        }
        else if(current_display == 0)
        {
            P3_3 = 0;
            P3_4 = 0;
            P1 = get_digit_representation(forth_digit);
            if(first_digit != 0)
                current_display = 3;
            else if(second_digit != 0)
                current_display = 2;
            else if(third_digit != 0)
                current_display = 1;
        }
    }
}