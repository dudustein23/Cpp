#include <iostream>
#include <iomanip>
#include "Capacitor.h"
#include "Diodo.h"
#include "Resistor.h"
#include "fonteTensao.h"
#include "Componente.h"
#include "fonteTensaoAC.h"
#include <cmath>

using namespace std;

enum tipo{
    serie = 1,
    paralelo,
};

int main()
{
    int menu(string texto, int min, int max);
    capacitor calculaTipo(tipo t, capacitor c1, capacitor c2);
    resistor calculaTipo(tipo t, resistor r1, resistor r2);

    diodo d1, d2;
    resistor r1, r2, req;
    capacitor c1, c2, ceq;

    while(1) {
        int opcao = menu("\n\nDigite 1 para calcular resistores, 2 para calcular capacitores e 3 para calcular a retificacao do sinal(4 para sair): ", 1, 4);

        if (opcao == 4) break;
        if (opcao == 1) {
            r1 = resistor("Digite o valor do primeiro resistor: ");
            r2 = resistor("Digite o valor do segundo resistor: ");
            opcao = menu("digite 1 para calcular serie e 2 para calcular paralelo: ", 1, 2);
            req = (resistor) calculaTipo(opcao == 1? serie : paralelo, r1, r2);
            cout << req;

        } else if(opcao == 3){
            double f;
            cout << "Digite a frequêcia da fonte AC: ";
            cin >> f;
            fonteTensaoAC f1(5, 15, 10, 0.1, f);

            d1.setv(0.7);
            d2.setv(0.7);

            for(int i = 0; i < 1000; i++){
        cout << "Tensao no segundo: " << i << " --- " << f1.tensaoAtual(i) << endl;

        if(f1.tensaoAtual(i) > d1.getV()){
        cout << "Tensao apos d1: " << f1.tensaoAtual(i) - d1.getV() << endl;
    } else {
        cout << "Tensao apos d1 = 0V" << endl;
    }

        if(f1.tensaoAtual(i)*(-1) > d2.getV()){
                cout << "Tensao apos d2: " << f1.tensaoAtual(i)*(-1) - d2.getV() << endl;
    } else {
        cout << "Tensao apos d2 = 0V" << endl;
    }
    }

        } else {
            c1 = capacitor("Digite o valor do primeiro capacitor: ");
            c2 = capacitor("Digite o valor do segundo capacitor: ");
            opcao = menu("digite 1 para calcular serie e 2 para calcular paralelo: ", 1, 2);
            ceq = (capacitor) calculaTipo(opcao == 1? serie : paralelo, c1, c2);
            cout << ceq;
        }
    }









  /*  digite 1 para serie e 2 para paralelo
    1: req=r1+r2 e ceq=(c1*c2)/(c1+c2)
    2: req=(r1*r2)/(r1+r2) e ceq=c1+c2
    imprimir req e ceq com tensao
*/
}

capacitor calculaTipo(tipo t, capacitor c1, capacitor c2) {
    capacitor ceq;
    if (t == serie) {
        ceq = c1 + c2;
    } else {
        ceq = c1 / c2;
    }
    return ceq;
}

resistor calculaTipo(tipo t, resistor r1, resistor r2) {
    resistor req;
    if (t == serie) {
        req = r1 + r2;
    } else {
        req = r1 / r2;
    }
    return req;
}

int menu(string texto, int min, int max) {
    int opcao = 0;
    cout << texto;
    do {
        cin >> opcao;
        if (opcao<min||opcao>max){
            cout << "Opcao invalida. Digite novamente: ";
        }
    } while (opcao<min||opcao>max);
}

