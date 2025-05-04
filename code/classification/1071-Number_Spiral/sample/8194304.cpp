#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,a,s,b;
	cin>>n;
	for (i=1;i<=n;i++){
		cin >> a >> b;
		if( a > b){
			if(a%2==0){
				cout << a * a + 1 - b << endl;
			}
			else{
				cout << (a - 1) * (a - 1) + b << endl;
			}
		}
		else{
			if(b%2==0){
				cout << (b-1) * (b-1) + a << endl;
			}
			else{
				cout << b * b + 1 - a << endl;
			}
		}
	}
	return 0;
}
