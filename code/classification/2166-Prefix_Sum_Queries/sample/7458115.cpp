#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma")
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define float double
 
#define pb push_back
#define pf push_front
#define mp make_pair
#define mii map<int,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define sii set<int,int>
#define vi vector<int>
#define vb vector<bool>
#define si set<int>
#define msi multiset<int>
#define di deque<int>
#define qi queue<int>
#define sti stack<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define setbits(x) _builtin_popcountll(x)
#define zrobits(x) _builtin_ctzll(x)
#define MAX_N 1e5+1
#define mod 1000000007
#define trie_len 26
#define inf 1e18
#define all(container) container.begin(),container.end()
#define rall(a) a.rbegin(), a.rend()
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define present(container, element)(container.find(element) != container.end())
#define cpresent(container, element)(find(all(container), element) != container.end())
#define ps(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n]
#define w(t) int t;  cin>>t;  while(t--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int func(int a,int b){return a+b;}
int min(int a,int b){if(a<=b) return a;else return b;}
int max(int a,int b){if(a>=b) return a;else return b;}
int func_take(int a,int b){return a*b;}
int min_take(int a,int b){return b;}
int max_take(int a,int b){return b;}
int power(int x,int n,int modulus=mod) {int r=1; while(n){if(n&1)r=(r*x)%modulus;x=(x*x)%modulus;n>>=1;} return r%modulus;}
int gcd(int a,int b) { if(a<b) return gcd(b,a); else if(b==0) return a; else return gcd(b,a%b); }
int gcd_extended(int a,int m,int& x,int& y) { if(m==0) { x=1; y=0; return a; }
else { int p=gcd_extended(m,a%m,x,y),y1=x-(a/m)*y,x1=y; y=y1; x=x1; return p; } }
int Inverse_mod_from_euclid(int n,int modulus=mod) {int x=1,y=1,ans=0;if(n<modulus) ans=gcd_extended(modulus,n,y,x);
else ans=gcd_extended(n,modulus,x,y);x=(x+modulus)%modulus;if(n*x%modulus != 1) return -1;else return x;}
int Inverse_mod_from_fermat(int n,int modulus=mod) { return power(n,modulus-2,modulus); }
int get_hash(string s,int p=29791,int m=mod) {int n=s.length(),hash=0,p_pow=1;for(int i=0;i<n;i++){hash=(hash+(s[i]-'a'+1)*p_pow)%m;
p_pow=(p_pow*p)%m;}return hash;}
 
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
 
class SieveOfEratosthenes {
    public:
    vector<bool> isprime;
    vector<int> primes,SPF;
    
    SieveOfEratosthenes(int N=MAX_N) {
        isprime.resize(N); SPF.resize(N);
        isprime[0]=isprime[1]=false;
        SPF[0]=2; SPF[1]=1;
        for(int i=2;i<N;i++) {
            if(isprime[i]) { primes.push_back(i); SPF[i]=i; }
            for(int j=0;j<primes.size() && i*primes[j]<N && primes[j]<=SPF[i];j++) {
                isprime[i*primes[j]]=false;
                SPF[i*primes[j]]=primes[j];
            }
        }
        return;
    }
};
 
class NCR {
    private:
    vector<int> fact;
    vector<int> Ifact;
    int modulo;
 
    public:
    NCR(int size=MAX_N,int modulus=mod) {
        fact.resize(size); Ifact.resize(size);
        fact[0]=fact[1]=Ifact[0]=Ifact[1]=1;
        for(int i=2;i<=MAX_N;i++) {
            fact[i]=(fact[i-1]*i)%modulus;
            Ifact[i]=(Ifact[i-1]*Inverse_mod_from_fermat(i,modulus))%modulus;
        }
        modulo=modulus; return;
    }
    
    int nCr(int n,int r) {
        if(n<0||r<0||n<r) return 0;
        return (((fact[n]*Ifact[r])%modulo)*Ifact[n-r])%modulo;
    }
};
 
class DSU {
    private:
    vector<int> dsu_parent;
    vector<int> dsu_size;
 
    public:
    DSU(int size=MAX_N) {
        dsu_parent.resize(size);
        dsu_size.resize(size);
        return;
    }
 
    void make(int v) {
        dsu_parent[v]=v; dsu_size[v]=1;
        return;
    }
 
