#include "Capacitor.h"
#include <cmath>

const std::string unidades[] = {"p", "n", "u", "m", "faraday", "k", "M", "G"};

capacitor::capacitor(void) {
    componente();
}

capacitor::capacitor(string texto) {
    float valor = 0;
    cout << texto;
    do {
        cin >> valor;
        if (valor == 0) cout << "Valor invalido. Digite novamente: ";
    } while (valor == 0);
    componente();
    nominal = valor;
}

capacitor::capacitor(double cap) {
    componente();
    nominal = cap;
}

capacitor::capacitor(double cap, double inct) {
    componente();
    dt = inct;
    nominal = cap;
}

void capacitor::setV(double v) {
    tensao = v;
}

void capacitor::setI(double i) {
    corrente = i;
}

double capacitor::C(void) {
    return nominal;
}

double capacitor::V(double i){
    setI(i);
    tensao += ((corrente * dt) / nominal);
    return tensao;
}

double capacitor::I(double v){
    setI((v - tensao) * nominal);
    setV(v);
    return corrente;
}

string capacitor::getU(void)
 {
     return unidade;
 }

 capacitor capacitor::operator + (capacitor &outroC)
 {
     float paraUnidade(float valor);
     int getUnidade(float valor);
     capacitor ceq;
     float aux = (nominal * outroC.nominal)/(nominal + outroC.nominal);
     ceq.unidade = unidades[getUnidade(aux)];
     ceq.nominal= paraUnidade(aux);
     return ceq;
 }

 capacitor capacitor::operator / (capacitor &outroC)
 {
     float paraUnidade(float valor);
     int getUnidade(float valor);
     capacitor ceq; //!< capacitor equivalente da associacao serie
     float aux = nominal+outroC.nominal;
     ceq.unidade = unidades[getUnidade(aux)];
     ceq.nominal = paraUnidade(aux);
     return ceq;
 }

void capacitor::setC(double capa)
{
    nominal=capa;
}

double capacitor::valorReal(){
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

float paraUnidade(float valor) {
    int casas = 9;
    float valorFinal = valor / pow(10, casas);
    while ((0 == (int)(valorFinal)) && (casas >= -12)) {
        casas -= 3;
        valorFinal = valor / pow(10, casas);
    }
    return valorFinal;
}

int getUnidade(float valor) {
    int casas = 9;
    int valorAtual = valor;
    do {
        valorAtual = (int) (valor / pow(10, casas));
        if (valorAtual == 0) casas -= 3;
    } while ((valorAtual == 0) && (casas >= -12));
    return (casas / 3) + 4;
}
