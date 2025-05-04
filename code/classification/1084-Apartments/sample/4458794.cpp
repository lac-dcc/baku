#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false);
  int n_cli, n_ap, dif;
  cin >> n_cli >> n_ap >> dif;
 
  vector<ll> tam_desej(n_cli);
  vector<ll> tam_ap(n_ap);
  
  for (int i = 0; i < n_cli; i++){
    cin >> tam_desej[i];
  }
  
  for (int i = 0; i < n_ap; i++){
    cin >> tam_ap[i];
  }
 
  sort(tam_desej.begin(), tam_desej.end());
  sort(tam_ap.begin(), tam_ap.end());
 
  ll ans = 0;
  ll pos_desej = 0, pos_ap = 0; 
 
  while (pos_ap < n_ap && pos_desej < n_cli){ 
      if (tam_desej[pos_desej] + dif < tam_ap[pos_ap]){
        pos_desej++;
        continue;
      }
 
      if (abs(tam_desej[pos_desej] - tam_ap[pos_ap]) <= dif){
        ans++; // Mais uma resposta
        pos_desej++; // Outra pessoa
        pos_ap++; // Outro apartamento
      }
      else{
        if(tam_desej[pos_desej] < tam_ap[pos_ap]){
          pos_desej++; // Outra pessoa
          pos_ap++; // Outro apartamento
        }
        else{
          pos_ap++; // Outro apartamento         
        }
      }
      continue;
  }
  
  cout << ans << "\n";
 
  return 0;
}