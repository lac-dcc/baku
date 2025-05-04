#include<bits/stdc++.h>
using namespace std;
 
int par(int x, vector<int> &parent){
    if(parent[x] == x) return x;
    else return parent[x] = par(parent[x], parent);
}
 
void merge(int x, int y, vector<int> &parent){
    int a = par(x, parent);
    int b = par(y, parent);
    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        if(par(x, parent) != par(y, parent)){
            merge(x, y, parent);
        }
    }
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(par(i, parent));
    }
    int len = s.size()-1;
    cout << len << "\n";
    while(len--){
        auto itr = s.begin();
        cout << *itr << " ";
        itr++;
        cout << *itr << "\n";
        s.erase(s.begin());
    }
}
