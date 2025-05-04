#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef long long int lld;
typedef tree<lld,null_type,less<lld>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,v) for(auto a:v)
 
void solve(){
	lld x,y;
	cin>>x>>y;
	lld M=max(x,y);
	lld M2=1+(M*(M-1))+(x-y)*(1-2*(M%2));
	cout<<M2<<endl;
}
 
int main(){
	
	int tt;
	tt=1;
	cin>>tt;
	while(tt--){
		solve();
	}
}
