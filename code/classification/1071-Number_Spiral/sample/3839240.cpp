#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
	ll r,c;
	cin>>r>>c;
	
	if(r == c){
		cout << r*r - r + 1 << endl;
		return;
	}else if(r > c){
		if((r&1) == 1){
			cout << (r-1)*(r-1) + c << endl;
		}else{
			cout << (r*r) - c + 1 << endl;
		}
	}else{
		if((c&1) == 1){
			cout << c*c - r + 1 << endl;
		}else{
			cout << (c-1)*(c-1) + r << endl;
		}
	}
	
}
 
int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}