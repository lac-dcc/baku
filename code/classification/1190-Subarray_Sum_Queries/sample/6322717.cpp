#include <bits/stdc++.h>
using namespace std;
 
// Define Template		  Python++
// Data Structure and Algorithm
#define all(vec)			(vec).begin(),(vec).end() 
#define arrsize(arr)		sizeof(arr)/sizeof(int)
#define sortarr(arr)		sort(arr,arr+arrsize(arr));
#define sortvec(vec)		sort(all(vec));
#define minarr(arr)		 *min_element(arr,arr+arrsize(arr))
#define minvec(vec)		 *min_element(all(vec))
#define maxarr(arr)		 *max_element(arr,arr+arrsize(arr))
#define maxvec(vec)		 *max_element(all(vec))
#define sumarr(arr)		 accumulate(arr,arr+arrsize(arr),0LL)
#define sumvec(vec)		 accumulate(all(vec),0LL)
#define reversearr(arr)	 reverse(arr,arr+arrsize(arr));
#define reversevec(vec)	 reverse(all(vec));
#define range(i,s,e)		for(int i=s;i<e;i++)
#define range2(i,s,e)	   for(int i=s;i>=e;i--)
#define fors(var,arr)	   for(auto &var:arr)
// Input Output Manage
#define debug(x)			cout<<(#x)<<" : "<<(x)<<endl;
#define test				cout<<"test"<<endl;
#define fastIO			  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define floatprecision	  cout<<fixed<<setprecision(9);
#define fileread			freopen("input.txt","r",stdin);
#define fileout			 freopen("output.txt","w",stdout);
#define query			   cin>>QUERY;while(QUERY--)
#define inputarr(arr,am)	int arr[am];fors(num,arr)cin>>num;
#define inputvec(vec,am)	vector<int> vec(am);fors(num,vec)cin>>num;
#define input(var)		  int var;cin>>var;
#define input2(a,b)		 int a,b;cin>>a>>b;
#define inputs(var)		 string var;cin>>var;
#define print(var)		  cout<<(var)<<endl;
#define prints(var)		 cout<<(var)<<" ";
#define print2(var1,var2)   cout<<(var1)<<" "<<(var2)<<endl;
#define printp(paired)	  cout<<(paired.first)<<" "<<(paired.second)<<endl;
#define printyes(cond)	  cout<<((cond)?"YES":"NO")<<endl;
#define printarr(arr)	   fors(num,arr){cout<<num<<" ";};cout<<endl;
#define printmap(hashmap)   for(auto[x,y]:hashmap)cout<<x<<" : "<<y<<endl;
#define endline			 cout<<endl;
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
 
// experimenting super short macro
#define endline			 cout<<endl;
#define uma(var,val)		var=max(var,(val));
#define umi(var,val)		var=min(var,(val));
#define ina(arr,am)		 int arr[am];fors(num,arr)cin>>num;
#define inv(vec,am)		 vector<int> vec(am);fors(num,vec)cin>>num;
#define in(var)			 int var;cin>>var;
#define in2(a,b)			int a,b;cin>>a>>b;
#define ins(var)			string var;cin>>var;
#define out(var)			cout<<(var)<<endl;
#define outs(var)		   cout<<(var)<<" ";
#define out2(var1,var2)	 cout<<(var1)<<" "<<(var2)<<endl;
#define outp(paired)		cout<<(paired.first)<<" "<<(paired.second)<<endl;
#define outa(arr)		   fors(num,arr){cout<<num<<" ";};cout<<endl;
#define sora(arr)		   sort(arr,arr+arrsize(arr));
#define sorv(vec)		   sort(all(vec));
#define reva(arr)		   reverse(arr,arr+arrsize(arr));
#define revv(vec)		   reverse(all(vec));
#define ra(i,s,e)		   for(int i=s;i<e;i++)
#define ra2(i,s,e)		  for(int i=s;i>=e;i--)
#define fos(var,arr)		for(auto &var:arr)
#define que				 cin>>QUERY;while(QUERY--)
#define quer				 cin>>QUERY;while(QUERY--)
#define i32				 int32_t
 
// Constant
const int MOD = 1e9+7;
const long long INF = 1e18;
const int maxn = 2e5+5;
 
struct segtree {
    int n;
    vi seg, pref, suff, sum;
    segtree(vi &arr){
        n = arr.size();
        n = log2(n-1) + 1;
        n = 1 << n;
        seg = vi(2 * n);
        pref = vi(2 * n);
        suff = vi(2 * n);
        sum = vi(2 * n);
        build(arr);
    }
 
    void combine(int idx) {
        sum[idx] = sum[2*idx] + sum[2*idx + 1];
        seg[idx] = max({seg[2*idx], seg[2*idx + 1], 
                        suff[2*idx] + pref[2*idx + 1]});
        pref[idx] = max(pref[2*idx], sum[2*idx] + pref[2*idx + 1]);
        suff[idx] = max(suff[2*idx + 1], suff[2*idx] + sum[2*idx + 1]);
    }
 
    void set(int idx, int val) {
        sum[idx] = val;
        seg[idx] = max(0LL, val);
        pref[idx] = max(0LL, val);
        suff[idx] = max(0LL, val);
    }
 
    void build(vi &arr) {
        range(i,0,arr.size()) {
            set(i + n, arr[i]);
        }
        range2(i,n-1,1) {
            combine(i);
        }
    }
 
    void update(int idx, int val) {
        idx += n;
        set(idx, val);
        idx /= 2;
        while(idx >= 1) {
            combine(idx);
            idx /= 2;
        }
    }
};
 
i32 main() {
    fastIO
    
    input2(n,q)
    inputvec(a, n)
    segtree st(a);
    range(i,0,q) {
        input2(k,x)
        st.update(k-1,x);
        print(st.seg[1])
    }
 
    return 0;
}
 
 
