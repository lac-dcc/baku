#include <bits/stdc++.h>
using namespace std;
#define kaushik ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fori for(int i=0;i<n;i++)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fl(i,a,b) for(ll i=a;i<=b;i++)
#define pb push_back
#define M 1000000007
#define debug(x) cout<<#x<<" -> "<<x<<endl
 
int gcd(int A, int B){
    if (B == 0)
        return A;
    else
        return gcd(B, A % B);
}
 
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
ll pow1(ll a,ll b,ll MOD){ll ans=1;while(b!=0){if(b&1)ans=(ans*a)%MOD;a=(a*a)%MOD;b=b/2;}return ans;}
 
 
int testCase = 1;
int isGoogle = 0;
int test = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
void solve(){
    ll n;
    cin >> n;
 
    ll a[n];
    set<ll> s;
 
    fl(i,0,n-1){
        cin >> a[i];
        s.insert(a[i]);
    }
 
    cout << s.size();
 
 
 
    
    
}
 
 
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main(){
    kaushik;
 
    if(test){
        int t;
        cin >> t;
        while(t--)
        {   
            if(isGoogle){
                cout << "Case #" << testCase << ": ";
                testCase++;
            } 
            solve();    
        }
    }else{
        solve();
    }
 
    return 0;
}