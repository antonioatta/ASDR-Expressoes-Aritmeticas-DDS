#include <stdlib.h>
#include "analex.h"

extern TOKEN t;

float Expr();
float Termo();
float Resto(float);
float Sobra(float);
float Fator();
void Erro(int);


float Expr() {

    float primOp, result;

    primOp=Termo();
    result=Resto(primOp);

    return result;
}

float Termo() {

    float primOp, result;

    primOp=Fator();
    result=Sobra(primOp);

    return result;
}

float Resto(float primOp) {

    float segunOp, tmpResult, result;

    if ((t.cat==SN && t.cod==SOMA) || (t.cat==SN && t.cod==SUBT))  {
        TCOD opSalva=t.cod;
        Analex(stdin);
        segunOp=Termo();
        tmpResult=(opSalva==SOMA ? primOp+segunOp : primOp-segunOp);
        result=Resto(tmpResult);
        return result;
    }
    else {       // saida por vazio
       return primOp;
    }
}

float Sobra(float primOp) {

    float segunOp, tmpResult, result;

    if ((t.cat==SN && t.cod==MULT) || (t.cat==SN && t.cod==DIVI))  {
        TCOD opSalva=t.cod;
        Analex(stdin);
        segunOp=Fator();
        if (opSalva==DIVI && segunOp==0.0) Erro(2);
        tmpResult=(opSalva==MULT ? primOp*segunOp : primOp/segunOp);
        result=Sobra(tmpResult);
        return result;
    }
    else {       // saida por vazio
       return primOp;
    }
}

float Fator() {

    float result;

    if (t.cat==SN && t.cod==ABRE_P) {
        Analex(stdin);
        result=Expr();
        if (t.cat!=SN || t.cod!=FECHA_P) {
            Erro(3);
        }
    }
    else if (t.cat==SN && (t.cod==SOMA || t.cod==SUBT)) {
        int sinal = (t.cod==SOMA ? 1 : -1);
        Analex(stdin);
        if (t.cat==OP) result=sinal*t.valor;
        else Erro(4);
    }
    else if (t.cat==OP) {
        result=t.valor;
    }
    else Erro(1);
    Analex(stdin);
    return result;
}