    int find(int v) {
        if(v==dsu_parent[v]) return v;
        return dsu_parent[v]=find(dsu_parent[v]);
    }
 
    void merge(int a,int b) {
        a=find(a); b=find(b);
        if(a!=b) {
            if(dsu_size[a]<dsu_size[b]) swap(a, b);
            dsu_parent[b]=a;
            dsu_size[a]+=dsu_size[b];
        }
        return;
    }
};
 
class LCA {
private:
    vi height,euler,first,segtree;
    vb visited;
    int n;
    void dfs(vector<vector<int>>&adj,int node,int h) {
        visited[node]=true; height[node]=h;
        first[node]=euler.size();
        euler.pb(node);
        for(auto to:adj[node]) {
            if(!visited[to]) { dfs(adj,to,h+1); euler.pb(node); }
        }
        return;
    }
 
    void build(int node,int b,int e) {
        if(b==e) segtree[node] = euler[b];
        else {
            int mid=(b+e)/2;
            build(node<<1,b,mid);
            build(node<<1|1,mid+1,e);
            int l=segtree[node<<1],r=segtree[node<<1|1];
            segtree[node]=(height[l]<height[r])?l:r;
        }
        return;
    }
 
    int query(int node,int b,int e,int L,int R) {
        if(b>R||e<L) return -1;
        if(b>=L&&e<=R) return segtree[node];
        int mid=(b+e)>>1,left=query(node<<1,b,mid,L,R),right=query(node<<1|1,mid+1,e,L,R);
        if(left==-1) return right;
        if(right==-1) return left;
        return height[left]<height[right]?left:right;
    }
    
    public:
    LCA(vector<vi>&adj,int root=0) {
        n=adj.size(); height.resize(n);
        first.resize(n); euler.reserve(n*2);
        visited.assign(n,false); dfs(adj,root,0);
        int m=euler.size(); segtree.resize(m*4);
        build(1, 0, m - 1);
        return;
    }
    
    int lca(int u,int v) {
        int left=first[u],right=first[v];
        if(left>right) swap(left, right);
        return query(1,0,euler.size()-1,left,right);
    }
    
    int dist(int u,int v) {
        int lx=lca(u,v);
        return height[u]+height[v]-2*height[lx];
    }
};
 
class Trie {
    private:
    struct Vertex {
        int next[trie_len];
        bool output = false;
        Vertex() { fill(begin(next), end(next), -1);}
    };
    vector<Vertex> trie;
    char start;
    
    public:
    Trie(char st='a') {
        trie.emplace_back(); start=st;
        return;
    }
    
    void add(string s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - start;
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].output = true;
        return;
    }
    
    bool find(string s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - start;
            if (trie[v].next[c] != -1) v = trie[v].next[c];
            else return false;
        }
        return trie[v].output;
    }
};
 
class SparseTable {
    private:
    int (*function) (int,int);
    int n,modulo,k;
    vector<vector<int>> spt;
 
    public:
    SparseTable(vector<int>& a,int fx(int,int)=func,int modulus=mod) {
        n=a.size(); modulo=modulus; function=fx;
        k=log2(n)+1; spt.assign(n,vector<int>(k));
        for(int i = 0; i < n; i++) spt[i][0]=a[i];
        for(int j = 1; j < k; j++) {
            for (int i=0; i+(1<<j)<= n;i++) {
                spt[i][j] = function(spt[i][j-1], spt[i+(1<<(j-1))][j - 1])%modulo;
            }
        }
        return;
    }
 
    int query(int u,int v) {
        if(u>v) swap(u,v);
        int j = log2(v-u+1);
        return function(spt[u][j],spt[v-(1<<j)+1][j])%modulo;
    }
};
 
class FenwickTree {
    private:
    vector<int> tree;
    int n,modulo;
 
    public:
    FenwickTree(vector<int>& a,int modulus=mod) {
        n=a.size(); tree.resize(n);
        modulo=modulus;
        for(int i=0;i<n;i++) if((i+((i+1)&-(i+1)))<n) tree[i+((i+1)&-(i+1))]+=tree[i];
        return;
    }
    
    int sum(int k) {
        int ans=0;
        while(k>-1) { ans=(ans+tree[k])%modulo; k-=((k+1)&-(k+1)); }
        return ans;
    }
    
