/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      João Victor da Silva
 * Matricula: 2211100072
 */

#include <iostream>
#include "Digrafo.h"
#include "Aresta.h"

using namespace std;

int main() {

    int R, C = 0; // R = Regiões (Vértices) | C = Caminhos (Arestas).

    cin >> R >> C;
    Digrafo digrafo(R);

    int X, Y, D = 0;

    for(int i = 0; i < C; i++){
        cin >> X >> Y >> D;
        digrafo.insert_edge(Aresta(X, Y), D);
    }

    int O = 0;
    cin >> O;

    for (int i = 0; i < O; i++){
        int v = 0;
        int dp[R];
        cin >> v;
        
        bool aux = digrafo.max_vidas(v, dp);

        int max = dp[0];
        for(int j = 1; j < R; j++) 
            if(dp[j] > max) 
                max = dp[j];
  
        if(aux)
            cout << v << ":" << " " <<  max;
        else
            cout << v << ":" << " " << "ilimitada";
    }

    return 0;
}
