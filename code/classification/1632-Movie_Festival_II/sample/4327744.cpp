#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#define ll long long
#define f(i,a,b,c) for(int i=a;i<b;i+=c)
#define fr(i,a,b,c) for(int i=a;i>=b;i-=c)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(z) z.begin(),z.end()
#define rall(z) z.rbegin(),z.rend()
ll md=1e9+7;
ll gcd(ll a,ll b){
    if(!b){return a;}
    return gcd(b,a%b);
}
ll l_c_m(vector<ll>a){
    ll ans=1;
    for(int i=0;i<a.size();i++){
        //cout<<a[i]<<" ";
        ans=(a[i]*ans)/gcd(a[i],ans);
    }
    return ans;
}
void solve(int k){
    
 
}
bool cp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}
int main(){
    int n,k;cin>>n>>k;
    vector<vector<int>>t;
    f(i,0,n,1){
        int a,b;cin>>a>>b;t.pb({a,b});
    }
    sort(all(t),cp);
    multiset<int>s;int res=0;
    f(i,0,n,1){
        if(s.size()==0){
            s.insert(t[i][1]);res++;
        }
        else{
            auto it=s.lower_bound(t[i][0]+1);
            if(it!=s.begin()){
                s.erase(--it);s.insert(t[i][1]);res++;
            }
            else if(s.size()<k){s.insert(t[i][1]);res++;}
        }
    }
    cout<<res;
}