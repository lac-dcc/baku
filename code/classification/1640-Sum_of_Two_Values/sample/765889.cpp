#include<bits/stdc++.h>
#include<string>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define N 1000012
#define ll long long
#define ld long double
#define lli long long 
#define pb push_back
#define INF 10000000000
#define mod 1000000007
#define MOD 1000000007
#define mp make_pair
#define loop(n) for (lli i = 0; i < n; i++)
#define FOR(a,b) for (lli i = a; i < b; i+=1)
#define st(v) v.begin(),v.end()
#define F first
#define S second
#define mp make_pair
#define itr :: iterator it
#define w(t) cin>>t; while(t --)
#define inputarr(a,n) for(lli i=1;i<=n;i++)cin>>a[i];
#define input(a,n) for(lli i=0;i<n;i++){ lli x ; cin>>x; a.push_back(x);}
#define printarr(a,n) for(lli i=0;i<n;i++)cout<<a[i]; cout<<endl;
#define print(vec) for(auto xt : vec)cout<<xt; cout<<endl;
#define printset(st) for(auto xt : st) cout<<xt<<" ";    cout<<endl;
// const int N=(int)(1 * 1e5 + 10);
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// // typedef tree<int,null_type,less<int>,rb_tree_tag,
// // tree_order_statistics_node_update> indexed_set;
// typedef tree<int, null_type, less_equal<int>, 
//              rb_tree_tag, 
//              tree_order_statistics_node_update> 
//     ordered_set; 
 
 
// lli v1[N],  v3[N];
// std::vector<lli> v1[N];
// lli v2[N];
// lli ans[N], a[N];
// lli maxi=0;
 
// lli sqr(lli a){
//     return a*a;
// }
 
 
// int n, k, m,l,a[200004],i;
// string s;
// int gcd(int a, int b, int& x, int& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }
 
// int gcd(int a, int b, int &x, int &y) 
// {  
//     int xx = y = 0;
//     int yy = x = 1;
//     while (b) 
//     {
//         int q = a/b;
//         int t = b; b = a%b; a = t;
//         t = xx; xx = x-q*xx; x = t;
//         t = yy; yy = y-q*yy; y = t;
//     } 
//     return a;
// }
 
// bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
//     g = gcd(abs(a), abs(b), x0, y0);
//     if (c % g !=0) {
//         return false;
//     }
 
//     x0 *= c / g;
//     y0 *= c / g;
 
//     // cout<<x0<<" "<<y0<<endl;
 
//     double t1 = ceil((-1.0 * x0 * g)/b);
//     double t2 = floor((1.0 * y0 * g)/a);
      
//     if (t2 >= t1)
//         return true;
//     else
//            return false;
    
// }
// set<lli> s1;
// void seive(lli n,vector<lli> &primes){
//     bool isprime[n+1];
//     memset(isprime,true,n+1);
 
//     for(lli i =2;i*i<=n;i++){
//         if(isprime[i]==true){
 
//             for(lli j=i*i;j<=n ;j+=i)
//                 isprime[j]=false;
//         }
//     }
//     for(lli i =2;i<=n;i++){
//         if(isprime[i]){
//             primes.pb(i);
//         }
//     }
// }
 
// lli A,R,M,n,ans,k;
// lli a,b,x,y,m,c;
// string s;
 
// // bool is_prime(lli n){
// //   if(n<=1)return false;
// //   // if(n <= 1: return False
// //     if (n <= 3) return true;
// //     if(n%2==0 or n%3 == 0)return false;
// //     lli r = int(sqrt(n));
// //     lli f = 5;
// //     while(f*f < n){
// //         if(n%f == 0 || n%(f+2) == 0)return false;
// //         f+= 6;
// //     }
// //     return true;
 
// // }
 
// bool is_prime(lli n) 
// { 
//     // Corner cases 
//     if (n <= 1)  return false; 
//     if (n <= 3)  return true; 
  
//     // This is checked so that we can skip  
//     // middle five numbers in below loop 
//     if (n%2 == 0 || n%3 == 0) return false; 
  
//     for (lli i=5; i*i<=n; i=i+6) 
//         if (n%i == 0 || n%(i+2) == 0) 
//            return false; 
  
