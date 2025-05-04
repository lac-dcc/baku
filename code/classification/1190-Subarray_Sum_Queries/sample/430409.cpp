#include "bits/stdc++.h"
 
using namespace std;
 
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define int long long
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define INF LLONG_MAX
#define EPS 1e-9
#define all(v) (v).begin(),(v).end()
#define sq(x) ((x)*(x))
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
typedef long double dbl;
bool codejam = 0;
 
const int MOD = 1000*1000*1000 + 7;
const int NMAX = 1000*1000 + 11;
 
int arr[NMAX];
int n,m,p,q,k,a,b,c,ans;
string s,str;
char ch;
vector<int> v;
 
struct node{
    int ans,sum,suff,pref;
};
 
node t[NMAX];
 
node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
 
node make_node(int x){
    node res;
    res.sum = x;
    res.pref = res.suff = res.ans = max(0LL,x);
    return res;
}   
 
// void build(){
//     for(int i=n-1; i>0; i--){
//         t[i] = combine(t[i<<1],t[i<<1|1]);
//     }
//     return;
// }
 
void modify(int p,int x){
    // node val = make_node(x);
    for(t[p+=n] = make_node(x); p >>= 1;){
        t[p] = combine(t[p<<1],t[p<<1|1]);
    }
}
 
int query(int l, int r){
    node ans_left = make_node(0), ans_right = make_node(0);
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if(l&1)
            ans_left=combine(ans_left,t[l++]);
        if(r&1)
            ans_right=combine(t[--r],ans_right);
    }
    node ans = combine(ans_left, ans_right);
    return ans.ans;
}
 
int x;
 
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=1000000;i++){
        t[i] = make_node(0);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        modify(i,x);
        // tr(t[i+n].ans);
    }
    for(int i=1;i<2*n;i++){
        // tr(i,t[i].ans);
    }
    while(m--){
        cin>>p>>x;
        // cout<<p<<" "<<x<<"\n";
        modify(p-1,x);
        cout<<query(0,n)<<" ";
    }
}
 
int32_t main(){ fio;
    int t = 1;
    int cs = 1;
    // cin>>t;
    while(t--){
        if(codejam){
            cout<<"Case #"<<cs<<": ";
        }
        cs++;
        solve();
        cout<<"\n";
    }
}
