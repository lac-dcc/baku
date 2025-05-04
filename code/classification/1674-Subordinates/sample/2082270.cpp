#include<bits/stdc++.h>
using namespace std;
 
int helper(vector<int> adj[],vector<int> &ans,int u){
    if(ans[u]!=-1){
        return ans[u];
    }
    int count = 0;
    for(int v : adj[u]){
        count++;
        count += helper(adj,ans,v);
    }
    return ans[u] = count;
}
 
int main(){
    int n;
    cin>>n;
    n++;
    vector<int> *adj = new vector<int>[n];
    for(int i=2;i<n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> ans(n,-1);
    for(int i=1;i<n;i++){
        if(ans[i] == -1)
            helper(adj,ans,1);    
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
