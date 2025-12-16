#include <stdio.h>
#include <math.h>
int main() {

 double din,flodin;
    int nflodin;
    int intdin,resto;
    int n100,n50,n20,n10,n5,n2;
    int m1,m05,m025,m01,m005,m001;

    scanf("%lf",&din);
    intdin = floor(din);
    flodin = din - intdin;


    n100 = intdin/100;
    resto = intdin%100;

    n50 = resto/50;
    resto = resto%50;

    n20 = resto/20;
    resto = resto%20;

    n10 = resto/10;
    resto = resto%10;

    n5 = resto/5;
    resto = resto%5;

    n2 = resto/2;
    resto = resto%2;

    m1 = resto/1;
    resto = resto%1;


    nflodin = flodin*100.00;

    m05 = flodin/0.5;
    nflodin = nflodin%50;

    m025 = nflodin/25;
    nflodin  = nflodin%25;

    m01 = nflodin/10;
    nflodin = nflodin%10;

    m005 = nflodin/5;
    nflodin = nflodin%5;

    m001 = nflodin/1;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n",n100);
    printf("%d nota(s) de R$ 50.00\n",n50);
    printf("%d nota(s) de R$ 20.00\n",n20);
    printf("%d nota(s) de R$ 10.00\n",n10);
    printf("%d nota(s) de R$ 5.00\n",n5);
    printf("%d nota(s) de R$ 2.00\n",n2);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",m1);
    printf("%d moeda(s) de R$ 0.50\n",m05);
    printf("%d moeda(s) de R$ 0.25\n",m025);
    printf("%d moeda(s) de R$ 0.10\n",m01);
    printf("%d moeda(s) de R$ 0.05\n",m005);
    printf("%d moeda(s) de R$ 0.01\n",m001);

    return 0;
}
