#include<iostream>
#include<vector>
using namespace std;
const int N=1e7;
vector<vector<int>>tree(N);
void solve(int src, int par, vector<int>&ans){
    int subordinates=0;
    for(int child:tree[src]){
        if(child!=par){
            solve(child,src,ans);
            subordinates+=(1+ans[child]);
        }
    }
    ans[src]=subordinates;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    vector<int>ans(n+1);
    solve(1,0,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
