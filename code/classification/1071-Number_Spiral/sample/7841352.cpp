#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
 
 
int soulution(int x, int y){
	int z = max(x, y) - 1;
	int z2 = z*z;
 
	if(z%2==0){
		if(x==y)return z2+x;
		else if(x==z+1)return z2 + y;
		else return z2 + x + (2*abs(x-y));
	}
	else{
		if(x==y)return z2+x;
		else if(x == z+1) return z2 + y + (2*(x-y));
		else return z2 + x;
	}
}
 
 
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>> x >> y;
		int res = soulution(x,y);
		cout << res << endl;
	}
	
	return 0;
}
