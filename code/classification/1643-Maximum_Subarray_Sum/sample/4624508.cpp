#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
int main(){
	ll maior = -1e18, ant = 0;
    
	int n;
    cin >> n;
    
    ll vetor[n];
    
    for (int i=0; i<n; i++){
        cin >> vetor[i];
    }
    
    for (int i=0; i<n; i++){
        if (ant+vetor[i] >= vetor[i])
        	ant += vetor[i];
        else
        	ant = vetor[i];
        maior = max(maior, ant);
    }
    
    cout << maior;
}
