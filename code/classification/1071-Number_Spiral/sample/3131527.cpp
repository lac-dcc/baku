#include<iostream>
using namespace std;
typedef unsigned long long int ulli;
 
int main(){
	ulli n;
	cin>>n;
	while(n>0){
		cin.tie(0);
		cout.tie(0);
		ios_base::sync_with_stdio(0);
		n=n-1;
		ulli y,x,ans=0,z;
		cin>>y>>x;
		z=max(y,x);
		ans=z*(z-1)+1;
		if(x==y){
			cout<<ans<<endl;
		}else if(z%2==1){
			if(y>x){
				while(z!=x){
					z=z-1;
					ans=ans-1;
				}
				cout<<ans<<endl;
			}else{
				while(z!=y){
					z=z-1;
					ans=ans+1;
				}
				cout<<ans<<endl;
			}
		}else if(z%2==0){
			if(y>x){
				while(z!=x){
					z=z-1;
					ans=ans+1;
				}
				cout<<ans<<endl;
			}else{
				while(z!=y){
					z=z-1;
					ans=ans-1;
				}
				cout<<ans<<endl;
			}
		}
	}
} 