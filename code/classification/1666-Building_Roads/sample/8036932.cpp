#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
 
vector < vector<int> > path;
int vst[100001];
int n,m;
 
void dfs(int i){
    vst[i]=1;
    for (int v:path[i]){
        if (!vst[v]) dfs(v);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m; int a,b;
    vector <pair<int,int>> pp;
    path.resize(n+1);
    for (int i=0;i<m;i++){
        cin>>a>>b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (!vst[i]) {dfs(i);pp.push_back(make_pair(i-1,i));}
    }
    cout<<pp.size()-1<<endl;
    for (int i=1;i<pp.size();i++){
        cout<<pp[i].first<<" "<<pp[i].second<<endl;
    }
}
