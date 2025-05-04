using namespace std;
#include <bits/stdc++.h>
 
#define For(i,n) for(int i=0;i<n;i++)
#define fi first
#define t_int int
#define ll long long
#define sec second
#define el "\n"
 
inline int gcd(int a, int b)        {if (b == 0) return a;    return gcd(b, a % b);}
inline int lcm(int a, int b)        {return (a / gcd(a, b) * b);}
inline bool isprime(int n)          {int i; for (i = 2; i <= sqrt(n); i++) {if (n % i == 0)return false;} return true;}
inline bool issqrt(int x)           {int s = sqrt(x); if (x == s * s) return true; return false;}
inline int ceil(int num, int den)   {return ((num + den - 1) / den);}
inline int fact(int n)              {int ans=1; for(int i = 1; i <= n; ++i) {ans *= i;} return ans;}
inline int stoint(string s)         {return stoi(s);}
inline string inttos(int a)         {return to_string(a);}
 
inline void yes() { cout<< "YES"<<el; }
inline void no() { cout<<"NO"<<el; }
 
inline void debugMode(){
ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("D:/Cp/cf_883_div3/input.txt", "r", stdin);
freopen("D:/Cp/cf_883_div3/output.txt", "w", stdout);
#endif 
}
 
 
#define For(i,n) for(int i=0;i<n;i++)
#define fi first
#define t_int int
#define ll long long
#define sec second
#define mp                  make_pair
#define vi                  vector<int>
#define si                  set<int>
#define pb                  push_back
#define mpii                multiset<pair<int, int>>
#define prec(n)             fixed<<setprecision(n)
#define rep(i,a,b)          for(int i = a; i < b; i++)
#define loop(x, n)          for(int x = 0; x < n; ++ x)
#define loop1(x, n)         for(int x = 1; x <= n; ++ x)
#define pii                 pair<int, int>
#define vpi                 vector<pair<int,int> >
 
 
#define N 1000005
#define MOD 1e9+7
 
template <typename T,typename U>
T sum(T a, U b){
      cout<<"sum of the two numbers in different data types "<<el;
      return a+b;
}
 
typedef pair<int,int> mypair;
struct sort_pair
{
      bool operator () (const mypair& left, const mypair& right)
            {
            	 
                  return left.fi<right.fi;
            }
};
 
//vector<vector<ll>> dp(N,vector<ll>(N,0));
#define ull unsigned long long
#define vti vector<tuple<int,int,int>> 
vector<int> div_count_nlog(N,0);
#define int long long 
 
void solve(){
    
    ull number;
    cin>>number;
    int n;
    cin>>n;
    int b[n];
    For(j,n) cin>>b[j];                  // starts with i=0 if you have to count also the
    int ans=0;                           // conidition of zero elemeents selected
    for(int i=1;i<(1<<n);i++){           // in the group 
      int value =1;
      int temp=0;
      for(int j=0;j<20;j++){
            if(i&(1<<j)){
                  if(value>number/b[j]){
                        value = number+1;         // number goes out of the range if 
                        break;                     // if we don't put this conditon 
                  }                                // then we new number 
                  temp++;
                value*=b[j]; 
 
            }
      }
      if(temp%2==0)
            ans-=number/value;
      else 
      ans+=number/value;
    }
    cout<<ans<<el;
           
           
           
 
}
 
 
 
 
 
 
signed main(){
            
            
            debugMode();
            int t;
            t=1;
            while (t--) {
                solve();   
            }
 
            return 0;}