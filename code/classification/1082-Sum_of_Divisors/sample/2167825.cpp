#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define NLIN "\n"
#define pb push_back
#define fst first
#define snd second
typedef long long int Num;
typedef vector<int> vi;
#define CONTAINS(set, elem) ((set).find(elem) != (set).end())
void printArray(vi v)
{
	for(int elem : v)
	{
		cerr << elem << " ";
	}
	cerr << "\n";
}
 
Num sumofsums(Num n){
	Num MOD = 1'000'000'007;
	Num split = sqrt(n);
	Num res = 0;
	FOR(i,1,split){
		res += i*(n/i);
		res %= MOD;
	}
	Num val = n/(split+1);
	assert(val != n/split);
	FOR(k,1,val){
		Num a = n/(k+1);
		Num b = n/k;
		Num diff = b-a;
		Num sum = a+b+1;
		if(diff % 2 == 0)diff /= 2;
		else sum /= 2;
		diff %= MOD;
		sum %= MOD;
		res += ((diff*sum)%MOD)*k;//(k*(b-a)*(a+b+1));
		res %= MOD;
	}
	return res;
}
Num sumofsums_slow(Num n){
	Num MOD = 1'000'000'007;
	Num res = 0;
	FOR(i,1,n){
		res += i*(n/i);
		res %= MOD;
	}
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Num n; cin >> n;
	cout << sumofsums(n) << "\n";
 
	return 0;
}
