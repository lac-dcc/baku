// Problem: Apartments
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1084
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// *****CODE BY NIMIT*****
// 
// Powered by CP Editor (https://cpeditor.org)
 
// Problem: B1. Wonderful Coloring - 1
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1551/B1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// *****CODE BY NIMIT*****
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
#define int long long 
#define fio ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define fo(i,a,b) for(int i=a;i<b;i++)
#define fi first
#define se second
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define ld long double
#define inf 1000000000000000
using namespace std;
 
int mod=1e9+7;
 
int bexp(int a,int b,int m){
    if(a==0) return 0;
    int res=1;
    a%=m;
    while(b>0){
    	if(b&1) res=(1ll*res*a)%m;
        b>>=1;
        a=(1ll*a*a)%m;
    }
    return res;
}
 
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
 
 
bool solve1(int n,int m,int k,vector<int> a){
	int flg=0;
	int cnt=0;
	fo(i,0,k){
		a[i]/=m;
		if(a[i]>1){
			cnt+=a[i];
		}
		if(a[i]>2){
			flg=1;
		}
	}
	if(cnt<n) return false;
	if(n%2&&flg==0) return false;
	return true;
}
 
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n),b(m);
	fo(i,0,n) cin>>a[i];
	fo(i,0,m) cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans=0,ind=0;
	fo(i,0,n){
		while(ind<m){
			if(b[ind]+k<a[i]){
				ind++;
			}else if(b[ind]-k>a[i]){
				break;
			}else{
				ind++;ans++;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
 
int32_t main(){
	fio;
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}