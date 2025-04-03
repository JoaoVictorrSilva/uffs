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
#include <limits.h>
#include <climits>  

using namespace std;

Digrafo::Digrafo(int r){
  regioes = r;
  vida = 0;

  adj.resize(r);

  for(int i = 0; i < r; i++)
    adj[i].resize(r, 0); // 100 equivalente ao 0 pois pesos das arestas podem ser 0;
}

void Digrafo::insert_edge(Aresta S, int vida_cano){
  if(adj[S.v1][S.v2] != 0)
    return;
  
  adj[S.v1][S.v2] = vida_cano;
}

bool Digrafo::max_vidas(int s, int dp[]){

  for(int i = 0; i < regioes; i++)
    dp[i] = INT_MIN; 

  dp[s] = 0;

  bool aux = Bellman_Ford(s, dp);
  return aux;
}

bool Digrafo::Bellman_Ford(int s, int dp[]){
  for(int u = 0; u < regioes; u++)
    for(int v = 0; v < regioes; v++)
      if(adj[u][v] != 0 && dp[u] != INT_MIN && dp[v] < dp[u] + adj[u][v])
        dp[v] = dp[u] + adj[u][v];

  for(int u = 0; u < regioes; u++)
    for(int v = 0; v < regioes; v++)
      if(adj[u][v] != 0 && dp[u] != INT_MIN && dp[v] < dp[u] + adj[u][v])
        return false; 

  return true;
}