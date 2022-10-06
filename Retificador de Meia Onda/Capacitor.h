#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <iostream>
#include <ostream>
#include <string>
#include "Componente.h"

class capacitor : public componente
{
    public:
        capacitor(void);
        capacitor(string texto);
        capacitor(double c);
        capacitor(double cap, double inct);
        double C(void);
        string getU(void);
        double valorReal();
        void setC(double);
        double V(double i);
        double I(double v);
        void setV(double v);
        void setI(double i);
        capacitor operator + (capacitor &outroC);
        capacitor operator / (capacitor &outroC);


    private:
};

#endif // CAPACITOR_H
