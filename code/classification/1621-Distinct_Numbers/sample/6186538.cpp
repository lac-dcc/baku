#include "iostream"
#include "set"
using namespace std;
#define int long long
 
int32_t main(){
	int n;cin>>n;
	set<int>s;
	while(n--){
		int x; cin>>x;
		s.insert(x);
	}
	cout<<s.size()<<"\n";
} 
