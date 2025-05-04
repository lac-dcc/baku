#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define sum(a) accumulate(a.begin(), a.end(),0)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> big;
	rep(i,n)big.pb({a[i],i});
	sort(big.begin(),big.end());
	if(n<=4){
		if(n<4 || sum(a)!=m)cout<<"IMPOSSIBLE";
		else cout<<"1 2 3 4";
		return 0;
	}
	rep(i,n){
		for(int j=i+1;j<n;j++){
			int l=j+1,h=n-1;
			while(l<h){
				int p=big[i][0],q=big[j][0];
				int r=big[l][0],s=big[h][0];
				if(p+q+r+s==m){
					cout<<big[i][1]+1<<' '<<big[j][1]+1<<' '<<big[l][1]+1<<' '<<big[h][1]+1;
					return 0; 
				}
				else if(p+q+r+s<m)l++;
				else h--;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
