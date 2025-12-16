#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
FILE* abrir_arq(char name_arq[]);
void leitura_arq(FILE *arq,char **palavras);
void imprimir_vetor(char palavras[]);
int main()
{
    setlocale(LC_ALL,"Portuguese");

    char nome_arq[40],*palavras;


    printf("Digite o nome do arquivo: ");
    gets(nome_arq);

    FILE *arq = abrir_arq(nome_arq);
    if(arq == NULL)
    {
        printf("Erro!");
        return 0;
    }
    leitura_arq(arq,&palavras);

    imprimir_vetor(palavras);

    fclose(arq);
    free(palavras);
return 0;
}
FILE* abrir_arq(char name_arq[])
{
    char extensao[20] = {".c"};
    strcat(name_arq,extensao);
    FILE *arq1 = fopen(name_arq,"r");
    if(arq1 == NULL)
    {
        printf("Erro ao abrir!");

    }
    return arq1;
}
void leitura_arq(FILE *arq,char **palavras)
{
    char caracter;
    int i=0,tamanho=1000;
    *palavras = malloc(tamanho*sizeof(char));

    while(fscanf(arq,"%c",&caracter)!=EOF)
    {
        (*palavras)[i]=caracter;
        i++;
        if(i>=tamanho)
        {
            tamanho*=2;
            palavras = malloc(tamanho*sizeof(char));
        }
    }
    palavras[i] = '\0';


}
void imprimir_vetor(char palavras[])
{
    printf("Vetor palavras:\n%s",palavras);
}
