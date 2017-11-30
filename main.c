#include <stdio.h>
#include <stdlib.h>
#include "analex.h"

extern TOKEN t;

float Expr();

int main()
{
    float result;

    printf("Digite expressoes aritmeticas no formato padrao (modo infixo).\n");
    printf("Termine cada expressao com o sinal de igualdade (=) seguido de <enter>.\n");
    printf("Parenteses podem ser usados para quebrar a ordem de precedencia dos \n");
    printf("operadores (+, -, *, e /). Ao final de cada expressao, se ela estiver correta,\n");
    printf("o resultado sera apresentado e, em seguida, uma nova expressao pode ser\n");
    printf("digitada.\n");
    printf("Termine a entrda de expressoes com um sinal de igualdade (=) sem expressao.\n");
    printf("\nExpr> ");
    Analex(stdin);
    while (t.cat != SN || t.cod != IGUAL) {
        result=Expr();
        printf("Resultado> %10.3f\n", result);
        printf("\nExpr> ");
        fflush(stdin);
        Analex(stdin);
    }
    printf("Ate a proxima!");
    return 0;
}
