#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <math.h>
using namespace std; 
#define all(a) a.begin(),a.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define ll long long
long long INF = (long long)1e9;
long long MOD = 1000000007;
vector<vector<long long>> a(200009),backa(200009);  // khong trong so
 
 
// unordered_map<long long,vector<long long>> a;
// vector<pair<long long,long long>> a[200009],aback[200009];
// vector<pair<long long, pair<long long, long long>>> a[100009];
// char a[1009][1009];
bool visited[200009];
long long luu[200009],luu1[200009],luuback[200009],maxvet[100009],buocdi[100009],thu[100009];
 
 
// unordered_map<long long,long long> luu;
 
long long truoc[200009],c[209][209];
long long n,m,x,y,w,st,en,l=0,kt=0,dem=0,d=0,k,F;
vector<long long> luumang,topo;
long long demluu[200009],demluu1n[200009],demluun1[200009];
long long dx[4]={-1,0,0,1};
long long dy[4]={0,-1,1,0};
long long colo[100009],dd=0;
 
 
 
 
 
long long ans[200009];
void DFS(int u, int par){
 
    int dem=0;
 
 
    for (int i=0; i<a[u].size(); i++){
        if (a[u][i]!=par){
            // cout << a[u][i] << 'F' << "\n";
            DFS(a[u][i],u);
            // cout << a[u][i] << 'M' << "\n";
 
            dem+=(ans[a[u][i]]+1);
 
        }
    }
    ans[u]=dem; // cout << u << ' ' << 'l' << ans[u] <<  "\n";
}
 
 
 
int luuu=0;
void BFS(int u){
    for (int i=0; i<=n; i++){
        visited[i]=false; luu[i]=INF;
    }
    queue<int> q;
    q.push(u);
    luu[u]=0;
    while (q.empty()==false){
        int v=q.front(); q.pop();
 
        visited[v]=true;
        // cout << v << ' ';
        
        if (q.empty()){
            luuu=v;
        }
        
        for (int i=0; i<a[v].size(); i++){
            if (visited[a[v][i]]==false){
                luu[a[v][i]]=luu[v]+1;
                q.push(a[v][i]);
            }
        }
    }
}
 
 
 
 
signed main() {
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    int q;
    cin >> n;
    for (int i=1; i<n; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
 
    
    BFS(1);
 
    // cout << luuu;
 
 
    int tam=luuu;
    BFS(tam);
 
    cout << luu[luuu];
 
 
    
    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
 
 
 
 
 
 
 
 
