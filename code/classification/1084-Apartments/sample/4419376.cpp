#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define ff                first
#define ss                second
#define ii                pair<int,int>
#define mp                make_pair
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define fast_io          ios::sync_with_stdio(0); cin.tie(0);
#define nl                 '\n'
#define vt                vector
#define vi                vector<int>
#define ar                array
 
const int mxN=2e5;
int a[mxN], b[mxN];
 
int main(){
	fast_io
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=0; i<n; ++i) cin>>a[i];
	for(int i=0; i<m; ++i) cin>>b[i];
	
	sort(a, a+n); 
	sort(b, b+m);
	int ans=0;
	
	for(int i=0, j=0; i<n; ++i){
		while(j<m && b[j]<a[i]-k)
			++j;
		if(j<m && b[j]<=a[i]+k )
			++ans, ++j;
	}
	cout<<ans;
}
