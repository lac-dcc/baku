#include <bits/stdc++.h>
using namespace std;
 
vector <vector <int>> A;
vector <int> se;
 
void dfs (int o, int p){
    
    for (int x: A[o]){
        
        if (x == p) continue;
        
        dfs (x,o);
        
        se[o] += se[x]+1;
    }
    
    return;
}
 
int main (){
    
    int n;
    cin >> n;
    
    A.assign(n+1,vector <int> ());
    se.assign(n+1,0);
    
    int x;
    
    for (int i=2; i<=n; i++){
        
        cin >> x;
        
        A[x].push_back(i);
        A[i].push_back(x);
    }
    
    dfs (1,0);
    
    for (int i=1; i<=n; i++){
        
        cout << se[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
