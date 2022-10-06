#ifndef RESISTOR_H
#define RESISTOR_H
#include <iostream>
#include "Componente.h"

class resistor : public componente {
    public:
        resistor(void);
        resistor(std::string texto);
        resistor(double r, std::string unidadeMedida);
        double getr(void);
        std::string getU(void);
        bool setr(double r);
        bool setr(double r, std::string unidadeMedida);
        double v(double i);
        double i(double v);
        double valorReal();
        resistor operator + (resistor &outroR);
        resistor operator / (resistor &outroR);

    private:
        bool setUnidade(std::string unidadeMedida);
};

#endif // RESISTOR_H
