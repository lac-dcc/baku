#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;
 
int main(){
	fastio;
	vector<vector<pair<int,int> > > e;
	int n;
	int m;
	cin >> n >> m;
	e.resize(n);
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		e[a].push_back({b,c});
	}
	vector<long long> d(n,1ll<<55);
	d[0]=0;
	int h=0;
	vector<int> mm(n,-1);
	while(1){
		h++;
		vector<long long> p=d;
		int till=0;
		for(int i=0;i<n;i++){
			for(auto k:e[i]){
				if(d[i]+k.sc<d[k.fs]){
					d[k.fs]=d[i]+k.sc;
					mm[k.fs]=i;
					till=k.fs;
				}
			}
		}
		bool flag=0;
		for(int i=0;i<n;i++){
			if(p[i]!=d[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			break;
		}
		if(h>n){
			cout << "YES\n";
			for(int i=0;i<n;i++){
				till=mm[till];
			}
			vector<int> cyc;
			for(int k=till;;k=mm[k]){
				cyc.push_back(k);
				if(k==till && cyc.size()>1){
					break;
				}
			}
			reverse(cyc.begin(),cyc.end());
			for(auto w:cyc){
				cout << w+1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
