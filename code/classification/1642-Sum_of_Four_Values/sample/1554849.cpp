// Problem: Sum of Four Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1642
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define float long double
#define pr pair<int,int>
const int mod=1e9+7;
const int N=2e5+5;
const int inf=1e14;
void solve(){
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	multiset<int> st;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			st.insert(a[i]+a[j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			auto it=st.find(a[i]+a[j]);
			st.erase(it);
			if(st.find(x-a[i]-a[j])!=st.end()){
				// find k,l >j st a[k]+a[l]+a[i]+a[j]==x
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if(a[i]+a[j]+a[k]+a[l]==x){
							cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1;
							return;	
						}
						
					}
				}
				
			}
		}
	}
	cout<<"IMPOSSIBLE";
}
int32_t main(){
	IOS
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}