#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define debug(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************
int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}
 
int addMOD(int a,int b){
    return ((a+b)%MOD+MOD)%MOD;
}
int multMOD(int a,int b){
    return ((a*b)%MOD+MOD)%MOD;
}
int invMOD(int a){
    return power(a,MOD-2);
}
int divMOD(int a,int b){
    return multMOD(a,invMOD(b));
}
int subMOD(int a,int b){
    return addMOD(a,MOD-b);
}
void solve()
{
    int n;
    cin>>n;
    int answer=0;
    for(int i=1;i*i<=n;i++){
        answer=addMOD(answer,multMOD(n/i,i));
    }
    int l=(int)sqrt(n);
    for(int i=sqrt(n);i>=1;i--)
    {
        int r=n/i;
        int sum=0;
        // Sum from 1 to r
        sum+=((((r%MOD)*((r+1)%MOD))%MOD)*invMOD(2))%MOD;
        sum%=MOD;
        // Sum from 1 to l
        sum-=((((l%MOD)*((l+1)%MOD))%MOD)*invMOD(2))%MOD;
        sum=(sum+MOD)%MOD;
        sum=(sum*i)%MOD;
        l=r;
        answer=(answer+sum)%MOD;
    }
    cout<<answer<<endl;
 
    
}
signed main() 
{ 
    FAST;
    solve();
    return 0; 
} 
