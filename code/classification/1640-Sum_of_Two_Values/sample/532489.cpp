#include<bits/stdc++.h>
using namespace std;
 
int n, x;
pair<int,int>a[200005];
 
int main(){
	cin >> n >> x;
	for (int i=0;i<n;i++) cin >> a[i].first;
	for (int i=0;i<n;i++) a[i].second=i+1;
	sort(a,a+n);
	for (int i=0;i<n;i++){
		int l=i+1, r=n-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (a[i].first+a[mid].first==x){
				cout << a[i].second << " " << a[mid].second << "\n";
				return 0;
			}
			if (a[i].first+a[mid].first>x) r=mid-1;
			else l=mid+1;
		}
	}
	cout << "IMPOSSIBLE\n";
}
