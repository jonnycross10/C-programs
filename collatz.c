#include <stdio.h>

int n;

int get_start()
{
    int num = -1;
    while (num <=0)
    {
        printf("Enter a positive number: ");
        scanf("%d", &num);
    }
    return num;
}
int next_collatz(int next)
{
    int r;
    if (next%2 == 1)
    {
        r = next * 3 + 1;
    }
    else
    {
        r = next / 2;
    }
    return r;
}

int main()
{
    int counter= 1;
    printf("Enter a number to begin collatz sequence: ");
    n= next_collatz(get_start());
    printf("%d\n", n);
    counter++;
    while ( n != 1)
    {
        n = next_collatz(n);
        printf("%d\n", n);
        counter++;
    }
    printf("The length of the sequence is: %d\n", counter);
}
