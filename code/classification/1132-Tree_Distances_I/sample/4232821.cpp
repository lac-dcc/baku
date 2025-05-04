#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[200001];
int depth[200001];
int ans[200001];
 
void evaluate(int src,int par){
    int sd = 0;
    for(auto child:g[src]){
        if(child != par){
        evaluate(child,src);
        sd = max(sd, 1 + depth[child]);
      }
    }
    
    depth[src] = sd;
}
 
void solve(int src,int par,int par_ans){
    vector<int> pre,suf;
    
    for(auto child:g[src]){
        if(child != par){
        pre.push_back(depth[child]);
        suf.push_back(depth[child]);
        }
    }
    
    for(int i=1;i<pre.size();i++) pre[i] = max(pre[i], pre[i-1]);
    
    for(int i=(int)suf.size()-2;i>=0;i--) suf[i] = max(suf[i], suf[i+1]);
    
    int c = 0;
    for(auto child:g[src]){
        if(child==par) continue;
        int op1 = (c == 0) ? INT_MIN : pre[c-1];
        int op2 = (c == (int)suf.size()-1) ? INT_MIN : suf[c+1];
        int partial = 1 + max(par_ans, max(op1, op2));
        
        solve(child,src,partial);
        c++;
    }
    
    ans[src] = 1 + max(par_ans, (pre.empty() ? -1 : pre.back()));
}
 
int main() {
 
   int n;
   cin>>n;
   for(int i=1;i<n;i++){
       int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
   }
  evaluate(1,0);
  solve(1,0,-1);
  
  for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
