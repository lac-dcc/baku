#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
ll max(ll a, ll b){
    if(a>b)return a;
    else return b;
}
int Prime(int n)
{
for (int i = 2; i*i <= n; i++)
 if (n % i == 0)
return 0;
return 1;
}
int main(){
fast
ll n,mi;
cin>>n>>mi;
map<ll,ll> m;
for(ll i=0;i<n;i++){
    ll b;
    cin>>b;
    m[b]++;
}
// for(auto it=m.begin();it!=m.end();it++){
// cout<<(*it).first<<" "<<(*it).second<<endl;
// }
 
while(mi--){
ll a;
cin>>a;
// cout<<a<<endl;
if(m.size()==0||a<m.begin()->first){
cout<<-1<<endl;
}
else{
    auto k=m.upper_bound(a);
    k--;
    cout<<(*k).first<<endl;
    m[(*k).first]--;
    
    if(m[(*k).first]==0)m.erase((*k).first);
}
// for(auto it=m.begin();it!=m.end();it++){
// cout<<(*it).first<<" "<<(*it).second<<endl;
// }
}
 
}