//     return true; 
// } 
 
 
 
 
// lli fun(lli n,vector<lli> &primes){
//  lli l=n;
//  lli c=0;
//  // set<long long> factorization;
//  // for(auto x: primes ){
//  //  cout<<x<<" ";
//  // }
//     for (long long d : primes) {
//         lli f=0;
//         if (d * d > n)
//             break;
//         while (n % d == 0) {
//          f=1;
//             // factorization.insert(d);
//             n /= d;
//         }
//         if(f==1)c++;
 
 
//     }
//     if (n > 1)c++;
//         // factorization.insert(n);
 
//     // cout<<l<<" "<<factorization.size()<<endl;
//     return c;
//  // return c;
// }
 
// lli fun(lli n){
//  return n*(n+1)/2;
// }
 
// lli fact(lli n){
//  lli res=1;
//  for(lli i =2;i<=n;i++){
//      res*=i;
//  }
//  return res;
// }
 
// lli gcd(lli a,lli b){
//  if(a==0){
//      return b;
//  }
//  return gcd(b%a,a);
// }
// lli fac(lli n,lli k){
//  lli maxi=1;
//  for(lli i =1;i*i<=n;i++){
    
//      if(n%i==0 &&i<=k){
//          maxi=max(maxi,i);
//      }
//      if(n%i==0 && n/i<=k){
//          maxi=max(maxi,n/i);
//      }
//  }
//  return maxi;
// }
 
 
 
 
// // int a[N];
// int S[N];
// int freq[N];
// vector<int> good[N];
// lli some1(){
//  S[1]=0;
//  for(lli i =2;i<N;i++){
//      if(!S[i]){
//          // lli j=i;
//          for(lli j=i;j<N;j+=i){
//              S[j]+=i;
//          }
//      }
//  }
 
//  for(lli i =1;i<N;i++){
//      // lli j=i;
//      for(lli j=i;j<N;j+=i){
//          if(S[i] && S[j]%S[i]==0){
//              good[i].pb(j);
//          }
//      }
//  }
// }
 
// lli totfac(lli n){
//  // set<lli> s1;
//  lli c=0;
//  for(lli i=1;i*i<=n;i++){
//      if(n%i==0){
//          if(n/i ==i){
//              c++;
//          }
//          else{
//              c+=2;
//          }
//      }
 
//  }
//  return c;
// }
 
// lli somefun(lli a, lli b, lli m){
//  lli res=1;
//  while(b){
        
//      if(b&1)
//          res=res*a%m;
        
//      a=a*a%m;
//      b/=2;
//  }
//  return res;
// }
 
// lli lpf[N];
// void init(){
//  lpf[1]=1;
//  for(lli i =2;i<N;i++){
//      lpf[i]=i;
//  }
//  for(lli i=2;i<N;i+=2)
//      lpf[i]=2;
 
//  for(lli i=3;i*i<N;i++){
//      if(lpf[i]==i){
//          for(lli j=i*i;j<N;j+=i){
//              if(lpf[j]==j)
//                  lpf[j]=i;
//          }
//      }
//  }
// }
 
// lli findGCD(std::vector<lli> &arr, lli n) 
// { 
//     lli result = arr[0]; 
//     for (int i = 1; i < n; i++) 
//     { 
//         result = gcd(arr[i], result); 
  
//         if(result == 1) 
//         { 
//            return 1; 
//         } 
//     } 
//     return result; 
// }
 
// std::vector<lli> factorial(N+1);
 
// std::vector<lli> factorial2(N+1);
// // std::vector<lli> dp(N+1);
// std::vector<lli> invFact(N+1);
 
// lli nCr(lli n, lli r)
// {
//  return (((factorial[n]*invFact[r])%MOD)*invFact[n-r])%MOD;
// }
 
// // lli val;
// // int pre[N];
// std::vector<lli> factval;
// lli printDivisors(lli n) 
// { 
//     // Note that this loop runs till square root 
//     for (lli i=1; i*i<=n; i++) 
//     { 
//         if (n%i == 0) 
//         { 
//             // If divisors are equal, print only one 
//             factval.pb(i);
//             if (n/i != i) 
//                 factval.pb(n/i); 
  
//             // else // Otherwise print both 
//             //     printf("%d %d ", i, n/i); 
//         } 
//     } 
//     return factval.size();
// } 
 
