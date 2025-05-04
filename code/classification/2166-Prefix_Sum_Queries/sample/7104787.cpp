#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define IShowSpeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll h[200005],tpre[4*200005],tsum[4*200005],z=0,ans=0,sum=0;
 
void build(int v, int tl, int tr)
{
	if(tl==tr)
	{
		tpre[v]=max({z,h[tl]});
		tsum[v]=h[tl];
		return;
	}
	int mid=(tl+tr) >> 1;
	build(v+v,tl,mid);
	build(v+v+1,mid+1,tr);
	tpre[v]=max({z,tpre[v+v],tsum[v+v]+tpre[v+v+1]});
	tsum[v]=tsum[v+v]+tsum[v+v+1];
}
 
void upd(int v, int tl, int tr, int pos, ll x)
{
	if(tl==tr)
	{
		tpre[v]=max({z,x});
		tsum[v]=x;
		h[tl] = x;
		return;
	}
	int mid=(tl+tr) >> 1;
	if(pos<=mid) upd(v+v,tl,mid,pos,x);
	else upd(v+v+1,mid+1,tr,pos,x);
	tpre[v]=max({z,tpre[v+v],tsum[v+v]+tpre[v+v+1]});
	tsum[v]=tsum[v+v]+tsum[v+v+1];
}
 
void get(int v, int tl, int tr, int l, int r)
{
	if(tl>r || tr<l) return;
	if(tl>=l && tr<=r)
	{
		ans=max({ans,sum+tpre[v]});
		//cout<<tl<<" "<<tr<<" "<<tpre[v]<<"\n";
		sum+=tsum[v];
		return;
	}
	int mid=(tl+tr) >> 1;
	get(v+v,tl,mid,l,r);
	get(v+v+1,mid+1,tr,l,r);
}
 
int main()
{
	// freopen("test_input.txt","r",stdin);
	// IShowSpeed
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>h[i];
	build(1,1,n);
	while(q--)
	{
		int check;
		cin>>check;
		if(check==1)
		{
			int pos,x;
			cin>>pos>>x;
			upd(1,1,n,pos,x);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			get(1,1,n,l,r);
			//for(int i = l;i <= r;i ++) cout << h[i] << " ";
			//cout << endl;
			cout<<ans<<"\n";
			ans=0,sum=0;
		}
		
	}
}
/*
100 16
58 36 81 -7 46 49 87 -58 98 -15 -2 62 -8 -22 0 78 -48 94 68 -7 -73 8 62 2 -84 29 78 71 -11 3 3 88 -21 69 -96 -10 52 -70 17 -37 -57 -20 73 76 54 17 54 -33 -49 40 -83 63 34 58 47 98 -89 -82 4 67 58 -87 72 -96 62 -50 -50 -74 -28 -50 15 91 45 -20 -97 56 -15 10 46 -42 40 -89 98 42 85 65 -22 -46 56 -54 35 34 35 -53 98 69 -88 91 26 80
2 4 70
2 70 94
2 95 99
2 34 42
1 8 -57
2 11 35
2 70 96
2 7 77
1 55 -11
1 56 -27
1 8 62
2 45 69
1 27 -10
2 92 95
1 18 23
2 79 92
*/
