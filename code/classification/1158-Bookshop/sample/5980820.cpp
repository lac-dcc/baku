#include<bits/stdc++.h>
using namespace std;
int n, x;
int H[1001], S[1001];
int F[1001][100001];
int qhd(){
	memset(F, 0, sizeof(F));
	int Max = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x; j++){
			if(H[i] > j){
				F[i][j] = F[i - 1][j];
			}else F[i][j] = max(F[i-1][j],F[i - 1][j - H[i]] + S[i]);
			
		}
		
	}	
	return F[n][x];
}
int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> H[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> S[i];
	}
	cout<<qhd();
}