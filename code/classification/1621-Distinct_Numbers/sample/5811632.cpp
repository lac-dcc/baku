#include<bits/stdc++.h>
using namespace std;
int comparator(const void *a, const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	return *x - *y;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	qsort(a,n,sizeof(int),comparator);
	int cnt = 1;
	for(int i=1; i<n; i++){
		if(a[i] != a[i-1]) cnt++;
	}
	cout<<cnt;
}