#include <iostream>
#include <set>
 
using namespace std;
 
void solve(){
	int n;
	cin>>n;
	set<long long int> f;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		f.insert(j);
	}
	cout<<f.size()<<endl;
		
}
 
int main(){
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
