#include<bits/stdc++.h>
#include<set>
 
using namespace std;
multiset<int> s;
int n,m,k,a[200005],ans=0;
int main(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	s.insert(1000000001);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=a[i]-k;
		int it=*s.lower_bound(x);
		if(it<=a[i]+k && it!=1000000001){
			ans++;
			s.erase(s.find(it));
		}
	}
	cout << ans;
 
	return 0;
}
