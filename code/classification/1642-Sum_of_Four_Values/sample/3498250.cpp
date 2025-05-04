#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<ll,ll>
#define ft first
#define sc second
 
using namespace std;
//using namespace __gnu_pbds;
 
const int N=1005;
long long n,x,a[N];
 
//template<class T> using Tree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
unordered_map<ll,vector<ii>> mp;
int main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    mp.reserve(N*N);
    cin>>n>>x;
 
    for(int i=1;i<=n;i++) cin>>a[i];
 
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
    {
        int T=a[i]+a[j];
        if(T>=x) continue;
        if(mp.find(x-T)!=mp.end())
        {
            for(auto P:mp[x-T])
            {
                if(P.ft!=i&&P.sc!=i&&P.ft!=j&&P.sc!=j)
                {
                    cout<<i<<" "<<j<<" "<<P.ft<<" "<<P.sc;
                    return 0;
                }
            }
        }
        else mp[T].push_back(ii{i,j});
    }
 
    cout<<"IMPOSSIBLE";
    return 0;
}
