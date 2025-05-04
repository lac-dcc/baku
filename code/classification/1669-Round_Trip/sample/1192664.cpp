#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5+10;
int n,m,a,b,par[N];
bool p,vis[N];
vector<int>adj[N];
vector<int>ans;
void print(int node){
    ans.push_back(node);
    if(par[node]==node)return;
    print(par[node]);
}
void dfs(int node){
    if(p)return;
    vis[node]=1;
    for(int i : adj[node]){
        if(p)return;
        if(!vis[i]){
            par[i]=node;
            dfs(i);
        }
        else{
            if(par[node]!=i){
                ans.push_back(i);
                par[i]=i;
                print(node);
                p=1;
                return;
            }
        }
    }
    return;
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(p)return 0;
        if(!vis[i]){
            dfs(i);
            if(p){
                cout<<ans.size()<<endl;
                for(int x : ans){
                    cout<<x<<" ";
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
