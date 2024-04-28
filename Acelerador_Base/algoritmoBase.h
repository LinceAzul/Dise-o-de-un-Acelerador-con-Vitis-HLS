#ifndef ALGORITMOACELERADOR_ALGORITMO_H
#define ALGORITMOACELERADOR_ALGORITMO_H
#include <iostream>
#include <limits> // Para poner el valor más grande
#include <ap_fixed.h> // libreria punto fijo
using namespace std;

const int M = 1024;
const int N = 16;

//typedef ap_fixed<9,4> fixed;

typedef struct TSignal{
    ap_fixed<9,4> vec[M];
} TSignal;

typedef struct TTrozo{
    ap_fixed<9,4> vec[N];
} TTrozo;

void findBestMatch(const TSignal &S, const TTrozo &T, int &position, ap_fixed<9,4> &minEnergy);

#endif // ALGORITMOACELERADOR_ALGORITMO_H
