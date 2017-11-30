#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "analex.h"

void Erro(int);

void Analex(FILE *fd) {

    char c;
    int estado;


    c=fgetc(stdin);
    estado=0;

    while (1) {
        switch (estado) {
        case 0:
            if (c==' ' || c=='\t') estado=0;
            else if (isdigit(c)) {
                estado=1;
                digitos[0]=c;
                indDig=1;
            }
            else if (c=='+') {t.cat=SN; t.cod=SOMA; return;}
            else if (c=='-') {t.cat=SN; t.cod=SUBT; return;}
            else if (c=='*') {t.cat=SN; t.cod=MULT; return;}
            else if (c=='/') {t.cat=SN; t.cod=DIVI; return;}
            else if (c=='(') {t.cat=SN; t.cod=ABRE_P; return;}
            else if (c==')') {t.cat=SN; t.cod=FECHA_P; return;}
            else if (c=='=') {t.cat=SN; t.cod=IGUAL; return;}
            else Erro(5);
            break;
        case 1:
            if (isdigit(c)) {
                estado=1;
                digitos[indDig++]=c;
            }
            else if (c=='.') {
                estado=2;
                digitos[indDig++]=c;
            }
            else {
                estado=3;
                ungetc(c, stdin);
                t.cat=OP;
                digitos[indDig]='\0';
                t.valor=atof(digitos);
                return;
            }
            break;
        case 2:
            if (isdigit(c)) {
                estado=4;
                digitos[indDig++]=c;
            }
            else Erro(6);
            break;
        case 4:
            if (isdigit(c)) {
                estado=4;
                digitos[indDig++]=c;
            }
            else {
                estado=5;
                ungetc(c, stdin);
                t.cat=OP;
                digitos[indDig]='\0';
                t.valor=atof(digitos);
                return;
            }
        }
        c=fgetc(stdin);
    }
}

