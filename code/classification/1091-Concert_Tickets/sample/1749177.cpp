#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
const int maxn=5e5;
set<pii> ST;
 
int32_t main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ST.insert({x,i});
	}
	ST.insert({-1,-1});
	while(m--){
        int x;
        cin>>x;
        pii pw={x+1,-1};
        auto it=ST.upper_bound(pw);
        it--;
        pii ans=*it;
        if(ans.F==-1) cout<<-1<<'\n';
        else{
            cout<<ans.F<<'\n';
            ST.erase(it);
        }
    }
 
	return 0;
}
