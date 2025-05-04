#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;
 
const int N = 2e5 + 1;
 
void solve(){
	int n,k;
	cin >> n >> k;
	vector <pair <int,int>> t(n);
	for(int i = 0;i < n;++i){
		int a,b;
		cin >> a >> b;
		t[i].first = b;
		t[i].second = a;
	}
	sort(t.begin(),t.end());
	multiset <int> s;
	int count = 0;
	for(int i = 0;i < n;++i){
		auto itr = s.upper_bound(t[i].second);
		if(s.size() > 0 and itr != s.begin()){
			--itr;
			s.erase(itr);
			++k;
		}
		if(k > 0){
			--k;
			++count;
			s.insert(t[i].first);
		}
	}
	cout << count << newl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}