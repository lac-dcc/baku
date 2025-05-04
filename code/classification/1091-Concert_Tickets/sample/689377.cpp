#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             INT_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(x)			x.begin(),x.end() 
#define FIO				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
int nCr(int n , int r ) {
	int p = 1, k = 1;
 
	if (n - r < r ) {
		r = n - r;
	}
	if (r != 0) {
		while (r != 0) {
			p *= n ;
			k *= r ;
			int m = __gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else {
		p = 1;
	}
	return p ;
}
 
int lcm(int x , int y){
	return (x * y) / __gcd(x, y);
}
 
int modPower(int x, int y , int p) {
	//Used to calculate (x^y)%p
	int res = 1;
	if (y == 0) {
		return 1;
	}
 
	x = x % p;
	if (x == 0) {
		return 0  ;
	}
 
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % p;
		}
 
		y >>= 1;
		x = (x * x) % p;
	}
	return res ;
 
}
 
void aryan_p() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return;
}
 
int lower(vi a , int val){
	for (int i = a.size()-1; i >=0 ; i--){
		if(a[i]<=val){
			return i;
		}
	}
	return a.size();
}
 
int32_t main() {
	//  aryan_p();
	FIO;
 
	int n, m, curr, ticket;
    cin >> n >> m;
    multiset<int, greater<int>> tickets;
 
    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }
 
    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}
