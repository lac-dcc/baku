#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using ll = long long;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int main() {
	ll n; int k;
	cin>>n >> k;
 
	vl primes(k);
	for(int i=0; i<k; i++)
		cin>>primes[i];
	sort(primes.begin(), primes.end());
	//for(int i=0; i<k; i++)
	//	cout<<primes[i]<<' ';
	//cout<<endl;
	ll count=0;
	for( int i=1; i<(1<<k); i++)
	{
		ll val=1;
		bool fail=false;
		int cnt=0;
		//cout<<i<<endl;
		for(int j=0; j<k; j++){
			//cout<<(i&(1<<j))<<' ';
			if((i&(1<<j))>0){
				cnt++;
				if(val>1e18/primes[j])
					fail=true;
				val*=primes[j];
				if(val<1)
					fail=true;
				if(val>n)
					fail=true;
			}
		}
 
		if(fail)
			continue;
		
		if(cnt%2==1)
			count+= n/val;
		else
			count-=n/val;
		//highest=max(count, highest);
	}
	//cout<<highest<<endl;
	cout<<count;
}