#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// orderded_set ->  find_by_order(x)<itr, x being 0-indexed>; order_of_key(x)<count, strictly less>
 
typedef long long ll;
typedef long double lld;
typedef pair<int,int> pii;
#define  loop(n)        for(int i=0;i<(n);++i)
#define  rep(i,zz,n)    for(int i=zz;i<(n);++i)
#define  all(v)         v.begin(),v.end()
#define  pb             push_back
#define  ff             first
#define  ss             second
#define  sz(x)          (int)x.size()
#define  nline          cout<<'\n'
 
#define  debug(x)       cout<<#x<<" ";_print(x);cout<<'\n';
#define  _debug(a,b)    cout<<#a<<" [ ";array_debug(a,b);cout<<"]\n";
void array_debug(ll *a, ll n){ for(ll i=0;i<(n);++i) cout<<a[i]<<' ';}
void array_debug(int *a, int n){ for(int i=0;i<(n);++i) cout<<a[i]<<' ';}
void array_debug(ll *a, int n){ for(int i=0;i<(n);++i) cout<<a[i]<<' ';}
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
 
const lld eps=1e-9;
const int mod=1e9+7;
const ll inf=1e18;
const int N1=2e5+10;
 
int code(){
    int n,m;
    cin>>n>>m;
    map<pii,int> edge;
    vector<ll> cost(n+1,inf);
    
    loop(m){
        int a,b,c;
        cin>>a>>b>>c;
        if(edge.count({a,b}))   edge[{a,b}]=min({c,edge[{a,b}]});
        else    edge[{a,b}]=c;
    }
    rep(i,1,n+1)    edge[{0,i}]=0;
    cost[0]=0;
    
    loop(n+2){
        bool change=0;
        for(auto [x,y]:edge){
            if(cost[x.ff]+y<cost[x.ss]){
                change=1;
                cost[x.ss]=cost[x.ff]+y;
            }
        }
        if(change==0){
            cout<<"NO";
            return 0;
        }
    }
 
    vector<int> parent(n+1,-1);
    int last=-1;
    loop(n+1){
        for(auto [x,y]:edge){
            if(cost[x.ff]+y<cost[x.ss]){
                cost[x.ss]=cost[x.ff]+y;
                parent[x.ss]=x.ff;
                last=x.ss;
            }
        }
    }
    loop(n+1)   last=parent[last];
 
    vector<int> ans{last};
    do{
        ans.pb(parent[last]);
        last=parent[last];
    }while(last!=ans[0]);
    reverse(all(ans));
    cout<<"YES\n";
    for(auto x:ans) cout<<x<<' ';
    return 0;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int tc=1;
    // cin>>tc;
    loop(tc)  code();
    return 0;
}
