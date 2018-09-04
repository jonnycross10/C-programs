#include <stdio.h>

int get_amount()
{
    int num = -1;
    while (num <=0)
    {
        printf("Enter money in dollars: ");
        scanf("%d", &num);
    }
    return num;
}

int bills(int dollar)
{
    int store = 0;
    int c100 = 0;
    int c50 = 0;
    int c20 = 0;
    int c10 = 0;
    int c5 =0;
    int c1 =0;
    while (dollar >= 1)
    {
        if (dollar >= 100)
        {
            dollar = dollar -100;
            c100++;
        }
        else if((dollar <100) && (dollar >= 50))
        {
            dollar = dollar -50;
            c50++;
        }
        else if ((dollar <50) && (dollar>=20))
        {
            dollar = dollar -20;
            c20++;
        }
        else if ((dollar<20) && (dollar >=10))
        {
            dollar = dollar -10;
            c10++;
        }
        else if((dollar <10) && (dollar>=5))
        {
            dollar = dollar -5;
            c5++;
        }
        else if((dollar<5) && (dollar >=1))
        {
            dollar = dollar -1;
            c1++;
        }
    }
    store = c1 + c5 + c10 + c20 + c50 + c100;
    return store;
}

int main()
{
    int n = bills(get_amount());
    printf("%d\n", n);
}
