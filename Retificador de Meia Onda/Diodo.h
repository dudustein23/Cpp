#ifndef DIODO_H_INCLUDED
#define DIODO_H_INCLUDED
#include "Componente.h"

class diodo : public componente {
    public:
        diodo(void);
        double setv(double v);
        double seti(double i);
        ///string toString(void);

    private:
};

#endif // DIODO_H_INCLUDED
