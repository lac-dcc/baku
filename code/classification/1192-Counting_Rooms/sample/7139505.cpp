#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using ii =pair<long,long>;
 
const int N = 1e6;
 
int inf = 1e9;
int mod = 1e9 + 7;
 
void BFS(int i1,int i2, string a[],vector<vector<bool>>&visited){
    visited[i1][i2]=1;
    queue<pair<int,int>> q;
    int rdiff[4]={-1,0,1,0};
    int cdiff[4]={0,-1,0,1};
    q.push({i1,i2});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+rdiff[i];
            int nc=c+cdiff[i];
            if(nr>=0 && nr<visited.size() && nc>=0 && nc<a[0].size() && !visited[nr][nc] && a[nr][nc]=='.'){
                visited[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
}
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,m;
    cin>>n>>m;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<bool>> visited(n,vector<bool> (m,0));
    int ans=0;
    // for(int i=0;i<n;i++){
    //     if(a[i][0]=='.' &&!visited[i][0]){
    //         BFS(i,0,a,visited);
    //     }
    //     if(a[i][m-1]=='.'&&!visited[i][m-1]){
    //         BFS(i,m-1,a,visited);
    //     }
    // }
    // for(int i=0;i<m;i++){
    //     if(a[0][i]=='.' &&!visited[0][i]){
    //         BFS(0,i,a,visited);
    //     }
    //     if(a[n-1][i]=='.'&&!visited[n-1][i]){
    //         BFS(n-1,i,a,visited);
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.' && !visited[i][j]){
                BFS(i,j,a,visited);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
