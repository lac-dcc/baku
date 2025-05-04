#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<vector<bool>> d(N+1,vector<bool>(N+1,true));
struct ii{
    int x;
    int y;
};
 
int n,m;
ii k[4] = {{-1,0},{0,-1},{1,0},{0,1}};
 
bool check(ii x, ii a){
    return x.x+a.x>=1 && x.x+a.x<=n && x.y+a.y>=1 && x.y+a.y<=m;
}
 
void bfs(ii x){
    deque<ii> bfs;
    d[x.x][x.y] = false;
    bfs.push_back(x);
    while(!bfs.empty()){
        ii tmp = bfs.front(); bfs.pop_front();
        for(auto e:k){
            if(check(tmp,e) && d[tmp.x+e.x][tmp.y+e.y]){
                bfs.push_back({tmp.x+e.x,tmp.y + e.y});
                d[tmp.x+e.x][tmp.y+e.y] = false;
            }
        }
    }
}
 
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j] == '#') d[i][j+1] = false;
            else d[i][j+1] = true;
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(d[i][j]){
                bfs({i,j});
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}