// lli primefactorization(lli n){
//  lli i=2,c=0;
//  while(i*i<=n){
//      if(n%i==0){
//          while(n%i==0){
//              n/=i;
//          }
//          c++;    
//      }
 
//      i++;
//  }
//  if(n>1)c++;
//  return c;
// }
 
// lli factorials(int n) 
// { 
//     // single line to find factorial 
//     // return (n==1 || n==0) ? 1: n * factorials(n - 1);
//  lli val=1;
//     for(lli i =1;i<=n;i++)
//      val=val*i%MOD;
//     return val;   
// } 
 
// lli some(lli n,lli k){
 
//  return factorials(n)/factorials(k)*factorials(n-k);
// }
// bool sum10(lli k){
//  lli sum=0;
//  while(k>0){
//      sum+=k%10;
//      k/=10;
//  }
//  return sum==10;
 
// }
// int n,x;
int bit[N];
// int fen[N];
void update(int i, int add) {
    while (i > 0 && i < N)
    {
        bit[i] += add;
        i += (i & (-i));
    }
}
 
int sum1(int i) {
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i = i - (i & (-i));
    }
    return s;
}
// int n;
// void add(int idx, int val) {
//  // cout<<idx<<endl;
//     for (++idx; idx < N; idx += idx & -idx)
//         bit[idx] += val;
// }
 
// void range_add(ll l, ll r, ll val) {
//  // cout<<l<<" "<<r<<endl;
//     add(l, val);
//     add(r + 1, -val);
// }
 
// ll point_query(int idx) {
//     int ret = 0;
//     for (++idx; idx > 0; idx -= idx & -idx)
//         ret += bit[idx];
//     return ret;
// }
// void Update(int x, int add) {
//     for (; x <= n; x += x & -x)
//         bit[x] += add;
// }
 
// int Query(int x) {
//     int answer = 0;
//     for (; x; x -= x & -x)
//         answer += bit[x];
//     return answer;
// }
 
 
std::map<lli, lli> has;
set<lli>s1;
 
// bool sortdec(const pair<pair<ll,ll>,ll> &a,
//               const pair<pair<ll,ll>,ll> &b){
 
//     if(a.F.F<b.F.F)return true;
//     else if(a.F.F==b.F.F)return a.F.S>b.F.S; 
//     else return false; 
// }
lli n;
lli a,b,k,m;
// std::vector<string> v1(2);
// std::vector<lli> edges[N];
bool visited[N];
// int dist[N];
// int indegree[N];
lli mini=0;
// void dfs(lli i,std::vector<lli> &v1){
//     // assert(!visited[a]==true);
//     mini=min(mini,v1[i]);
//     visited[i]=true;
//     for(auto b: edges[i]){
//         // dist[b]=max(dist[b],dist[a]+1);
//         // --indegree[b];
//         if(!visited[b]){
//             dfs(b,v1);
//         }
//     }
 
// }
// bool vis[500][500];
// char v1[500][500];
 
int32_t main() {
// your code goes here
// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// #endif
 
    // lli m,o,e,k,b,l,c,d,x,y,f,t,r,a;
    // lli x,y,z,k,b,j,c,d,m;
    
    // lli t,l,r,f,g,d,q,u;
    // lli q;
    // init();  //calculates prime factoriztion til 1e6
    
 
 
 
    fastIO
    // cin>>n>>d;
    
    // phi_1_to_n();
    // cout<<phi[5]<<endl;
    // w(t){
    // }
    // lli n,a,b,k;
    
    lli t,q,H,e,D,C,w,x,y;
    cin>>n>>k;
    std::vector<lli> v1;
    std::map<lli, lli> has;
    input(v1,n)
    for(ll i=0;i<n;i++){
        has[v1[i]]=i;
    }
    // for(auto x:has){
    //     cout<<x.F<<" ";
    // }
    lli f=0;
    for(lli i =0;i<n;i++){
        if(has[k-v1[i]] && has[k-v1[i]]!=i){
            // cout<<"Sad";
            cout<<i+1<<" "<<has[k-v1[i]]+1;
            f=1;
            break;
        }
        // cout<<has[k-v1[i]];
    }
    if(f==0)cout<<"IMPOSSIBLE";
    return 0;
}