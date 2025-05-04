#include <iostream>
 
#define ll long long
 
int main(){
 
	int test;
	std::cin>>test;
	
	while(test--){
		ll r, c;
		std::cin>>r>>c;
		
		if (r > c)
			std::cout << (r % 2 ? (r-1)*(r-1)+c : r*r-c+1) << '\n';
		else 
			std::cout << (c % 2 ? c*c-r+1 : (c-1)*(c-1)+r) << '\n';
	}
}
 
 