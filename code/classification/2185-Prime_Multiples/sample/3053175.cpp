#pragma GCC optimize("Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
#define push_back emplace_back
/**********/
const int MAXN = 200011,mod = 1e9+7,mp = mod - 1;
ll a[MAXN];
int main()
{
	ll n=read(),ans=0;
	int m=read();
	for(int i=0;i<m;++i)a[i]=read();
	for(int s=1;s<(1<<m);++s)
	{
		int sgn=-1;
		ll rest=n;
		for(int i=0;i<m;++i)
			if(s&(1<<i))sgn=-sgn,rest/=a[i];
		ans+=sgn*rest;
	}
	printf("%lld\n",ans);
	return 0;
}