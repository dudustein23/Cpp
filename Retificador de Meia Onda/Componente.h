#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class componente
{
    public:
        componente();
        double getV(void);     //!< valor atual da tensão
        double I(void);     //!< valor atual da corrente
        string toString(void);

    protected:
        double nominal;
        string unidade;
        double tensao;       //!< Tensao presente nos terminais
        double corrente;    //!< corrente circulando pelo componente
        double dt;          //!< passo de tempo da simulação
};

 // Sobrecarga fora da classe
std::ostream& operator << (std::ostream&saida, componente &c);

#endif // COMPONENTE_H
