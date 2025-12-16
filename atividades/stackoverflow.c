#include <stdio.h>
void stack(int *num);
int main()
{
    int num=0;
    stack(&num);

return 0;
}
void stack(int *num)
{

    *num++;
    printf("repeticao\n");
    stack(num);
}
