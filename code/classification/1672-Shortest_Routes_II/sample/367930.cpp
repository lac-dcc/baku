#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;
ii operator+(const ii& a, const ii& b){
    return {a.x+b.x,a.y+b.y};
}
ii operator-(const ii& a, const ii& b){
    return {a.x-b.x,a.y-b.y};
}
int n,m;
vvii g;
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    int q; cin>>n>>m>>q;
    g.resize(n);
    vvi dist(n, vi(n, INF));
    loop(i,0,n) dist[i][i]=0;
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        chkmin(dist[a][b],c); chkmin(dist[b][a],c);
    }
    loop(k,0,n){
        loop(i,0,n){
            loop(j,0,n){
                chkmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    loop(i,0,q){
        int a,b; cin>>a>>b;
        int d=dist[a-1][b-1];
        cout<<(d==INF?-1:d)<<endl;
    }
    return 0;
}
/*
color a
cls
g++ tmp.cpp -o a & a
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
 
 
*/
 
 
 
 
