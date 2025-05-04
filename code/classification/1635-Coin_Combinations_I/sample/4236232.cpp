#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long ul;
 
const long NUM = 1000000007;
 
bool pronto[1000000];
ul valore[1000000];
int n;
ul moneta[1000001];
ul x;
 
ul Risolvi(int s){
	if(s<0)
		return 0; // non ci sono modi per una somma negativa
		
	if(s==0)
		return 1; // 1 modo per ottenere una somma nulla
		
	if(pronto[s])  // utilit  della memoization
		return valore[s];
	
	ul t=0;
	for(int i=1; i <=n; i++){
		t += Risolvi(s-moneta[i]);  // scelta della moneta di indice i
		t = t % NUM;
	}
	// memoization
	valore[s] = t;
	pronto[s] = true;
	return t;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> x;
	
	for(int i=1; i<=n; i++){
		cin >> moneta[i];
	}
	
	cout << Risolvi(x);
	
	return 0;
}
 