//Feito por Ígor Romero Nogueira
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define EXPONENTIATION 34
#define MODULO 35
#define INCREMENT 36
#define DECREMENT 37
#define CLEAR 38

#define BRANCH 40 //Desvia para um lugar específico da memória
#define BRANCHNEG 41 //Desvia para um local específico da memória se o acumulador for negativo
#define BRANCHZERO 42 //Desvia para um local específico da memória se o acumulador for zero
#define HALT 43 //termina o programa

#define LOOP 50
#define CONTADOR 51

void despejo(int mem[],int acc,int contIntru,int registIntru,int codOp,int op);
int main()
{
    setlocale(LC_ALL,"Portuguese");
    printf("Bem vindo ao Simpletron!\n");
    printf("Por favor digite uma instrução (ou palavra\n ");
    printf("de dados) de seu programa por vez. Digitarei o\n");
    printf("numero da posição e um ponto de interrogação \n");
    printf("(?). Digite então a palavra para aquela posição \n");
    printf("Digite o valor sentinela -99999 para encerrar a \n");
    printf("digitação de seu programa.\n");

    int memoria[100];
    int acumulador = +0000;
    int contadorInstrucao = 00; //local da mem que tem a instru q esta sendo realizada
    int codigoOperacao = 00; //indica a operação realizada no momento (os dois digitos da esq da palavra)
    int operando = 00; //indica o local na mem q a instru é aplicada (os dois digitos da dir da palavra)
    int registroInstrucao = +0000; //ppega proz instru da mem
    int contador=0;

    //o contIntru informa o local da prox instru a ser realizada
    for(int i=0;i<100;i++)
    {
        memoria[i]=0;
    }
    char nomearq[100];
    char text[5];
    printf("Digite o nome do arquivo: ");
    gets(nomearq);
    strcpy(text,".txt");
    strcat(nomearq,text);

    FILE *arq = fopen(nomearq,"r");
    if(!arq)
    {
        printf("Erro ao abrir o txt!\n");
        return 0;
    }
    int linha;

    while(fscanf(arq,"%d",&linha)==1 && contadorInstrucao<100)
    {
        memoria[contadorInstrucao] = linha;
        if(!(memoria[contadorInstrucao]>=-9999 && memoria[contadorInstrucao]<=+9999))
        {
            printf("Entrada %d inválida!\n",linha);
            return 0;
        }
        if(memoria[contadorInstrucao]==-9999)
        {
            break;
        }
        contadorInstrucao++;
    }
    printf("Carregando do programa concluido\n");
    printf("Inicio da excução do programa\n");
    contadorInstrucao=0;
    while(contadorInstrucao<100)
    {

        registroInstrucao  = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao/100;
        operando = registroInstrucao%100;

        int num_valido=1;
        switch(codigoOperacao)
        {
            case READ:
                while(num_valido)
                {
                    scanf("%d",&memoria[operando]);
                    contadorInstrucao++;
                    if(num_valido)
                    {
                        num_valido=0;
                    }
                    else
                    {
                        printf("Número inválido!\n");
                    }
                }
                break;

            case WRITE:
                printf("%d",memoria[operando]);
                contadorInstrucao++;
                break;

            case LOAD:
                acumulador=memoria[operando];
                contadorInstrucao++;
                break;

            case STORE:
                memoria[operando] = acumulador;
                contadorInstrucao++;
                break;

            case ADD:
                acumulador+=memoria[operando];
                contadorInstrucao++;
                break;

            case SUBTRACT:
                acumulador-=memoria[operando];
                contadorInstrucao++;
                break;

            case DIVIDE:
                if(memoria[operando])
                {
                    acumulador/=memoria[operando];
                    contadorInstrucao++;
                }
                else
                {
                    printf("Tentativa de dividir por zero\n");
                    printf("Interrupção anormal da execução do SImpletron\n");
                    despejo(memoria,acumulador,contadorInstrucao,registroInstrucao,codigoOperacao,operando);
                    return 0;
                }
                break;

            case MULTIPLY:
                acumulador*=memoria[operando];
                contadorInstrucao++;
                break;

            //Realiza o calculo da exponenciação com base no valor do acumulador elevado ao número da memoria
            case EXPONENTIATION:
                acumulador = pow(acumulador,memoria[operando]);
                contadorInstrucao++;
                break;

            case MODULO:
                if(acumulador)
                {
                    acumulador = memoria[operando]%acumulador;
                    contadorInstrucao++;
                }
                else
                {
                    printf("Tentativa de dividir por zero para pegar o resto\n");
                    printf("Interrupção anormal da execução do Simpletron\n");
                    despejo(memoria,acumulador,contadorInstrucao,registroInstrucao,codigoOperacao,operando);
                    return 0;
                }
                break;

            case INCREMENT:
                acumulador++;
                contadorInstrucao++;
                break;

            case DECREMENT:
                acumulador--;
                contadorInstrucao++;
                break;

            case CLEAR:
                acumulador=0;
                contadorInstrucao++;
                break;

            case BRANCH:
                contadorInstrucao=operando;
                break;

            case BRANCHNEG:
                if(acumulador<0)
                {
                    contadorInstrucao=operando;
                }
                break;

            case BRANCHZERO:
                if(acumulador==0)
                {
                    contadorInstrucao=operando;
                }
                break;

            case HALT:
                printf("\nExecução do Simpletron concluída!\n");
                despejo(memoria,acumulador,contadorInstrucao,registroInstrucao,codigoOperacao,operando);
                return 0;

            case LOOP:
                if(contador>1)
                {
                    contadorInstrucao=operando;
                    contador--;
                }
                else
                {
                    contadorInstrucao++;
                }
                break;

            case CONTADOR:
                contador = memoria[operando];
                contadorInstrucao++;
                break;

            default:
                printf("\nExecução do Simpletron concluída!\n");
                despejo(memoria,acumulador,contadorInstrucao,registroInstrucao,codigoOperacao,operando);
                return 0;
        }

    }
return 0;
}
void despejo(int mem[],int acc,int contIntru,int registIntru,int codOp,int op)
{
    printf("REGISTROS: \n");
    printf("Acumulador: %d\n",acc);
    printf("Contador Instrução: %d\n",contIntru);
    printf("Registro Instrução: %d\n",registIntru);
    printf("Código Operação: %d\n",codOp);
    printf("Operando: %d\n",op);

    printf("MEMÓRIA: \n");
    printf("  ");
    for(int k=0;k<10;k++)
    {
        printf("     %d",k);
    }
    printf("\n");
    for(int i=0;i<100;i+=10)
    {
        if(i==0)
        {
            printf("0");
        }

        printf("%-d ",i);
        for(int j=0;j<10;j++)
        {
            if(mem[j+i])
            {
                printf("%+05d ",mem[j+i]);
            }
            else
            {
                printf("+0000 ");
            }
        }
        printf("\n");
    }
}

