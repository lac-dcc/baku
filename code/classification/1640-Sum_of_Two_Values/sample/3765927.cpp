#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define lld unsigned long long int // a long has the range of -2,147,483,648 to 2,147,483,647 . An unsigned long has the range of 0 to 4,294,967,295
#define pb push_back
#define m_p make_pair
#define fo(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define N 100005
//Extended's Algorithm ax+by = gcd(a,b)
vector<int> extendedGCD(int a,int b){
if(b==0){
// return the values of x and y
return {1,0,a};
}
vector<int> result = extendedGCD(b,a%b);
//Bottom Up 
int smallx = result[0];
int smally  = result[1];
int gcd = result[2];
int x = smally;
int y = smallx - (a/b)*smally;
return {x,y,gcd};
}
// never submit a fucking guess
//let's start
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n ; cin>>n;
ll k ; cin>>k;
vector<ll> v;
map<ll,ll> mp;
fo(i,n){
    ll x ; cin>>x;
    v.pb(x);
    mp[x]=i+1;
}
 
//sort(v.begin(),v.end());
pair<ll,ll> p;
bool flag = false;
for(int i=0; i<n;i++){
     if(mp[k-v[i]] && mp[k-v[i]]!=i+1){
          p={i+1,mp[k-v[i]]};
          flag = true;
          break;
     }
}
if(flag){
    cout<<p.first<<" "<<p.second;
}
else{
    cout<<"IMPOSSIBLE";
}
}
