#include <stdio.h>

int calculate(int num)
{
    switch (num)
    {
    case 1:

        printf("First\n");
        break;
    case 2:

        printf("Second\n");
        break;
    case 3:

        printf("Third\n");
        break;
    case 4:

        printf("Fourth\n");
        break;
    case 5:

        printf("Fifth\n");
        break;

    default:
        printf(" Not a number between 1 and 5 , Byebye ");
        break;
    }
}

int main()
{
    int n;
    do
    {
        printf("Enter a number between 1 and 5 : \n");
        scanf("%d", &n);
        calculate(n);
    } while (n < 6 && n > 0);
}
