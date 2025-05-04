#include<bits/stdc++.h>
//#include "DaVinci.h"
//#include "grader.cpp"
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int>vi;
typedef vector<vector<int>>vvi;
typedef vector<ll>vl;
typedef vector<vl> vvl;
typedef pair<int,int>pi;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<ld> vld;
typedef pair<ld,ld> pld;
//typedef tree<ll, null_type, less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template<typename T> ostream& operator<<(ostream& os, vector<T>& a){os<<"[";for(int i=0; i<ll(a.size()); i++){os << a[i] << ((i!=ll(a.size()-1)?" ":""));}os << "]\n"; return os;}
 
#define all(x) x.begin(),x.end()
#define YES out("YES")
#define NO out("NO")
#define out(x){cout << x << "\n"; return;}
#define GLHF ios_base::sync_with_stdio(false); cin.tie(NULL)
#define print(x){for(auto ait:x) cout << ait << " "; cout << "\n";}
#define gcd __gcd
#define popcount __builtin_popcountll
#define mp make_pair
 
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p){is >> p.first >> p.second;return is;}
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1, T2>& p){os <<"" << p.first << " " << p.second << ""; return os;}
void usaco(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
}
template<typename T>
void read(vector<T>& v){
    int n=v.size();
    for(int i=0; i<n; i++)
        cin >> v[i];
}
template<typename T>
vector<T>UNQ(vector<T>a){
    vector<T>ans;
    for(T t:a)
        if(ans.empty() || t!=ans.back())
            ans.push_back(t);
    return ans;
}
ll ceil(ll a,ll b){
    ll ans=a/b;
    if(a%b)ans++;
    return ans;
}
ld log (ld a,ld b){return log(b)/log(a);}
ll power(ll base, ll exp,ll M=1e9+7){//(base^exp)%M
    ll ans=1;
    while(exp){
        if(exp%2==1)ans=((ans%M)*(base%M))%M;
        base=((base%M)*(base%M))%M;
        exp/=2;
    }
    return ans;
}
 
string to_base(int n,int new_base){
    string s;
    int nn=n;
    while(nn){
        s+=to_string(nn%new_base);
        nn/=new_base;
    }
    reverse(all(s));
    return s;
}
 
ll lcm(ll a,ll b){
    ll x= (a/gcd(a,b));
    return b*x;
}
vl generate_array(ll n,ll mn=1,ll mx=1e18+1,bool permuatation=0){
    if(permuatation){
        vl a(n);
        for(int i=0; i<n; i++)
            a[i]=i+1;
        random_shuffle(all(a));
        return a;
    }
    if(mx==1e18+1)
        mx=n;
    vl ans(n);
    for(int i=0; i<n;i++)
        ans[i]=(mn+rand()%(mx-mn+1));
    return ans;
}
string substr(string s,int l,int r){
    string ans;
    for(int i=l; i<=r; i++)
        ans+=s[i];
    return ans;
}
 
 
void solve();
int main() {
    GLHF;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
struct Node{
    ll sum=0,mxpref=0,mxsuff=0,ans=0;
    Node(ll sum, ll mxpref,ll mxsuff, ll ans){
        this->sum=sum;
        this->mxpref=mxpref;
        this->mxsuff=mxsuff;
        this->ans=ans;
    }
};
Node* merge(Node* n1,Node* n2){
    Node ans(0,0,0,0);
    ans.sum=(n1->sum+n2->sum);
    ans.mxpref=max(n1->mxpref,n1->sum+n2->mxpref);
    ans.mxsuff=max(n2->mxsuff,n2->sum+n1->mxsuff);
    ans.ans=max({n1->ans, n2->ans, n1->mxsuff + n2->mxpref});
    return new Node(ans);
}
ll sz=1;
vector<Node*>t;
void update(ll i,ll v){
    t[i+=sz/2]=new Node(v,max(0ll,v),max(0ll,v),max(0ll,v));
 
    while(i>1){
        t[i/2]=((i<(i^1)) ?merge(t[i],t[i^1]):merge(t[i^1],t[i]) );
        i/=2;
    }
}
ll query(ll l,ll r){
    Node* ans=new Node(0,0,0,0);
    deque<Node*>dl,dr;
    for(l+=sz/2,r+=sz/2+1; l<r; l/=2,r/=2){
        if(l&1)dl.push_back(t[l++]);
        if(r&1)dr.push_front(t[--r]);
    }
    for(Node* nl:dl)
        ans=merge(ans,nl);
    for(Node* nr:dr)
        ans=merge(ans,nr);
    return ans->ans;
}
void solve(){
    ll n,q;
    cin >> n >> q;
    vl a(n);
    while(sz<=2*n)
        sz*=2;
    t.assign(sz,new Node(0,0,0,0));
    read(a);
    for(int i=0; i<n; i++)
        update(i,a[i]);
    while(q--){
        ll i,v;
        cin >> i >> v;
        update(i-1,v);
        cout << t[1]->ans << "\n";
    }
}
