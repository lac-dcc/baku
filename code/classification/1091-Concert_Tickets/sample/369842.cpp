#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long long ll;
 
bool sortValue(pi a, pi b){
	if(a.F == b.F)
		return a.S > b.S;	
	return a.F > b.F;
}
 
bool sortPosition(pi a, pi b){
	return a.S < b.S;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vi h(n);
    for(int i = 0; i < n; i++){
		cin >> h[i];		
	}
    vpi t(m);
    for(int  i = 0; i < m; i++){
		cin >> t[i].F;
		t[i].S = i;
	}
	
	sort(h.rbegin(), h.rend());
	sort(all(t), sortValue);
	
	int pos = 0;
	vi ans(m, -1);
	for(int i = 0; i < m; i++){
		while(pos < n && h[pos] > t[i].F)
			pos++;
			
		if(pos >= n)
			ans[t[i].S] = -1;
		else{
			ans[t[i].S] = h[pos];
			pos++;
		}
	}
	
	for(int i = 0; i < m; i++){
		cout << ans[i] << endl;
	}	
    
}
 
void solve2(){
	int n, m;
	cin >> n >> m;
	multiset<int, greater<int>> s;
	set<int> op;
	int x;
	while(n--){
		cin >> x;
		s.insert(x);
		op.insert(x);
	}
	
	
	while(m--){
		cin >> x;
		auto it  = s.lower_bound(x);
		if(it == s.end()){
			printf("-1\n");
		}else{
			printf("%d\n", *it);
			s.erase(it);
		}
	}
}
 
int main(){
    //int t; cin >> t;
    //while(t--) solve();
    //
    solve2();
    return 0;
}
