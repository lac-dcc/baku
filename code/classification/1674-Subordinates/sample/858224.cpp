#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
const ll INF=1e15;
//#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
 
long long binpows(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  //impar
            res = res * a;
        a = a * a;
        b >>= 1;  // /2
    }
    return res;
}
const int mod=1e9+7;
int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
//CHECAR SE PRECISA DE LONG LONG
int qt[223456];
vector<int> adj[223456];
int resolve(int pos){
	int &x=qt[pos];
	for(auto i: adj[pos]){
		x+=resolve(i)+1;
	}
	return x;
}
void solve(){
	int n;
	cin>>n;
	for(int i=2; i<=n; i++){
		int a;
		cin>>a;
		adj[a].pb(i);
	}
	resolve(1);
	for(int i=1; i<=n; i++){
		cout<<qt[i]<<" ";
	}
	cout<<endl;
}
//revise as variaveis e a ordem nas funções
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
