#include "diodo.h"

diodo::diodo(void) {
    componente();
}

double diodo::setv(double v){
    if(v>=0.7){
        tensao=0.7;
    }else{
        tensao=v;
    }
    return tensao;
}
double diodo::seti(double i){
    if(i>=0){
        corrente=i;
    }else{
        corrente=0;
    }
    return corrente;
}
/*
string diodo::toString(void){
    if (tensao = 0.7) {
        return "Diodo polarizado diretamente";
    } else if ((corrente > 0) && (tensao > 0)) {
        return "Diodo quase polarizado diretamente";
    } else if (corrente == 0) {
        return "Diodo desligado";
    } else {
        return "Diodo inversamente polarizado";
    }
}
*/
