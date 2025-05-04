#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[n];
	int maxi=0;
	for(int i=0; i<n; i++){
		cin>>x[i];
	
	
	}
	int ans=1;
	sort(x,x+n);
	for(int i=0; i<n-1; i++){
		if(x[i]!=x[i+1]) ans++;
		}
	cout<<ans<<endl;
}
 