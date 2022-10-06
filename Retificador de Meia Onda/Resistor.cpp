#include "Resistor.h"
#include <ostream>
#include <cmath>

const std::string unidades[] = {"p", "n", "u", "m", "ohm", "k", "M", "G"};

resistor::resistor(void){
    componente();
    nominal=0;
}

resistor::resistor(string texto) {
    float valor = 0;
    cout << texto;
    do {
        cin >> valor;
        if (valor == 0) cout << "Valor invalido. Digite novamente: ";
    } while (valor == 0);
    componente();
    nominal = valor;
}

resistor::resistor(double r, std::string unidadeMedida = ""){
    componente();
    setr(r, unidadeMedida);
}

bool resistor::setUnidade(std::string unidadeMedida) {
    std::string toLower(std::string str);

    if (toLower(unidadeMedida) == "k") {
        unidadeMedida = "k";
    } else {
        unidade = unidadeMedida;
    }
}

double resistor::getr(void){
    return nominal;
}

bool resistor::setr(double r){
    if ((r < 0) || (r > 10000000))
        return false;
    nominal = r;
    return true;
}

bool resistor::setr(double r, std::string unidadeMedida){
    if ((r < 0) || (r > 10000000))
        return false;
    setUnidade(unidadeMedida);
    nominal = r;
    return true;
}

double resistor::v(double i){
    corrente = i;
    tensao = valorReal() * i;
    return tensao;
}

double resistor::i(double v){
    if (nominal==0){
        tensao = v;
        corrente =  0;
    } else {
        tensao = v;
        corrente = v / valorReal();
    }
    return corrente;
}

double resistor::valorReal(){
    if (unidade == unidades[0]) {
        return (nominal * 0.000000000001);
    } else if (unidade == unidades[1]) {
        return (nominal * 0.000000001);
    } else if (unidade == unidades[2]) {
        return (nominal * 0.000001);
    } else if (unidade == unidades[3]) {
        return (nominal * 0.001);
    } else if (unidade == unidades[5]) {
        return (nominal * 1000);
    } else if (unidade == unidades[6]) {
        return (nominal * 1000000);
    } else if (unidade == unidades[7]) {
        return (nominal * 1000000000);
    }
    return nominal;
}

std::string toLower(std::string str) {
    char toLower(char c);

    std::string str2 = str;
    for (int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }
    return str2;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

 std::string resistor::getU(void)
 {
     return unidade;
 }

 resistor resistor::operator+(resistor &outroR)
 {
     float paraUnidade(float valor);
     int getIndiceUnidade(float valor);
     resistor req; //!< resistor equivalente da associacao serie
     float aux = nominal+outroR.nominal;
     req.unidade = unidades[getIndiceUnidade(aux)];
     req.nominal = paraUnidade(aux);
     return req;
 }

 resistor resistor::operator / (resistor &outroR)
 {
     float paraUnidade(float valor);
     int getIndiceUnidade(float valor);
     resistor req;
     float aux = (nominal * outroR.nominal)/(nominal + outroR.nominal);
     req.unidade = unidades[getIndiceUnidade(aux)];
     req.nominal = paraUnidade(aux);
     return req;
 }

int getIndiceUnidade(float valor) {
    int casas = 9;
    int valorAtual = valor;
    do {
        valorAtual = (int) (valor / pow(10, casas));
        if (valorAtual == 0) casas -= 3;
    } while ((valorAtual == 0) && (casas >= -12));
    return (casas / 3) + 4;
}
