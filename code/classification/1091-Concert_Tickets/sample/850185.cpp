#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define pb push_back
#define ll long long
 
int main(){
	
	int n,m; cin>>n>>m;
	set<pair<int,int> > st;
	for(int i=0;i<n;i++){
		int a; cin>>a;
		st.insert({a, i});
	}
	
	for(int i=0;i<m;i++){
		int t; cin>>t;
		auto it = st.lower_bound({t+1, 0});
		if(it == st.begin())
			cout<<-1<<endl;
		else {
			--it;
			cout<<(*it).first<<endl;
			st.erase(it);
		}
	}
	
	return 0;
}
 
 
 
