#include <bits/stdc++.h>
#define ll long long 
using namespace std ;
 
ll solve(){
	ll a , b ; cin>>a>>b;
	if(b>a){
     	if(b%2==1){
     		return b*b-a+1;
     	}
     	else{
     		return ((b-1)*(b-1)) +a ;
     	}
	}
	else{
		if(a%2==1){
			return ((a-1)*(a-1)) +b ;     
		}
     	else{
     		return ((a)*(a)) -b +1;
     	}
	}
}
int main(){
    int t; cin>> t;
    ll a[t];
   	for(int i=0 ; i<t ; i++){
   		a[i]=solve();
   	}
 
   	for(int i=0 ; i<t ; i++){
   		cout<<a[i]<<"\n";
   	}
   
    return 0 ;
}
