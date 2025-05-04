#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[1001],b[1001],f[1001][maxn]={};
int n,x;
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=n;i++){
		for(int s=0;s<=x;s++){
			f[i][s]=f[i-1][s];
			if(s>=a[i]){
				f[i][s]=max(f[i][s],f[i-1][s-a[i]]+b[i]);
			}
		}
	}cout<<f[n][x];
}
