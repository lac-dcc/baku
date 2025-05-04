#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005
 
int ans=0;
int n,m;
char grid[maxN][maxN];
bool visited[maxN][maxN];
int dY[4]={1,0,-1,0};
int dX[4]={0,1,0,-1};
 
bool isValid(int y, int x){
    if(grid[y][x]=='#') return false;
    if(y<0 ||x<0 ||y>=n ||x>=m) return false;
    return true;
}
void solve(int y, int x){
    visited[y][x]=true;
    for(int i=0; i<4; i++){
        int newY=y+dY[i];
        int newX=x+dX[i];
        if(isValid(newY, newX)){
            if(!visited[newY][newX]){
                // ans++;
                visited[newY][newX]=true;
                solve(newY, newX);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isValid(i,j)){
                if(!visited[i][j]){
                    visited[i][j]=true;
                    ans++;
                    solve(i,j);
                }
            }
        }
    }
    cout<<ans;
}
