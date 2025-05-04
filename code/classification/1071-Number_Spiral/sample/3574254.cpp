#include<iostream>
using namespace std;
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	long long y;
	long long x;
	long long group;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>y>>x;
		group = max(y,x);
		if(group % 2 == 0){
			if(y == group){
				//x�V�j value�V�p 
				//the nth group has 2n+1 values
				cout<<(group-1)*(group-1)+(2*group) - x<<"\n";
			}else{
				//y�j value �j
				cout<<(group-1)*(group-1) + y<<"\n";
			}
		}else{
			if(y == group){
				//x�V�j value�V�j
				cout<<(group-1)*(group-1) + x<<"\n";
			}else{
				//y�j value �p
				cout<<(group-1)*(group-1)+(2*group) - y<<"\n"; 
			}
		}
	}
	
	
	return 0;
}
