#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b){
    return (a.second < b.second);
}
int main(){
	// freopen("input1.txt", "r", stdin);
	// freopen("output1.txt", "w", stdout);
	long long n, k;
	cin >> n >> k;
	vector<pair<long long, long long> > v(n);
	for(long long i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), sortbysec);
	multiset<long long> ends;
	ends.insert(-v[0].second);
	long long badmovies = 0;
	for(long long i = 1; i < n; i++){
		auto it = ends.lower_bound(-v[i].first);
		if(it == ends.end()){
			if(ends.size() == k){
				badmovies++;
			}
			else{
				ends.insert(-v[i].second);
			}
		}
		else{
			ends.erase(it);
			ends.insert(-v[i].second);
		}
	}
	cout << n - badmovies << endl;
}
