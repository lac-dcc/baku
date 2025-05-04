#include <iostream>
 
using namespace std;
 
#define MAXN 110
#define MAXS 3000010
 
int moedas[MAXN];
long long int vetor[MAXS];
 
int main(){
    int n, x;
    cin>>n>>x;
 
    for(int i = 0; i < n; i++)
        cin>>moedas[i];
 
    vetor[0] = 1;
    for(int i = 1; i <= x; i++)
        vetor[i] = 0;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(vetor[j] > 0 && j+moedas[i] <= x){
                vetor[j+moedas[i]] += vetor[j]%1000000007;
                vetor[j+moedas[i]] = vetor[j+moedas[i]]%1000000007;
            }
 
        }
    }
 
    printf("%lld", vetor[x]);
}