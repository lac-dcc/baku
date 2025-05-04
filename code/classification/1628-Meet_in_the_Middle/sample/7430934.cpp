#include<bits/stdc++.h>
using namespace std;
 
constexpr int maxN = 1e6;
 
int L[maxN+10];
int R[maxN+10];
 
bool comp(long long a, long long b){
	return a > b;
}
 
long long solve(int n, long long k){
	int s = n/2;
	vector<long long> left, right;
 
	// liczymy sumy podzbiorow dla L
	for(int mask=1; mask<(1<<s); mask++){
		long long sum = 0;
		for(int i=0; i<s; i++){
			if(mask & (1<<i)) sum += L[i];
		}
		left.push_back(sum);
	}
 
	// dla P
	s = n - s;
	for(int mask=1; mask<(1<<s); mask++){
		long long sum = 0;
		for(int i=0; i<s; i++){
			if(mask & (1<<i)) sum += R[i];
		}
		right.push_back(sum);
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end(),comp);
 
	int i = 0,j = 0;
	long long answer = 0;
 
	while(left.size()){
		if(i > right.size() - 1 || j > left.size() - 1) break;
		if(right[i] > k){
			i++;
			continue;
		}
		while(j < left.size() && right[i] + left[j] < k) j++;
 
		if(i > right.size() - 1 || j > left.size() - 1) break;
		if(right[i] + left[j] == k){
			long long r = 0, l = 0, rajt = right[i], lef = left[j];
			while(i < right.size() && right[i] + lef == k) r++, i++;
			while(j < left.size() && rajt + left[j] == k) l++, j++;
				//cout << i << ' ' << j << ' ' << r << ' ' << l << '\n';			
			answer += r*l;
		}
		else i++;
	}
	/*for(auto r: right) cout << r << ' ';
		cout << endl;
	for(auto l: left) cout << l  << ' ';
		cout << endl;*/
	for(auto r: right) if(r == k) answer++;
	for(auto l: left) if(l == k) answer++;
	return answer;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; long long k; cin >> n >> k;
    for(int i=0; i<n/2; i++) cin >> L[i];
    for(int i=0; i<n-n/2; i++) cin >> R[i];
 
    cout << solve(n,k) << '\n';
    return 0;
}
