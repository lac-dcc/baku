#include <bits/stdc++.h>
 
typedef unsigned long ul;
typedef long long ll;
typedef unsigned int UINT;
 
using namespace std;
 
void solve(){
int n, x, input;
cin >> n >> x;
map<int, int> mp;
for (int i = 0; i < n; ++i){
    cin >> input;
    if (mp.find(x-input)!=mp.end())
    {
        cout << mp[x-input]+1 << ' ' << i + 1 << '\n';
	return;
    }
    mp[input] = i;
}
cout << "IMPOSSIBLE\n";
return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
		while(t--) solve();
return 0;
}
