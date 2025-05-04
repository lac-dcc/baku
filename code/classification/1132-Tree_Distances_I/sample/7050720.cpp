#include<bits/stdc++.h>
using namespace std;
int v, u;
vector<int> tree[200005];
int dp1[200005];
int dp2[200005];
int maxi; 
 
void dfs(int src,int par, int c){
     if(c>maxi){
         maxi = c;
         u = src;
     }
 
     for(auto i : tree[src]){
        if(i!=par){
            dfs(i, src, c + 1); 
        }
     }
}
 
void dfs1(int src, int par,int c){
    if(c>maxi){
        maxi = c;
        v = src; 
    }
    
    for (auto i : tree[src])
    {
        
        if (i != par)
        {
            dfs1(i, src, c + 1);
        }
    }
}
 
void evelpath(int src,int par, int c){
     
    for(auto i:tree[src]){ 
        if(i!=par){
            evelpath(i, src, c + 1); 
        }
    }    
    dp1[src] = c;
}
 
void evelpath1(int src, int par, int c)
{
    
    for (auto i : tree[src])
    {
          if (i != par)
          {
            evelpath1(i, src, c + 1); 
          }
    }
    dp2[src] = c;
}
 
void callf(){
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    maxi = 0;
    dfs(1, 0, 0);
    maxi = 0; 
    dfs1(u, 0, 0);
    evelpath(u, 0,0);
    evelpath1(v, 0,0);
 
   
 
 
    for (int i = 1; i <= n; i++){
        cout << max(dp1[i], dp2[i]) << " ";
    }
}
    
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
     
     callf();
     
     }
return 0;
}
