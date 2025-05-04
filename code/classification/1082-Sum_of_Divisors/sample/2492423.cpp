#pragma GCC optimize("O2")
#include<ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define all(x) (x).begin(),(x).end()
#define ls(x) (x*2+1)
#define rs(x) (x*2+2)
#define lowbit(x) (x & -x)
void _debug() {cerr << '\n';}
template <typename A, typename... B>
void _debug(A a, B... b) {cerr << a << ' ', _debug(b...);}
#define debug(args...) cerr << '(' << (#args) << ") : ", _debug(args);
typedef long long ll;
const int oo = 2000000000; // 2e9
const int p = 1e9+7;
/*
 
	observation: Not only for each divisor it only appears floor(n/i) times, but also
	that the value of n/i, which we will denote that as q. The "q" here also has a limited value!
	To go straight for the answer, there are only sqrt(n) distince values for q.
 
	So the critical point is to calculate the summation with the same values of q = floor(n/i)
*/
int main(){ IOS
	ll n; cin>>n;
	ll ans = 0;
	for(ll i = 1; i <= n;){
		ll q = n/i, j = n/q+1;
		//j denotes the "start" of the other val "i"
		//compute [i,i+1,....j-1], i.e. testcase n = 12 => i = 1; [7,8,9,10,11,12] because they will appear q times.
		ll h = j-i, ud = (i+j-1);
		// h stands for 高，ud = up + down => 上底加下底
		// debug(h,ud);
		if(!(h&1)) h >>=1; // 再計算和的時後，處以 2 的部分，任一個值都可以，且必有一個為偶數
		else ud >>=1;
		h %= p, ud %= p;
		ans = (ans + q%p * h %p * ud % p)%p;
		i = j;
	}
	cout<<ans<<'\n';
}
