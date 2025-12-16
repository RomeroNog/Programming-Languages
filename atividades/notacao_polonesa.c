#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int topo;
    char itens[MAX];
} Pilha;
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}
int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}
int estaVazia(Pilha *p) {
    return p->topo == -1;
}
void empilhar(Pilha *p, char item) {
    if (estaCheia(p)) {
        printf("Pilha está cheia\n");
    } else {
        p->itens[++(p->topo)] = item;
    }
}
char desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha está vazia\n");
        return '\0';
    } else {
        return p->itens[(p->topo)--];
    }
}
char topo(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha está vazia\n");
        return '\0';
    } else {
        return p->itens[p->topo];
    }
}
int eOperador(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int precedencia(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixoParaPrefixo(char infixo[], char prefixo[]) {
    Pilha p;
    inicializaPilha(&p);
    int len = strlen(infixo);
    int indicePrefixo = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (infixo[i] >= '0' && infixo[i] <= '9') {
            prefixo[indicePrefixo++] = infixo[i];
        } else if (infixo[i] == ')') {
            empilhar(&p, infixo[i]);
        } else if (infixo[i] == '(') {
            while (!estaVazia(&p) && topo(&p) != ')') {
                prefixo[indicePrefixo++] = desempilhar(&p);
            }
            desempilhar(&p);
        } else if (eOperador(infixo[i])) {
            while (!estaVazia(&p) && precedencia(topo(&p)) > precedencia(infixo[i])) {
                prefixo[indicePrefixo++] = desempilhar(&p);
            }
            empilhar(&p, infixo[i]);
        }
    }

    while (!estaVazia(&p)) {
        prefixo[indicePrefixo++] = desempilhar(&p);
    }

    prefixo[indicePrefixo] = '\0';

    // Inverter a expressão prefixa
    for (int i = 0, j = indicePrefixo - 1; i < j; i++, j--) {
        char temp = prefixo[i];
        prefixo[i] = prefixo[j];
        prefixo[j] = temp;
    }
}
int main() {
    char infixo[MAX], prefixo[MAX];
    printf("Digite uma expressão infixa: ");
    fgets(infixo, MAX, stdin);
    infixo[strcspn(infixo, "\n")] = '\0';

    infixoParaPrefixo(infixo, prefixo);

    printf("Expressão prefixa: %s\n", prefixo);

    return 0;
}

