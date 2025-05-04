#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main(){
	int n;
	cin>>n;
	vector <int> mas(n);
	for(int i=0;i<n;i++){
		cin>>mas[i];
	}
	sort(mas.begin(),mas.end());
	int ans=1;;
	for(int i=1;i<n;i++){
		if(mas[i-1]!=mas[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
 