#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;
typedef vector< vector<int> > vvi;
typedef vector<string> vs;
typedef tuple<int,int,int> ti;
 
#define f first
#define s second
#define mp make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
#define REP1(i,a,b) for (int i = a; i <= b; i++)
const int MOD = 1000000000+7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<ti> edges;
    REP(_,0,m){
        int a,b,w; cin >> a >> b >> w;
        edges.push_back(make_tuple(a,b,w));
    }
    for (int i=1; i<=n; i++){
        edges.push_back(make_tuple(0,i,0));
    }
    vector<ll> dist(n+1, 1LL<<60);
    vector<int> prev(n+1, -1);
    int start = -1;
    dist[0] = 0;
    for(int i=0; i<n; i++){ //Repeat (n+1)-1 times
        for (auto e: edges){
            int a,b,w;
            tie (a,b,w) = e;
            dist[b] = min(dist[b], dist[a]+w);
        }
    }
    for(int i=0; i<n; i++){ //Repeat (n+1)-1 times
        for (auto e: edges){
            int a,b,w;
            tie (a,b,w) = e;
            if (dist[b] > dist[a]+w){
                dist[b] = dist[a]+w;
                start = b;
                prev[b] = a;
            }
            
        }
    }
    if (start == -1){
        cout << "NO" << endl; return 0;
    }
    
    for(int i=0; i<n; i++){
        start = prev[start];
    }
    vector<int> cycle(1,start);
    int v = start;
    while (true){
        v = prev[v];
        cycle.push_back(v);
        if(v == start) break;
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    for (int v: cycle) cout << v << " ";
}
