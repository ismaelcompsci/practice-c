#include <stdio.h>
#include <stdlib.h>

int set_bit(int x, int position);
int clear_bit(int x, int position);
int flip_bit(int x, int position);
int modify_bit(int x, int position, int state);
int is_power_of_two(int x);
int flip_bit_v2(int x, int position);
int is_even(int x);
int count_bits(int x);
int diff(int a, int b);
int is_bit_set(int x, int position);
void print_bits(unsigned n);

int main(void)
{

    // int new = set_bit(6, 5);
    // int clear = clear_bit(new, 5);
    // int filp = flip_bit(6, 2);
    // int is_bit = is_bit_set(6, 5);
    // int modify = modify_bit(6, 5, 1);
    // int diffrence = diff(2, 1);
    int count = count_bits(15);
}
/* write a function to count the number of bits that are different between two numbers */
int diff(int a, int b)
{
    printf("Diff\n");
    print_bits(a);
    print_bits(b);
    int count = a ^ b;
    int i = 0;

    while (count > 0)
    {
        if ((count & 1) == 1)
            i++;

        count = count >> 1;
    }
    printf("%i\n", i);
    return i;
}

int count_bits(int x)
{
    int mask = 0b10000000;
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if ((x & mask) != 0)
            count++;

        mask = mask >> 1;
    }
    printf("%i\n", count);
    return count;
}

int set_bit(int x, int position)
{
    printf("Set bit\n");
    print_bits(x);
    int mask = 1 << position;
    print_bits(x | mask);
    return x | mask;
}

int clear_bit(int x, int position)
{
    printf("Clear bit\n");
    print_bits(x);
    int mask = ~(1 << position);

    print_bits((x & (mask)));
    return (x & (mask));
}

int flip_bit(int x, int position)
{
    printf("Flip bit\n");
    print_bits(x);
    int mask = 1 << position;

    print_bits((x ^ (mask)));
    return (x ^ (mask));
}
int flip_bit_v2(int x, int position)
{
    printf("Flip bit V2\n");
    print_bits(x);
    int shifted = x >> position;

    print_bits(shifted & 1);
    return (shifted & 1);
}

int is_bit_set(int x, int position)
{
    printf("Is Bit Set\n");
    print_bits(x);
    int mask = 1 << position;
    printf("%s\n", (x & (mask)) != 0 ? "true" : "false");
    return (x & (mask)) != 0;
}

int modify_bit(int x, int position, int state)
{
    printf("Modify Bit\n");
    print_bits(x);
    int mask = 1 << position;

    print_bits((x & ~mask) | (-state & mask));
    return (x & ~mask) | (-state & mask);
}

int get_sign(int x)
{
    int sign;
    // sign = -(x < 0); // if v < 0 then -1, else 0.

    sign = x >> (sizeof(int) * __CHAR_BIT__ - 1);
}

int is_even(int x)
{

    return (x & 1) == 0;
}

int is_power_of_two(int x)
{
    return (x & x - 1) == 0;
}

void print_bits(unsigned n)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

    printf("\n");
}