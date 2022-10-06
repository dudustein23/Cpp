#include "fonteTensao.h"

// construtor - metodo chamado na criacao do objeto
fonteTensao::fonteTensao(void)
{
    componente();
    vmin = 0;
    vmax = 15;
    nominal = 5;
    tensao = 5;
    unidade="v";
}

fonteTensao::fonteTensao(double valorMin, double valorMax, double v)
{
    componente();
    vmin = valorMin;
    vmax = valorMax;
    tensao = v;
    nominal = v;
    unidade="v";
}

double fonteTensao::V()
{
    return nominal;
}

bool fonteTensao::setV(double v)
{
    if ((v < vmin) || (v > vmax)) {
        return false;
    }
    tensao = v;
    nominal = v;
    return true;
}

fonteTensao::~fonteTensao(void)
{
}

fonteTensao::fonteTensao(double v)
{
    nominal = v;
    tensao=v;
    unidade="v";
}
