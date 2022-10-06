#include "Componente.h"

//! Construtor padr�o - incializa todas as variaveis com 0 ou vazio
componente::componente() {
    nominal=0;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}

double componente::getV(void) {
    return tensao;
}

double componente::I(void) {
    return corrente;
}
string componente::toString(void) {
    string texto;
    char str[30];
    sprintf(str, "%.2f %s", nominal, unidade.c_str());
    texto = str;
    return texto;
}
 // Sobrecarga fora da classe
std::ostream& operator << (std::ostream&saida, componente &c)
{
    saida << c.toString();
    return saida;
}
