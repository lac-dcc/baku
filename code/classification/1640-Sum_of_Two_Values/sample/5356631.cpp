// Mehribon va rahmdil Olloh nomi bilan o`zing qo`lla, ey xudoyim
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull __int128
#define F first
#define S second
#define vi vector<int>
#define vvi vector<vector<int>>
#define yes cout<<"YES";return
#define no cout<<"NO";return
#define next(x) next_permutation(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x);
#define pf(x) push_front(x);
#define deb(x) cout << #x << " = " << x << '\n'
#define yaxlit(x) cout<<fixed<<setprecision(x);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
std::ostream& operator << (std::ostream& os, const __int128 i) noexcept{
    std::ostream::sentry s(os);
    if(s){
        unsigned __int128 tmp = i < 0 ? -i : i;
        char buffer[128];
        char *d = std::end(buffer);
        do{
            --d;
            *d = "0123456789"[tmp%10];
            tmp /= 10;
        }while(tmp != 0);
        if(i < 0){
            --d;
            *d = '-';
        }
        int len = int(std::end(buffer) - d);
        if(os.rdbuf()->sputn(d, len) != len){
            os.setstate(std::ios_base::badbit);
        }
    }
    return os;
}
ll mod=1e9+7;
map<ll,ll>fact;
int X[] = {-1,0,1,-1,1,-1,1,1};
int Y[] = {-1,-1,-1,0,0,1,1,1};
ll MPlus (ll a, ll b, ll m=mod){ll sum=0;a%=m;while(b){if(b&1)sum=(sum+a)%m;a=(a+a)%m;b/=2;}return sum;}
ll fac (ll n){if(fact.find(n)!=fact.end())return fact[n];if(!n) return fact[0]=1;return fact[n] = n * fac(n-1) % mod;}
ll bin (ll a,ll b, ll m=mod){ll s=1; while(b) {if(b&1)s=s*a%m;b >>= 1;a=a*a%m;} return s;}
ll Mod (ll a, ll b, ll m=mod){return (a*bin(b,m-2))%m;}
void edge (int x, int y, vector<vector<int>> &v){v[x].push_back(y);v[y].push_back(x);}
bool prime (ll n){if(n==1)return 0;ll x;for(int i=0;i<100;i++){x=rand()+10;if(x%n==0)x++;if(bin(x,n-1,n)!=1)return 0;}return 1;}
ll r_yig(ll n){return(n<10 ? n : (n%10)+r_yig(n/10));}
ll rkv_yig(ll n){return(n<10 ? n*n : (n%10)*(n%10)+rkv_yig(n/10));}
bool comp(string a,string b){return a.size()>b.size()? 1 : a.size()<b.size() ? 0: a>=b? 1: 0;}
string cl_zero(string s){int i=0;while(i+1<s.size() && s[i]=='0')i++;return s.substr(i);}
double area(int x1, int y1, int x2, int y2, int x3, int y3) { return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));} // * 1/2 and abs()
//ll N=2000005,pp=2;
//ll fil[N]={1};
//void fill(){for(int i=1;i<N;i++)t[i] = t[i-1]*pp%mod;}
//indexed_set s;
const int N = 2e5 + 5;
int a[N];
vector<pair<int, int>> v;
map<int, int> mp;
 
void solve(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++) {
	 	int x; 
	 	cin >> x;
	 	
        if (mp.find(m-x)!=mp.end()){
            cout << mp[m - x] << " " << i; 
			return;
        }
        mp[x]=i;
	}
	
	cout << "IMPOSSIBLE";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    fill();
	int t=1;
//    cin>>t;
	while(t--){
	   solve();
	   cout<<'\n';
    }
}
