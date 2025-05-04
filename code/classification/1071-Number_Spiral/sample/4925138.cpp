//#include <iostream>
//#include <cstdio>
//#include <ctime>
//#include <cmath>
//#include <queue>
//#include <cstring>
//#include <fstream>
//#include <vector>
//#include <set>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long t,x,y;
	cin >> t;
	long long ans;
	for(long long i = 0; i < t; i++) {
		cin >> y >> x;
		x-=1;
		y-=1;
		if(x==0 && y==0) {
			cout << 1 << "\n";
			continue;
		}
		if(x>y) {
			if(x%2==0) ans=(x+1)*(x+1)-y;
			if(x%2==1) ans=x*x+1+y;
		}
		else {
			if(y%2==0) ans=y*y+1+x;
			if(y%2==1) ans=(y+1)*(y+1)-x;
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}
