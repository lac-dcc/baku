#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl "\n"
#define F first
#define S second
#define sortit(x) sort(x.begin(),x.end())
using namespace std;
 
bool ISPRIME(long long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	} 
	return true; 
}
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	vector<array<int,2>> times;
	while(t--){
		int x,y;
		cin>>x>>y;
		times.PB({x,y});
	}
	sortit(times);
	int maxcus = 0;
	priority_queue<int,vector<int>,std::greater<int>> q;
	FOR(times.size()){
		int x = times[i][0],y = times[i][1];
		if(q.empty()){
			q.push(y);
		}
		else{
			while(!q.empty() && x>=q.top()){
				q.pop();
				// cout<<"Popoing "<<x<<" "<<q.top()<<nl;
			}
			q.push(y);
		}
		maxcus = max(maxcus,(int)q.size());
	}
	cout<<maxcus<<nl;
 
}
