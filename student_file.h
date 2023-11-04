#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    int size = habilidades.size();
    int ganador = 0;
    int perdedor = 0;

    queue<int> cola;

    for (int i = 2; i < size; ++i) {
        cola.push(habilidades[i]);
    }

    int victorias = 0;
    int jugadorActual = habilidades[0];
    int retador = habilidades[1];

    vector<int> resultado(2);
    for (int juego = 1; juego <= K; ++juego) {
        if (jugadorActual > retador) {
            victorias++;
            resultado = {retador, jugadorActual};
            cola.push(retador);
        } else {
            victorias = 1;
            resultado = {jugadorActual, retador};
            cola.push(jugadorActual);
            jugadorActual = retador;
        }

        if (victorias == N) {
            cola.push(jugadorActual);
            jugadorActual = cola.front();
            cola.pop();
            victorias = 0;
        }
        retador = cola.front();
        cola.pop();
    }
    return resultado;
}
