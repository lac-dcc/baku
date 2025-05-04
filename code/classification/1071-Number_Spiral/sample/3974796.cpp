#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int t, x, y, ans;
	cin>>t;
	for(int i=1; i<=t; ++i){
		cin>>x>>y;
		if(y>x)
			if(y%2==1)
				ans=y*y-(x-1);
			else
				ans=(y-1)*(y-1)+1+(x-1);
		else
			if(x%2==0)
				ans=x*x-(y-1);
			else
				ans=(x-1)*(x-1)+1+(y-1);
		cout<<ans<<endl;
	}
	return 0;
}
