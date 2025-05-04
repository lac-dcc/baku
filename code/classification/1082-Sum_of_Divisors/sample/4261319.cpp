//exeCreate 2022-7-17 0:0:23	
 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef pair<int,int> Pii;
const int maxn=2e5+10,maxm=maxn;
const ll mod=1e9+7,inf=0x3f3f3f3f;
 
 
ll inv2 = (mod+1)/2;
/*数论分块*/
ll sqrtDecomposition(ll n){
	//模板题代码，计算Σσ(i),σ(x)为x的因数之和，例如σ(12) = 1+2+3+4+6+12=28
	ll quo=n,st = 1,ed;
	ll res=0;
	while(st<=n){
		ed = n/(n/st);
		res  = (res+((ed+st)%mod)*((ed-st+1)%mod)%mod*inv2%mod*(quo/st)%mod)%mod;
		st = ed+1;
	}
	return res;
}
int main()
{
	ll n;	cin>>n;
 
	ll ans=sqrtDecomposition(n);
	cout<<ans<<endl;
	
	fflush(stdin);	getchar();
	return 0;
}
//maxn改好了么?