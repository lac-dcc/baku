#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main(){
 
	int t;
	cin >> t;
	ll y,x,id,my,mx;
	for(int i=1;i<=t;i++){
		cin >> y >> x;
		id = max(y,x);
		if(id%2!=0){
			my=1;
			mx=id;
		}
		else{
			my=id;
			mx=1;
		}
		cout << id*id - (abs(my-y)+abs(mx-x)) << endl;
	}
 
	return 0;
}
