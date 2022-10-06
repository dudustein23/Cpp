#ifndef FONTETENSAOAC_H_INCLUDED
#define FONTETENSAOAC_H_INCLUDED

#include "fonteTensao.h"

class fonteTensaoAC : public fonteTensao {
    public:
        fonteTensaoAC(void);
        fonteTensaoAC(double valorMin, double valorMax, double v, double inct, double freq);
        // Destrutor
        ~fonteTensaoAC(void);
        bool setV(double v, double freq);
        double tensaoAtual(float seg);

    protected:
        double frequencia;

};

#endif // FONTETENSAOAC_H_INCLUDED
