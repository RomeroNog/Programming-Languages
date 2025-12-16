#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noPilha
{
    char elemento;
    struct noPilha *prox;
}noPilha;
typedef struct
{
    struct noPilha *topo;
}Pilha;
void pos_fixa(char expre[],char result[],Pilha *pi,int tam);
int niveis_op(char op);
int eh_operador(char expre);
void inicializa_pilha(Pilha* pilha);
void reinicializa(Pilha *pilha);
void obter_topo(Pilha* pilha,char *elem);
void pop(Pilha* pilha,char *elem);
void push(Pilha* pilha,char elem);
int se_vazia(Pilha* pilha);
int main()
{
    char expressao[20];
    char polonesa[20];
    printf("Digite a expressao: ");
    gets(expressao);

    Pilha pilha;
    inicializa_pilha(&pilha);
    int tam_expre = strlen(expressao);

    pos_fixa(expressao,polonesa,&pilha,tam_expre);

    printf("Expressão em polonesa: %s",polonesa);


return 0;
}
void pos_fixa(char expre[],char result[],Pilha *pi,int tam)
{
    int j=0;
    for(int i=0;i<tam;i++)
    {
        char atual=expre[i];
        if(atual>='A' && atual<='Z' || atual >='a' && atual<='z')
        {
            result[j++]=atual;
        }
        if(eh_operador(atual))
        {
            while(!se_vazia(pi))
            {
                char topo;
                obter_topo(pi,&topo);
                if (niveis_op(topo)>=niveis_op(atual))
                {
                    result[j++]=topo;
                    pop(pi,&topo);
                }
                else
                {
                    break;
                }
            }
            push(pi,atual);
        }
        if(atual=='(')
        {
            push(pi,atual);
        }
        if(atual==')')
        {
            char topo;
            while (!se_vazia(pi))
            {
                obter_topo(pi, &topo);
                if(topo=='(')
                {
                    break;
                }
                result[j++]=topo;
                pop(pi,&topo);
            }
            if(!se_vazia(pi))
            {
                pop(pi,&topo);
            }
        }
    }
    while(!se_vazia(pi))
    {
        char topo;
        pop(pi,&topo);
        result[j++]=topo;
    }
    result[j]='\0';
}
int niveis_op(char expre)
{
        if(expre == '+' || expre == '-')
        {
            return 1;
        }
        else
        {
            if(expre == '*' || expre == '/')
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
}
int eh_operador(char expre)
{
    if(expre== '+' || expre=='-' || expre=='*' || expre=='/')
    {
        return 1;
    }
    return 0;
}
void inicializa_pilha(Pilha* pilha)
{
    pilha->topo=NULL;
}
int se_vazia(Pilha* pilha)
{
    if(!pilha->topo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(Pilha* pilha,char elem)
{
    noPilha* novo_no = malloc(sizeof(noPilha));
    novo_no->elemento = elem;
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
}
void pop(Pilha* pilha,char *elem)
{
    if(se_vazia(pilha))
    {
        printf("Sem elementos!\n");
        return;
    }
    else
    {
        noPilha* aux = malloc(sizeof(noPilha));
        aux = pilha->topo;
        *elem = aux->elemento;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
}
void obter_topo(Pilha* pilha,char *elem)
{
    if(se_vazia(pilha) || !pilha->topo)
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        *elem = pilha->topo->elemento;
    }
}
void reinicializa(Pilha *pilha)
{
    if(se_vazia(pilha))
    {
        printf("Pilha vazia!\n");
        return;
    }
    else
    {
        while(pilha->topo)
        {
            noPilha* temp = malloc(sizeof(noPilha));
            temp = pilha->topo;
            pilha->topo = pilha->topo->prox;
            free(temp);
        }
        printf("Pilha esvaziada!\n");
        return;
    }
}
