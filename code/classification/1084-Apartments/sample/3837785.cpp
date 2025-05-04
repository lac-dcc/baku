#include<bits/stdc++.h>
using namespace std ; 
 
int n, m, k ; 
vector<int> a, b ; 
 
int main(){
 
	cin >> n >> m >> k ; 
 
	for(int i = 1 ; i <= n ; i++){
		int x ; cin >> x ; 
		a.push_back(x) ;
	} 
 
	for(int i = 1 ; i <= m ; i++){
		int x ; cin >> x ; 
		b.push_back(x) ; 
	}
 
	sort(a.begin(), a.end()) ; sort(b.begin(), b.end()) ; 
 
	int qtd = 0 ; 
 
	for(int i = 0, j = 0 ; i < n ; i++){
		while(j < m && b[j] < a[i] - k) j++ ; 
		if(j < m && b[j] <= a[i] + k) qtd++, j++ ; 
	}
 
	cout << qtd << "\n" ; 
 
}