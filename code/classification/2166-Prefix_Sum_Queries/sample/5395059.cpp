#include <bits/stdc++.h>
using namespace std;
 
// Define Template          Python++
// Data Structure and Algorithm
#define all(vec)            (vec).begin(),(vec).end() 
#define arrsize(arr)        sizeof(arr)/sizeof(int)
#define sortarr(arr)        sort(arr,arr+arrsize(arr));
#define sortvec(vec)        sort(all(vec));
#define minarr(arr)         *min_element(arr,arr+arrsize(arr))
#define minvec(vec)         *min_element(all(vec))
#define maxarr(arr)         *max_element(arr,arr+arrsize(arr))
#define maxvec(vec)         *max_element(all(vec))
#define sumarr(arr)         accumulate(arr,arr+arrsize(arr),0LL)
#define sumvec(vec)         accumulate(all(vec),0LL)
#define reversearr(arr)     reverse(arr,arr+arrsize(arr));
#define reversevec(vec)     reverse(all(vec));
#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define fors(var,arr)       for(auto &var:arr)
// Input Output Manage
#define debug(x)    cout<<(#x)<<" : "<<(x)<<endl;
#define test        cout<<"test"<<endl;
#define fastIO              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define floatprecision      cout<<fixed<<setprecision(9);
#define fileread            freopen("input.txt","r",stdin);
#define fileout             freopen("output.txt","w",stdout);
#define query               cin>>QUERY;while(QUERY--)
#define inputarr(arr,am)    int arr[am];fors(num,arr)cin>>num;
#define inputvec(vec,am)    vector<int> vec(am);fors(num,vec)cin>>num;
#define input(var)          int var;cin>>var;
#define input2(a,b)         int a,b;cin>>a>>b;
#define inputs(var)         string var;cin>>var;
#define print(var)          cout<<(var)<<endl;
#define prints(var)         cout<<(var)<<' ';
#define print2(var1,var2)   cout<<(var1)<<' '<<(var2)<<endl;
#define printp(paired)      cout<<(paired.first)<<' '<<(paired.second)<<endl;
#define printyes(cond)      cout<<((cond)?"YES":"NO")<<endl;
#define printarr(arr)       fors(num,arr){cout<<num<<' ';};cout<<endl;
#define printmap(hashmap)   for(auto[x,y]:hashmap)cout<<x<<":"<<y<<endl;
#define endline             cout<<endl;
// Macro
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define ms multiset
// Oneliner Function
ll sigma(ll num){return num*(num+1)/2;}
ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int long long
#define float long double
int QUERY;
// Constant
const int MOD = 1e9+7;
const long long INF = 1e18;
const int maxn = 2e5+5;
 
 
struct segtree{
    int l, r;
    int val = 0;
    int lazy = 0;
    segtree *tl = nullptr, *tr = nullptr;
    segtree(int n){
        int tn = log2(n-1) + 1;
        tn = (1<<tn);
        l = 0;
        r = tn - 1;
    }
    segtree(int a, int b){
        l = a;
        r = b;
    }
    void make_child(){
        int mid = (l+r)/2;
        if(!tl)
            tl = new segtree(l, mid);
        if(!tr)
            tr = new segtree(mid+1, r);
    }
    void push(){
        if(lazy == 0)return;
        val += lazy;
        if(l != r){
            make_child();
            tl->lazy += lazy;
            tr->lazy += lazy;
        }
        lazy = 0;
    }
    void add(int sl, int sr, int v){
        if(sl > r || sr < l)return; // out bound
        if(sl <= l && r <= sr){
            lazy += v;
            return;
        }
        push();
        make_child();
        tl->add(sl, sr, v);
        tr->add(sl, sr, v);
        tl->push();
        tr->push();
        val = max(tl->val, tr->val);
    }
    int rangequery(int ql, int qr){
        if(ql > r || qr < l)return -INF;
        push();
        if(ql <= l && r <= qr)return val;
        int ans = -INF;
        if(tl)ans = max(ans, tl->rangequery(ql, qr));
        if(tr)ans = max(ans, tr->rangequery(ql, qr));
        return ans;
    }
};
 
int32_t main(){
    fastIO
    
    input2(n,q)
    inputvec(arr,n)
    segtree container(n);
    range(i,0,arr.size())container.add(i, n-1, arr[i]);;
    while(q--){
        int x,a,b;
        cin>>x>>a>>b;
        if(x == 1){
            a--;
            container.add(a, n-1, -arr[a]);
            container.add(a, n-1, b);
            arr[a] = b;
        }else{
            a--;b--;
            int ans = container.rangequery(a,b);
            if(a > 0)ans -= container.rangequery(a-1,a-1);
            ans = max(0LL, ans);
            print(ans)
        }
    }
   
    
    
    return 0;
}
