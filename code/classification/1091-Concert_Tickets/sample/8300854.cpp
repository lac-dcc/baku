#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
// #define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<long>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
const int maxn=1e6;
const int mod=1e9+7;
lli fac[maxn+1];
lli inv[maxn+1];
bool compare(const pair<lli,lli>&i,const pair<lli,lli>&j){
    return i.second<j.second;
}
lli Mod(lli a, lli b){
    return (a%b+b)%b;
}
void printvector(vi arr){
    for(int k:arr){
        cout <<  k << " ";
    }
    cout << "\n";
}
long long powm(long long a, long long  b,int m) {
	long long res=1;
 
	while(b) {
		if(b&1)
			res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res;
}
 
int helper(int n){
  int ans=0;
  while(n!=0){
    int m=n%10;
    ans+=m;
    n=n/10;
  }
  return ans;
}
int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a%b);
}
void lps(string s ,vector<int>&arr){
    int pre=0;
    int suf=1;
    while(suf<s.length()){
        if(s[pre]==s[suf]){
            arr[suf]=pre+1;
            pre++;
            suf++;
        }
        else{
            if(pre==0){
                arr[suf]=0;
                suf++;
            }else{
                pre=arr[pre-1];          
            }
        }
    }
}
 
void factorial(){
    fac[0]=1;
    for(int i=1; i<=maxn; i++){
        fac[i]=fac[i-1]*i %mod;
    }
}
void inverses(){
     inv[maxn]=powm(fac[maxn],mod-2,mod);
    for(int i=maxn;i>=1; i--){
        inv[i-1]=inv[i]*i % mod;
    }
}
lli choose (int n,int r){
    return fac[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(){
   int n,m;
   cin >> n >> m;
   multiset<int>arr;
   REP(i,n){
    int a;
    cin >> a; 
    arr.insert(a);
   }
   REP(i,m){
    int b;
    cin >> b;
    auto it=arr.upper_bound(b);
    // cout << *it << endl;
    if(it==arr.begin()){
        // cout <<"hey"<<*it<<endl;
        cout << -1 << "\n";
    }else{
        cout << *--it << "\n";
        arr.erase(it);
    }
 
   }
 
}
int main() {
    solve();
   return 0;
}
