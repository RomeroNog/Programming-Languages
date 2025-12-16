#include <stdio.h>
int main()
{
    heap();
return 0;
}
void heap()
{
    int *i = malloc(sizeof(int));
    if(!i)
    {
        printf("nao foi possivel alocar\n");
    }
    printf("heap\n");
    heap();

}
