#include<bits/stdc++.h>
using namespace std;
#define dd double
#define ll long long int 
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define pr pair<ll,ll>
#define pri pair<pr,ll>
#define pir pair<ll,pr>
#define ppr pair<pr,pr>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll INF=9e15;
ll mod=998244353;
vector<ll> temp1;
vector<ll> temp2;
void solve(vector<ll> &v1,ll a,ll b,ll su,ll ok){
    // cout<<b<<" "<<ok<<endl;
    if(a>=b){
        if(ok==0) temp1.pb(su);
        else temp2.pb(su);
        return;
    }
    solve(v1,a+1,b,su+v1[a],ok);
    solve(v1,a+1,b,su,ok);
}
int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("opt.txt","w",stdout);
   #endif
   fastio;
   ll te=1;
   // cin>>te;
   while(te--){
    ll n,x,i,j,t;
    cin>>n>>x;
    vector<ll> v1(n);
    for(i=0;i<n;i++) cin>>v1[i];
    ll midi=n/2;
    if((n%2)==0) midi--;
    solve(v1,0,midi+1,0,0);
    solve(v1,midi+1,n,0,1);
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    // for(i=0;i<temp1.size();i++) cout<<temp1[i]<<" ";
    // cout<<endl;
    // for(i=0;i<temp2.size();i++) cout<<temp2[i]<<" ";
    // cout<<endl;
    ll ans=0;
    for(i=0;i<temp1.size();i++){
        ll in1=upper_bound(temp2.begin(),temp2.end(),x-temp1[i])-temp2.begin();
        ll in2=lower_bound(temp2.begin(),temp2.end(),x-temp1[i])-temp2.begin();
        // cout<<in1<<" "<<in2<<" "<<i<<endl;
        ans+=in1-in2;
    }
    cout<<ans<<endl;
   }
}
