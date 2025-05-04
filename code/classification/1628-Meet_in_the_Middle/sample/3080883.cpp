#pragma GCC optimize("Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<random>
#include<chrono>
#include<cmath>
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef long long ll;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 55;
int a[MAXN],sa[1<<20],sb[1<<20];
int main()
{
	int n=read(),sp=n>>1,la=0,lb=0;
	int x=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int s=0;s<(1<<sp);++s)
	{
		int sum=0,fail=0;
		for(int i=0;i<sp;++i)
			if(s&(1<<i))
			{
				sum+=a[i];
				if(sum>x){fail=1;break;}
			}
		if(!fail)sa[++la]=sum;
	}
	for(int s=0;s<(1<<(n-sp));++s)
	{
		int sum=0,fail=0;
		for(int i=0;i<(n-sp);++i)
			if(s&(1<<i))
			{
				sum+=a[sp+i];
				if(sum>x){fail=1;break;}
			}
		if(!fail)sb[++lb]=sum;
	}
	std::sort(sa+1,sa+la+1),std::sort(sb+1,sb+lb+1);
	ll ans=0;
	int it1=lb,it2=lb;
	for(int i=1;i<=la;++i)
	{
		while(it1&&sa[i]+sb[it1]>=x)--it1;
		while(it2&&sa[i]+sb[it2]>x)--it2;
		ans+=it2-it1;
	}
	printf("%lld\n",ans);
	return 0;
}
