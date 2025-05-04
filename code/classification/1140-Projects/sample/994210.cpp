#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<lld,lld > pii;
#define pi acos(-1)
#define fr(i,m,n) for(i=m;i<n;i++)
#define fu(i,m,n) for(i=m;i>=n;i--)
#define vec vector<lld>
#define pb push_back
#define pp pop_back()
#define ft first
#define sd second
#define all(v) v.begin(),v.end()
#define mom(ara) memset(ara,0,sizeof(ara));
#define m1m(ara) memset(ara,-1,sizeof(ara));
#define endl "\n"
#define eps 1.19209e-07
lld dp[300010];
struct tri
{
	lld l,r,m;
};
vector<tri> pro;
bool cmp(const tri &a,const tri &b)
{
	return a.r<b.r;
}
vec mydup;
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    lld i,j,k,a,b,c,x,y,z,n,t;
   	cin>>n;
   	fr(i,0,n)
   	{
   		cin>>a>>b>>c;
   		pro.pb({a,b,c});
   	}
   	sort(all(pro),cmp);
   	dp[0]=0;
   	fr(i,0,n)
   	{
   		mydup.pb(pro[i].r);
   		z=lower_bound(all(mydup),pro[i].l)-mydup.begin();
   		dp[i+1]=max(dp[i],dp[z]+pro[i].m);
   	}
   	cout<<dp[n]<<endl;
}
