#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct rom
{
    int I;
    int V;
    int X;
    int L;
    int C;
    int D;
    int M;
};

struct rom roman_constants = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(char* s);

int main()
{
    char r_num[100];
    printf("Enter your Roman Number in Bold Character: ");
    fgets(r_num, sizeof(r_num), stdin);

    int num = romanToInt(r_num);

    printf("Integer representation: %d\n", num);

    return 0;
}

int romanToInt(char* s) {
    int sum = 0;
    char prev_char = '\0';
    for (int i = 0; i < s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case 'I':
            sum += roman_constants.I;
            break;
        case 'V':
            sum += roman_constants.V;
            if (prev_char == 'I')
                sum -= 2 * roman_constants.I;
            break;
        case 'X':
            sum += roman_constants.X;
            if (prev_char == 'I')
                sum -= 2 * roman_constants.I;
            break;
        case 'L':
            sum += roman_constants.L;
            if (prev_char == 'X')
                sum -= 2 * roman_constants.X;
            break;
        case 'C':
            sum += roman_constants.C;
            if (prev_char == 'X')
                sum -= 2 * roman_constants.X;
            break;
        case 'D':
            sum += roman_constants.D;
            if (prev_char == 'C')
                sum -= 2 * roman_constants.C;
            break;
        case 'M':
            sum += roman_constants.M;
            if (prev_char == 'C')
                sum -= 2 * roman_constants.C;
            break;
        }
        prev_char = s[i];
    }

    return sum;
}
