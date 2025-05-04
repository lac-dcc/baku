#include<bits/stdc++.h>
#include<utility>
using namespace std;
#define T int t;cin>>t; while(t--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define br cout<<"\n"
/* --------------------------------- */
 
 
 
/* --------------------------------- */
int main()
{
	/* IO settings */
	fio;
	// #ifndef ONLINE_JUDGE
 //    freopen("C:\\Users\\gkk\\Documents\\input.txt", "r", stdin);
 //    freopen("C:\\Users\\gkk\\Documents\\output.txt", "w", stdout);
	// #endif
	/* --------------------------------- */
	int n,x; cin>>n>>x;
	vector<pair<int,int> > v;
	for(int tmp,i=0;i<n;i++){
		cin>>tmp; v.push_back(make_pair(tmp,i+1));
	}
	sort(v.begin(),v.end());
	int lft=0,rht=n-1;
	bool found=false;
	int a=0,b=0;
	while(lft<rht)
	{
		int val = v[lft].first + v[rht].first;
		// cout<<val<<" ";
		if(val==x){
			a= min(v[lft].second,v[rht].second);
			b= max(v[lft].second,v[rht].second);
			found = true; break;
		}
		if(val<x){
			lft++;
		}
		else{
			rht--;
		}
	}
	if(found && (a&&b)){
		cout<<a<<" "<<b;
	}
	else{
		cout<<"IMPOSSIBLE";
	}
	/* --------------------------------- */
	return 0;
}
