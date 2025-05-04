#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll; 
const int mxN=1e5;
long long arr[mxN];
 
void solve(int t){
	ll m=0;
	ll x,y;
	for(int i=0;i<t;i++){
		cin>>y>>x;
		m=(max(y,x)*max(y,x))-max(y-1,x-1);
			if(y>x){
				if(y%2==0)
					arr[i]=m+y-x;
				else
					arr[i]=m+x-y;
			}
			else if(y==x)
				arr[i]=m;
			else{
				if(x%2==0)
					arr[i]=m+y-x;
				else
					arr[i]=m+x-y;
			}
	}
	for(int i=0;i<t;i++){
		cout<<arr[i]<<endl;
	}
}
 
int main(void){
	int t;
	cin>>t;
	solve(t);
}
