#include<bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dbg2(x, y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<'\n';
 
using namespace std;
const ll MOD = 1e9 + 7;
 
// modular inverse of 2 with 1e9+7 is (1e9+7+1)/2
ll c2(ll n) {
	return (n % MOD * ((n + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD) % MOD;
}
// n(n+1)/2 is the sum of first n natural numbers
 
int main()
{
	FIO
	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll r = n / (n / i);
		// dbg2(i, r);
		// dbg2(c2(r), c2(i-1))  --> this would give us the sum of numbers we need to multiply with their freq (n/s)
		ll partial = ((n / i) % MOD * (c2(r) - c2(i - 1) + MOD) % MOD) % MOD;
		ans = (ans % MOD + partial % MOD) % MOD;
		// dbg2(partial, ans);
		i = r; // we could have also put i = r+1 but then we would have to remove it from thr for loop incrementing condition
	}
	cout << ans % MOD;
	return 0;
}
 
/*
Basically we are doing is almost like this :
 SUM(from i = 1 to n)[floor(n/i)*i] as every number from 1 to n would repeat
 itself n/i times collectively in all divisors of numbers from 1 to n
 [eg. if n = 10 ... 1 would occur 10 times, 2 would occur 5 times, 3 would occur 3 times,
 					{4,5} would occur 2 times, then {6,7,8,9,10} all will occur 1 time]
 
the above would take liner time which would not suffice.
So we have grouped the elements acc to their frequency.
 
Eg. 1 : if N = 100
	(Just see this to understand my notations in the next example)
Freq = 	100 [1 will repeat 100 times] -> 50 [2 will repeat 50 times] -> 33 [3 will repeat 33 times] -> 25 [4 will repeat 25 times] -> 14 -> 7
 
Eg. 2 : if  N = 25
 
Freq = 25[1] -> 12[2] -> 8[3] -> 6[4] -> 5[5] -> 4[6] -> 3[7,8] -> 2[9,10,11,12] -> 1[13,14,15,..24,25]
Bounds : (1,1)	 (2,2)	 (3,3)	 (4,4)	 (5,5) 	 (6,6)	 (7,8) 		 (9,12) 			(13,25)
	[1,25/(25/1)], [1+25/(25/1),25/(25/(1+25/(25/1)))]...[7,25/(25/7)], [9,25/(25/9)], [13,25/(25/13)]
 
// //
 
FOR N = 25
 
1
1,2
1,3
1,2,4
1,5
1,2,3,6
1,7
1,2,4,8
1,3,9
1,2,5,10
1,11
1,2,3,4,6,12
1,13
1,2,7,14
1,3,5,15
1,2,4,8,16
1,17
1,2,3,6,9,18
1,19
1,2,4,5,10,20
1,3,7,21
1,2,11,22
1,23
1,2,3,4,6,8,12,24
1,5,25
 
Dry - run of the prg.
 
i: 1 | r: 1
c2(r + 1): 1 | c2(i): 0
partial: 25 | ans: 25
 
i: 2 | r: 2
c2(r + 1): 3 | c2(i): 1
partial: 24 | ans: 49
 
i: 3 | r: 3
c2(r + 1): 6 | c2(i): 3
partial: 24 | ans: 73
 
i: 4 | r: 4
c2(r + 1): 10 | c2(i): 6
partial: 24 | ans: 97
 
i: 5 | r: 5
c2(r + 1): 15 | c2(i): 10
partial: 25 | ans: 122
 
i: 6 | r: 6
c2(r + 1): 21 | c2(i): 15
partial: 24 | ans: 146
 
i: 7 | r: 8
c2(r + 1): 36 | c2(i): 21
partial: 45 | ans: 191
 
i: 9 | r: 12
c2(r + 1): 78 | c2(i): 36
partial: 84 | ans: 275
 
i: 13 | r: 25
c2(r + 1): 325 | c2(i): 78
partial: 247 | ans: 522
 
*/
