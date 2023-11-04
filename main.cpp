#include <vector>
#include <iostream>

using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    int size = habilidades.size();
    int ganador = 0;
    int perdedor = 0;

    queue<int> cola;

    for (int i = 2; i < tam; ++i) {
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

int main(){
    std::vector<int> habilidades1 = {1, 2, 3};
    std::vector<int> habilidades2 = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
    std::vector<int> habilidades4 = {30, 12};
    
    int N1=2, K1=2;
    int N2=10, K2=399;
    int N3=2, K3=4;
    int N4=34, K4=80;

}