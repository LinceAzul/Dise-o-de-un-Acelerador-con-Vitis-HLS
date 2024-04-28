#include "algoritmo.h"

/**
 Encuentra la posicion de una pieza de señal (T) dentro de una señal mas grande (S) que minimiza el error
 **/
void findBestMatch(const TSignal &S, const TTrozo &T, int &position, ap_fixed<9,4> &minEnergy){
	ap_fixed<9,4> diff, currentEnergy;
	ap_fixed<9,4> aux;
    minEnergy = numeric_limits<float>::max(); // Inicializado con el maximo valor posible
    //cout<<"numero inicial"<<minEnergy<<"\n";
    position = -1;

    for (int i = 0; i <= M - N; i++){
        currentEnergy = 0.0;
        for (int n = 0; n < N; n++){
            diff = S.vec[i + n] - T.vec[n];
            //cout<<"S.vec[i+n]: "<<S.vec[i+n]<<"\n";
            //cout<<"T.vec[n]: "<<T.vec[n]<<"\n";
            //cout<< "diff: "<<diff<<"\n";
            aux = diff * diff;
            //cout<<"aux: "<<aux<<"\n";
            currentEnergy = currentEnergy + aux;
            //cout<< "Suma energías= "<< currentEnergy <<"\n";
        } // end for interno
        // Si la energia actual es menor que la minima, la actualizo
        if (currentEnergy < minEnergy){
            minEnergy = currentEnergy;
            position = i;
        }
    } // end for 1
}
