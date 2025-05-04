#include<bits/stdc++.h>
#define int long long
#define nl  "\n"
using namespace std;
void initCode()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("soutput.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
const int mod=1000000007;
//----------------------------------------------------------------------------
int fexp(int a, int b){
    int ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= mod;
        ans %= mod;
    }
    return ans;
}
 
int nCr(int N, int K){
   int fact[100000];
   fact[0] = 1;
    for(int i = 1; i < 100000; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    return fact[N] * fexp(fact[K] * fact[N-K] % mod, mod-2) % mod;
}
int modadd(int a,int b,int m){ a = a % m;b = b % m; return(((a + b) % m) + m) % m;}
int modmul(int a,int b,int m){ a = a % m;b = b % m; return(((a * b) % m) + m) % m;}
int modsub(int a,int b,int m){ a = a % m;b = b % m; return(((a - b) % m) + m) % m;}
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int expo(int a,int n,int md){ int res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n = n>>1;}} return res;}
bool revsort(int a, int b){return a > b;}
// void swap(auto &x, auto &y){auto temp = x; x = y; y = temp;}
void google(int T){cout<<"Case #"<<T<<": ";}
void gt(int T){cerr<<"Case #"<<T<<": "<<endl;}
vector<bool> sieve(int n){vector<bool> prime(n+1,1); prime[0] = prime[1] = 0; for(int i=2;i*i<=n;i++){if(prime[i]){for(int j=i*i;j<=n;j+=i) prime[j]=0;}} return prime;}
//--------------------------------------------------------------------------------
///CHECK TYPO BEFORE SUBMITTING
// QUEUE, HEAP,STACK,TREE,DP,GREEDY,MULTISET,SET,POLICY BASED
//GRAPH,MAP,TIME COMPLEXITY ANALYSIS
// Jai Shree Ram
bool compare(pair<int,pair<int,int>> a , pair<int,pair<int,int>>b)
{
    if(a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
}
int binSearch(int low ,int high , int val , vector<pair<int,pair<int,int>>>&v)
{
      int res =  INT_MAX;
      while(low<=high)
      {
        int mid = (high-low)/2 + low;
        if(v[mid].second.first > val)
        {
             res=mid;
             high=mid-1;
        }
        else
        {
            low=mid+1;
        }
      }
      return res;
}
int dp[200001];
int findAns(int index, int n, vector<pair<int,pair<int,int>>>&v)
{
     if(index>=n) return 0;
     // take or not take
     if(dp[index]!=-1) return dp[index];
     int end =v[index].first;
     int newIndex = binSearch(index+1,n-1,end,v);
     int take = v[index].second.second + findAns(newIndex, n, v);
     int notTake = findAns(index+1,n,v);
     return dp[index]=max(take,notTake);
}
void solve()
{
   memset(dp,-1,sizeof(dp));
   int n;
   cin>>n;
   int start,end,value;
   vector<pair<int,pair<int,int>>>v;
   for(int i=0;i<n;i++)
   {
       cin>>start>>end>>value;
       // cout<<start<<" "<<end<<" "<<value<<endl;
       v.push_back({end,{start,value}});
   }
   sort(v.begin(),v.end(), compare);
   // for(auto it: v)
   // {
   //   cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
   // }
   cout<<findAns(0,n,v) ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initCode();
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}   
