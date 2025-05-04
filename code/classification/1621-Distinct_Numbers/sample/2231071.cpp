#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
 
int main(){
ll n;
cin>>n;
set<int> s;
for(int i=1; i<=n; i++){
    ll x;cin>>x;
    s.insert(x);
}
cout<<s.size()<<endl;
return 0;
}
