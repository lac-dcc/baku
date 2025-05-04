#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
	int t;
	cin>>t;
	while(t--){
		int y,x,yy,xx;
		cin>>y>>x;
		int a=max(y,x);
		if(a&1){
			yy=1;
			xx=a;
		}
		else{
			yy=a;
			xx=1;
		}
		int ans=a*a-abs(y-yy)-abs(x-xx);
		cout<<ans<<"\n";
	}
}
