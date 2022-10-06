#include "fonteTensaoAC.h"

#include <cmath>

fonteTensaoAC::fonteTensaoAC(void){
    fonteTensao();
}
fonteTensaoAC::fonteTensaoAC(double valorMin, double valorMax, double v, double inct, double freq) {
    fonteTensao(valorMin, valorMax, v);
    dt=inct;
    frequencia=freq;
}
// Destrutor
fonteTensaoAC::~fonteTensaoAC(void) {
    fonteTensao();
}

bool fonteTensaoAC::setV(double v, double freq){
    frequencia=freq;
    tensao=v;
    nominal=v;
}

double fonteTensaoAC::tensaoAtual(float seg) {
    float periodo=1.0/frequencia;
    tensao = (vmax - vmin) * sin(seg*frequencia*3.1415*2) + vmin;
    nominal = tensao;
    return tensao;
}


