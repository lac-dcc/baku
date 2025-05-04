//exeCreate 2023-1-2 10:20:59	
 
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
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef pair<int,int> Pii;
const int maxn=2.5e3+10;
const ll mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;
 
/*SPFA(最差也是BellmanFord)
上次手打:230102*/
int n;
vector<Pii> G[maxn];
ll dis[maxn];	int cnt[maxn],pre[maxn]; bool vis[maxn];
queue<int> q;
 
int spfa(int s){
	rep(i,1,n) dis[i]=inf;
	dis[s]=0,vis[s]=true,cnt[s]=0;
	q.push(s);
	while(!q.empty()){
		int x = q.front();	q.pop();
		vis[x]=false;
		for(auto& p:G[x]){
			int y=p.first;
			if(dis[y]>dis[x]+p.second){
				dis[y]=dis[x]+p.second;
				cnt[y]=cnt[x]+1,pre[y]=x;
				if(cnt[y]==n+1) return y;
				if(!vis[y]) q.push(y),vis[y]=true;
			}
		}
	}
	return 0;
}
 
int idx[maxn];
int ans[maxn];
 
int main()
{
	int m;	cin>>n>>m;
	rep(i,1,m){
		int x,y,c;	scanf("%d%d%d",&x,&y,&c);
		G[x].pb(mp(y,c));
	}
	rep(i,1,n) G[n+1].push_back(mp(i,0));
 
	int now = spfa(n+1);
	if(!now) puts("NO");
	else{
		puts("YES");
		int cnt=0;
		int x=now;
		do{
			ans[++cnt]=now;
			if(idx[now]) break;
			idx[now]=cnt;
			now = pre[now];
		}while(1);
		per(i,cnt,idx[now]) printf("%d ",ans[i]);
	}
 
	fflush(stdin);	getchar();
	return 0;
	//maxn改好了吗?
}
