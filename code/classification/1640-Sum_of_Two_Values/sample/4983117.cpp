#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[200005],b[200005];
int x,y,z;
int ans1,ans2;
bool flag=1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		x=lower_bound(a+1,a+1+n,m-a[i])-a;
		if(a[i]+a[x]==m){
			flag=0;
			y=a[i],z=a[x];
			break;
		}
	}
	if(flag)cout<<"IMPOSSIBLE"<<endl;
	else{
		for(int i=1;i<=n;i++){
			if(b[i]==y)ans1=i; 
		}
		for(int i=1;i<=n;i++){
			if(b[i]==z && ans1!=i)ans2=i; 
		}
		if(ans2==0)cout<<"IMPOSSIBLE"<<endl;
		else
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
