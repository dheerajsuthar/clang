#include <stdio.h>
#define START 0
#define END 300

float fahtodeg(int fah);
int main(int argc, char const *argv[])
{
    for (int i = START; i < END; i = i + 20)
    {
        printf("%d\t%0.3f\n", i, fahtodeg(i));
    }
    return 0;
}

float fahtodeg(int fah)
{
    return 5 * (fah - 32) / 9.0;
}
