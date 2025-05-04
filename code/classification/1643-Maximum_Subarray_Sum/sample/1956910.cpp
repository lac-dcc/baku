#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP( i, a, b) for(ll i=a; i<=b; i++)
#define fori(i, b) for(ll i=0;i<b;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define vi vector<ll>
#define endl '\n'
#define cs(ans) cout<<ans<<' '
#define cn(ans) cout<<ans<<'\n'
#define Yes cout<<"yes"<<'\n'
#define No cout<<"No"<<'\n'
#define CASE(t) ll t;cin>>t;while(t--)
#define in(n) ll n;cin>>n;
#define ins(s) string s;getline(cin, s);
#define fin(a, n) vi a;while(n--){ll ele;cin>>ele;a.pb(ele);}
 
void FAST() {	//FAST Input Output
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
ll hcf(ll x, ll y) {	//returns hcf of two long long ints
	if (x == 0) return y;
	return hcf(y % x, x);
}
 
map<long long, long long> factorize(long long n) {	//returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}
	map<long long, long long> ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	if (n > 1) {
		ans[n]++;
		n = 1;
	}
	return ans;
}
 
//Template Ends
 
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}
 
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
 
 
int main(){
	FAST();
	//CASE(t)
	{
	   in(n);
	   vi v;
       for(ll i=0;i<n;i++){
		   in(a);
		   v.pb(a);
	   }
	   
	   //sort(v.begin(), v.end());
       ll ma = v[0],sum=v[0];
	   for(ll i=1;i<n;i++){
		   sum = max(v[i],sum+v[i]);
		   ma = max(ma,sum);
	   }
 
	   cout<<ma<<"\n";
	}
    return 0;
}
