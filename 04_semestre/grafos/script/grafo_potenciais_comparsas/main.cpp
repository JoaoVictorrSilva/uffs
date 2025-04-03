/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      João Victor da Silva
 * Matricula: 2211100072
 */

#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int main(){
    
    int Pessoas, Ligacoes, Operacoes, X, suspect_x, suspect_y;
    char Turno;

    cin >> Pessoas >> Ligacoes;

    Grafo calls(Pessoas);

    for(int i = 0; i < Ligacoes; i++){
        cin >> suspect_x >> suspect_y >> Turno;
        if(Turno == 'W')
            calls.insert_edge(Aresta(suspect_x, suspect_y));
    }

    cin >> Operacoes;
    
    for(int i = 0; i < Operacoes; i++){
        cin >> X;
        std::cout << X << ":";
        std::vector<int> suspects = calls.busca_larg(X);

        for(int j : suspects)
            std::cout << " " << j;           
        
        std::cout << endl;
    }

    return 0;
}