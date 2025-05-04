#include<bits/stdc++.h>
using namespace std;
const int mod = (int) 1e9 + 7;
void solve(){
	int n,k; cin>>n>>k;
	int a[n+10],b[n+10];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	//int d[n+100][k+100]={0};
	vector<vector<int>> d(n + 100, vector<int>(k + 100, 0));  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j<a[i]) d[i][j]=d[i-1][j];
			else d[i][j]=max(d[i-1][j],d[i-1][j-a[i]]+b[i]);
		}
	}
	cout<<d[n][k]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	solve();
    return 0;
}
 
