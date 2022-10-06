#ifndef FONTETENSAO_H
#define FONTETENSAO_H

#include "Componente.h"

class fonteTensao : public componente {
    public:
        fonteTensao(void);
        fonteTensao(double valorMin, double valorMax, double v);
        // Destrutor
        ~fonteTensao(void);
        bool setV(double v);
        double V();
        fonteTensao(double v);

    protected: // Atributo/metodo n�o � acessado fora do objeto
        double vmin;     // Tensao minima
        double vmax;     // Tensao maxima
};

#endif // FONTETENSAO_H
