#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int n, m; cin>>n>>m;
	multiset<int> ms;
	vector<int> vec(m);
	for(int i=0; i<n; i++){
	    int x;cin>>x;
	    ms.insert(x);
	}
	for(auto &it : vec) cin>>it;
	
	for(int i=0; i<m; i++){
        int limit = vec[i];
	    auto it = ms.upper_bound(limit);
	    if(it == ms.begin()){
	        cout<<"-1\n";
	    }
	    else{
	        it--;
	        cout<<*it<<"\n";
	        ms.erase(it);
	    }
	}
	return 0;
}