    void add(int k,int x) {
        while(k<n) {
            tree[k]=(tree[k]+x)%modulo;
            k+=((k+1)&-(k+1));
        }
        return;
    }
};
 
class SegmentTree {
    private:
    int (*function)(int,int);
    vector<int> T;
    int n,modulo;
 
    public:
    SegmentTree(vector<int>& v,int fx(int,int)=func,int modulus=mod) {
        n=v.size(); vector<int> st(2*n);
        for(int i=0;i<n;i++) st[n+i]=v[i];
        for(int i=n-1;i>-1;i--) st[i]=fx(st[i<<1],st[i<<1|1])%modulus;
        function=fx; T=st; modulo=modulus;
        return;
    }
 
    void modify(int p,int v) {
        int n=T.size()/2;
        for(T[p+=n]=v;p>1;p>>=1) T[p>>1]=function(T[p],T[p^1])%modulo;
        return;
    }
 
    int query(int l,int r) {
        int res=0,n=T.size()/2,flag=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if(l&1) {
                if(flag==1) res=function(res,T[l++])%modulo;
                else { res=T[l++]; flag=1; }
            }
            if(r&1) {
                if(flag==1) res=function(res,T[--r])%modulo;
                else { res=T[--r]; flag=1; }
            }
        }
        return res;
    }
};
 
// class SegmentTreeLazyPropagation {
//     private:
//     int (*function)(int,int);
//     int (*take) (int,int);
//     vector<int> tree,lazy,size;
//     int n,modulo;
 
//     vector<int> create(vector<int>& v) {
//         int len=log2(v.size());
//         if(pow(2,len)<v.size()) len++;
//         vector<int> ans(pow(2,len),0);
//         for(int i=0;i<v.size();i++) ans[i]=v[i];
//         return ans;
//     }
 
//     void propogate(int i) {
//         tree[i]=(tree[i]+take(size[i],lazy[i])%modulo)%modulo;
//         if(i<<1 < 2*n) lazy[i<<1]=(lazy[i<<1]+lazy[i])%modulo;
//         if((i<<1|1) < 2*n) lazy[i<<1|1]=(lazy[i<<1|1]+lazy[i])%modulo;
//         lazy[i]=0; return;
//     }
 
//     pair<int,int> query(int a,int b,int k,int x,int y) {
//         propogate(k);
//         if(b<x || a>y) return {0,-1};
//         else if(a<=x && y<=b) return {tree[k],0};
//         int d=(x+y)/2;
//         pair<int,int> ret1=query(a,b,2*k,x,d);
//         pair<int,int> ret2=query(a,b,2*k+1,d+1,y);
//         if(ret1.second==-1 && ret2.second==-1) return {0,-1};
//         else if(ret1.second==-1) return ret2;
//         else if(ret2.second==-1) return ret1;
//         else return {function(ret1.first,ret2.first)%modulo,0};
//     }
 
//     void modify(int a,int b,int c,int k,int x,int y) {
//         if(b<x || a>y) return;
//         else if(a<=x && y<=b) {
//             tree[k]=(tree[k]+take(size[k],lazy[k])%modulo)%modulo;
//             lazy[k]=(lazy[k]+c)%modulo;
//             return;
//         }
//         int d=(x+y)/2;
//         modify(a,b,c,2*k,x,d); modify(a,b,c,2*k+1,d+1,y);
//         tree[k]=function((tree[k<<1]+take(size[k<<1],lazy[k<<1])%modulo)%modulo,
//                         (tree[k<<1|1]+take(size[k<<1|1],lazy[k<<1|1])%modulo)%modulo)%modulo;
//         return;
//     }
 
//     public:
//     SegmentTreeLazyPropagation(vector<int>& vx,int fx(int,int)=func,int tx(int,int)=func_take,int modulus=mod) {
//         vector<int> v=create(vx);
//         n=v.size(); vector<int> st(2*n); size.assign(2*n,0);
//         function=fx; take=tx;
//         for(int i=0;i<n;i++) { st[n+i]=v[i]; size[n+i]=1; }
//         for(int i=n-1;i>-1;i--) {
//             st[i]=function(st[i<<1],st[i<<1|1])%modulus;
//             size[i]=(size[i<<1]+size[i<<1|1]);
//         }
//         tree=st; modulo=modulus; lazy.assign(2*n,0);
//         return;
//     }
 
