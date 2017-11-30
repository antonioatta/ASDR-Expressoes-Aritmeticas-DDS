#include <stdio.h>
#include <stdlib.h>

char erros[][50] =  {"Sem erro",
                     "Operando esperado!",
                     "Divisao por zero!",
                     "Faltando fecha parenteses!",
                     "Operador invalido!",
                     "Caracter invalido!",
                     "Formato de numero invalido!"};

void Erro(int e) {

    printf("Erro: %s\n", erros[e]);
    exit(e);
}
