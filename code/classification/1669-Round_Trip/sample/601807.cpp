#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
ll vis[maxn] = {0};
ll dis[maxn] = {0};
ll parent[maxn];
vector<vector<ll> >Q;
ll start = -1, end1 = -1;
void dfs(ll s){
    vis[s] = 1;
    for(auto u: Q[s]){
        if(!vis[u]){
            parent[u] = s;
            dfs(u);
        }
        else if(u!=parent[s]){
            start = u;
            end1 = s;
            return;
        }
    }
    return;
}
void print_path(ll start, ll end){
    if(start==end){
        cout<<start+1<<" ";
        return;
    }
    print_path(start, parent[end]);
    cout<<end+1<<" ";
    return;
}
ll count1 = 0;
ll count_path(ll start, ll end){
    if(start==end){
        count1++;
        return count1;
    }
    count1 = 1 + count_path(start, parent[end]);
    return count1;
}
int main(){
    ll n,m;
    cin>>n>>m;
    Q = vector<vector<ll> >(n);
    loop(i,0,m){
        ll t1,t2;
        cin>>t1>>t2;
        t1--;
        t2--;
        Q[t1].push_back(t2);
        Q[t2].push_back(t1);
    }
    loop(i,0,n){
        if(!vis[i]){
            dfs(i);
        }
        if(start!=-1){
            break;
        }
    }
    // cout<<start<<end1<<endl;
    if(start!=-1){
        cout<<count_path(end1, start)+1<<endl;
        print_path(end1, start);
        cout<<end1+1<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