//     void modify(int u,int v,int x) {
//         modify(u,v-1,x,1,0,n-1);
//         return;
//     }
 
//     int query(int l,int r) {
//         pair<int,int> ret=query(l,r-1,1,0,n-1);
//         if(ret.second==-1) return -1;
//         else return ret.first;
//     }
// };
 
class SegmentTreeLazyPropagation {
    private:
    vector<int> tree,lazy,size;
    int n,modulo;
 
    vector<int> create(vector<int>& v) {
        int len=log2(v.size());
        if(pow(2,len)<v.size()) len++;
        vector<int> ans(pow(2,len),0);
        for(int i=0;i<v.size();i++) ans[i]=v[i];
        return ans;
    }
 
    void propagate(int i) {
        tree[i]=(tree[i]+lazy[i])%modulo;
        if(i<<1 < 2*n) lazy[i<<1]=(lazy[i<<1]+lazy[i])%modulo;
        if((i<<1|1) < 2*n) lazy[i<<1|1]=(lazy[i<<1|1]+lazy[i])%modulo;
        lazy[i]=0; return;
    }
 
    pair<int,int> query(int a,int b,int k,int x,int y) {
        propagate(k);
        if(b<x || a>y) return {0,-1};
        else if(a<=x && y<=b) return {tree[k],0};
        int d=(x+y)/2;
        pair<int,int> ret1=query(a,b,2*k,x,d);
        pair<int,int> ret2=query(a,b,2*k+1,d+1,y);
        if(ret1.second==-1 && ret2.second==-1) return {0,-1};
        else if(ret1.second==-1) return ret2;
        else if(ret2.second==-1) return ret1;
        else return {max(ret1.first,ret2.first),0};
    }
 
    void modify(int a,int b,int c,int k,int x,int y) {
        propagate(k);
        if(b<x || a>y) return;
        else if(a<=x && y<=b) {
            lazy[k]=(lazy[k]+c)%modulo;
            return;
        }
        int d=(x+y)/2;
        modify(a,b,c,2*k,x,d); modify(a,b,c,2*k+1,d+1,y);
        tree[k]=max((tree[k<<1]+lazy[k<<1])%modulo,(tree[k<<1|1]+lazy[k<<1|1]))%modulo;
        return;
    }
 
    public:
    SegmentTreeLazyPropagation(vector<int>& vx,int modulus=mod) {
        vector<int> v=create(vx);
        n=v.size(); vector<int> st(2*n); size.assign(2*n,0);
        for(int i=0;i<n;i++) { st[n+i]=v[i]; size[n+i]=1; }
        for(int i=n-1;i>-1;i--) {
            st[i]=max(st[i<<1],st[i<<1|1])%modulus;
            size[i]=(size[i<<1]+size[i<<1|1]);
        }
        tree=st; modulo=modulus; lazy.assign(2*n,0);
        return;
    }
 
    void modify(int u,int v,int x) {
        modify(u,v-1,x,1,0,n-1);
        return;
    }
 
    int query(int l,int r) {
        pair<int,int> ret=query(l,r-1,1,0,n-1);
        if(ret.second==-1) return -1;
        else return ret.first;
    }
};
 
void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
}
 
void solve()
{
    int n,q;  cin>>n>>q;
    vi x(n),sm(n,0);
    for(int i=0;i<n;i++) {
        cin>>x[i];
        if(i==0) sm[i]=x[i];
        else sm[i]=sm[i-1]+x[i];
    }
    SegmentTreeLazyPropagation S(sm,1e18);
    while(q--) {
        // for(int i=0;i<n;i++) cerr<<S.query(i,i+1)<<" "; cerr<<"\n";
        int t;  cin>>t;
        if(t==1) {
            int k,u;  cin>>k>>u;  k--;
            S.modify(k,n,u-x[k]);
            x[k]=u;
        }
        else {
            int a,b;  cin>>a>>b; a--;
            int mx=S.query(a,b);
            if(a>0) mx-=S.query(a-1,a);
            cout<<max(0,mx)<<"\n";
        }
    }
    return;
}
 
int32_t main()
{
    dkj();
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++) {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
