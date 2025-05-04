#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int i,j;
    long long int x,y;
    for(i=0;i<n;i++){
	cin>>x>>y;
	if(x>y){
	    if(x%2==0){
		cout<<(x)*(x)-y+1;
	    }
	    else{
		cout<<(x-1)*(x-1)+y;
	    }
	}
	else{
	    if(y%2==0){
		cout<<(y-1)*(y-1)+x;
	    }
	    else{
		cout<<(y)*(y)-x+1;
	    }
	}
	cout<<endl;
    }
    return 0;
}
