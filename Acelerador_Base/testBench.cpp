#include "algoritmo.h"
int main()
{
    // Inicializado con unos valores random ideales como PoC (Proof of Concept) con un error de 0.
    int position;
    ap_fixed<9,4> minEnergy;
    int contadorCorrectos=0;
    int contadorIncorrectos=0;

    TSignal S;
    TTrozo T;
    int posicion;
    ap_fixed<9,4> energia;
    float randomFloat;

// inicializamos la entrada
bucleGrande:
    for (int i = 0; i < 1000; i++)
    {
    bucleEntrada:

    	//cout<<"array de entrada:"<<"\n";
        for (int i = 0; i < M; i++)
        {
            randomFloat = (rand()) / static_cast<float>(RAND_MAX);
            randomFloat = randomFloat * 2.0 - 1.0;
            S.vec[i] = randomFloat;
            //cout<<"Números aleatorios): "<< S.vec[i]<<" posición: "<<i <<"\n";
        }

        int j = rand() % 1008 + 0;
        //cout<<"posición de inicio del trozo = "<< j<<"\n";
    bucleMuestra:
		//cout<<"trozo:" <<"\n";
		int z=0;
        for (int i = j; i < j+N; i++)
        {
            T.vec[z] = S.vec[i];
            //cout<<"T.vec[i] parte main"<<T.vec[i]<<"\n";
            z++;
        }

        findBestMatch(S, T, posicion, energia);

        if (energia < 0.5 && (posicion < 1008 && posicion >= 0))
        {
            cout << "-------------------------------------------------- \n";
            cout << "TEST NUMERO " << i << " CORRECTO \n";
            cout << "-------------------------------------------------- \n";
            contadorCorrectos++;
        }
        else
        {
            cout << "-------------------------------------------------- \n";
            cout << "TEST NUMERO " << i << " INCORRECTO \n";
            cout << "Energia mínima: "<<energia<<"\n";
            cout << "-------------------------------------------------- \n";
            contadorIncorrectos++;
        }

    }

    cout << "-------------------------------------------------- \n";
    cout << "HAY " << contadorCorrectos << " TEST CORRECTOS \n";
    cout << "TEST NUMERO " << contadorIncorrectos << " TEST INCORRECTOS \n";
    cout << "-------------------------------------------------- \n";
}
