#include <bits/stdc++.h>
using namespace std;
 
#define sdef string s; cin >> s;
#define vll vector<long long>
#define pll pair<long long, long long>
#define vvll vector<vll>
#define vpll vector<pair<long long,long long>>
#define vs vector<string>
#define mll map<long long, long long>
#define ff first
#define ss second
#define pb push_back
#define forl(i, a, b) for (long long i = a; i < b; i++)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(),v.end()
#define l(s) s.length()
ll floor_multiset(multiset<ll>& mySet, ll x) {
    auto it = mySet.lower_bound(x);
    if(*it==x)return x;
    else if (it != mySet.begin()) {
         --it;
        return *it;
    } else {
        return -1;
    }
}
int main() {
   ll n;cin>>n;
   forl(i,0,n){
   ll a,b;cin>>a>>b;
   if(a>=b){
      if(a%2==0){
         cout<<a*a-b+1<<endl;
      }
      else{
         cout<<((a-1)*(a-1))+b<<endl;
      }
   }
   else{
      if(b%2==0){
         cout<<((b-1)*(b-1))+a<<endl;
      }
      else{
         cout<<b*b-a+1<<endl;
      }
   }
   }
 
   return 0;
}
