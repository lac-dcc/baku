#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;
using ipair=pair<int,long long>; // nodo, ciudad
vector<vector<ipair>> plan;
 
long long Dijkstra(int salida, int destino, vector<vector<ipair>> & listaAdy) {
    int N = (int) listaAdy.size();
    // vector donde guardaremos las distancias r´ecord para llegar a cada nodo
    vector<vector<long long>> distancia(N, vector<long long>(2,1e18));  // 0 SIN USAR CUPON, 1 USANDO CUPON
    // la distancia de la salida a la salida es 0
    distancia[salida] = vector<long long>(2, 0);
  
    priority_queue<tuple<long long, int, int>> pq; 
    // a~nadimos la ´unica ruta conocida a la cola
    pq.push(make_tuple(0, salida, 0)); // {distancia, nodo, descuento usado?}
    while(!pq.empty()) {
        // extraemos la ruta m´as corta de la cola
        int nodo = get<1>(pq.top());
        long long distanciaAlt = -get<0>(pq.top());
        int cupon = get<2>(pq.top());
        pq.pop();
 
        if (distanciaAlt > distancia[nodo][cupon])
          continue; // la descartaremos si ya hemos encontrado una mejor
 
        for (ipair vecino: listaAdy[nodo]) {
          int nodoVecino = vecino.second;
          long long costeVecino = vecino.first;
 
          // Intentamos usar cupon en este salto
          if (cupon == 0) {
            if (distancia[nodoVecino][1] > distancia[nodo][0] + costeVecino/2) {
              distancia[nodoVecino][1] = distancia[nodo][0] + costeVecino/2;
              pq.push(make_tuple(-distancia[nodoVecino][1], nodoVecino, 1));
            }
          }            
 
          // Sin usar cupon en este salto ... seguimos con el valor de cupon previo
          if (distancia[nodoVecino][cupon] > distancia[nodo][cupon] + costeVecino) {
            distancia[nodoVecino][cupon] = distancia[nodo][cupon] + costeVecino;
            pq.push(make_tuple(-distancia[nodoVecino][cupon], nodoVecino, cupon));
          }
        }
      }
//    for (int i=0; i<N; i++)
//        cout << distancia[i]  << " ";
//    cout << endl;
   
    return distancia[destino][1];
 }
 
int main(){
    int n, m, a, b;
    long long c;
    cin >> n >> m;
    ipair temp;
    plan = vector<vector<ipair>>(n,vector<ipair>(0));
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        temp.second = b-1; // nodo
        temp.first = c; // distancia
        plan[a-1].push_back(temp);
    }
    cout << Dijkstra(0, n-1, plan) << endl;
}
