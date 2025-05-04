#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono> 
using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
typedef long double lld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int>  vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; 
#define f first
#define s second
#define PB push_back
#define mp make_pair
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
 
const int mod = 1000000007; 
 
int n,m,a,b;
vector<int> adjList[100001];
vector<int> visited(100001,0);
vector<int> V;
 
void dfs(int i){
    if(visited[i]) return;
    visited[i] = 1;
    for(int x : adjList[i]){
        if(!visited[x])
            dfs(x);
    }
}
 
void solve(){
    cin>>n>>m;
    REP(i,0,m){
        cin>>a>>b;
        adjList[a].PB(b);
        adjList[b].PB(a);
    }
    dfs(1);
    REP(i,1,n+1){
        if(!visited[i]){
            V.PB(i);
            dfs(i);
        }
    }
    cout<<V.size()<<endl;
    for(int x : V){
        cout<<1<<" "<<x<<endl;
    }
 
}
 
int main(){
    //auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //ll t;cin>>t;while(t--)
        solve();
 
    //auto stop = high_resolution_clock::now(); 
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << endl<<duration.count();
    return 0;
}