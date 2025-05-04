#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mt make_tuple
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define mod(a,b) ((a%b +b)%b)
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a) 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define INF 1001001001
#define PI 3.1415926535897932384626
 
using namespace std;
 using namespace __gnu_pbds;
 template <typename T>
 using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
//----------------------------------------------------------------------------------------------------------------------
 
#define p 101 
#define MOD 1000000007 
  
void swap(int &a, int & b){
    int temp = a;
    a = b;
    b = temp;
 
}
 
 
    //     ll l = -1,  r  = exp;
    // ll ans = exp + 50;
    // while (l + 1 < r) {
    //     ll c = (l + r) / 2;
    //     if ( str + c > in + (exp - c) ){
    //         ans = min(ans,c);
    //         r = c;
    //     }else{
    //         l = c;
    //     }
    // }
 
 
 
 
int main(){
	int n;
	cin >> n; int x; cin >> x;
	vector< int > coins (n);
	scanVec(coins,n);
	vector< int > sum (x+1,0);
	sum[0] = 1;
	for(int i = 0;i <= x;i++){
		for(int j = 0; j < n;j++){
			if(i+coins[j] <= x){
				sum[i+coins[j]] += sum[i];
				sum[i+coins[j]]%=MOD;
			}
		}
	}
	cout << sum[x]%MOD << endl;
}
 
 
