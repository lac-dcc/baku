#include <bits/stdc++.h>
#include <string>
#define ll long long
#define do double
#define all(x) x.begin(),x.end()
#define pi 3.14159265358979323
#define fn for(int i=0; i<n; i++)
#define sp << fixed << setprecision(10)
#define BIG  1000000007
#define el '\n'
#define itn int
#define F first
#define S second
#define korra   ios_base::sync_with_stdio(false);
using namespace std;
int main() {
    korra
    // ll n,k; cin>>n>>k;
    // vector<pair<ll,ll>>v(n);
    // fn {cin>>v[i].F; v[i].S=i+1;}
        int n; cin>>n;
      //  vector<ll>v(n);
      //  fn cin>>v[i];
      ll sum=0,r=LONG_MIN;
       for(int i=0; i<n; i++)
       {
         ll x; cin>>x;
         sum+=x;
         r=max(r,sum);
         sum=max(sum,0LL);
       }
       cout<<r;
    return 0;
}
