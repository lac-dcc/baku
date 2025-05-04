#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
int l[4]={0,0,1,-1};
int r[4]={1,-1,0,0};
vector<char> step={'R','L','D','U'};
int n,m;
// -----------------------------------counting room
// void dfs(vector<string>& ar,int i,int j,vector<vector<bool>>& vis){
// 	vis[i][j]=1;
// 	for(int k=0;k<4;k++){
// 		int x=i+l[k];
// 		int y=j+r[k];
// 		if(x>=0&&x<n&&y>=0&&y<m&&ar[x][y]=='.'&&vis[x][y]==0)
// 		dfs(ar,x,y,vis);
// 	}
// }
 
void dfs(int u,vector<int> gr[],vector<bool>& vis){
	vis[u]=1;
	for(int v:gr[u]){
		if(vis[v]==0)
		dfs(v,gr,vis);
	}
}
 
void go(int u,vector<bool>& vis,vector<pair<ll,ll>> gr[],bool &neg){
	if(u==n) neg=1;
	vis[u]=1;
	for(auto v:gr[u]){
		if(vis[v.first]==0) go(v.first,vis,gr,neg);
	}
}
 
vector<ll> djkstra(vector<pair<int,ll>> gr[],int src){
	vector<ll> d(n+1,1e18);
	d[src]=0;
    set <pair <ll,ll> > q;
    q.insert({0,src});
    while(!q.empty()){
        pair <ll,ll> f=*q.begin(); q.erase(q.begin());
        ll e=f.second;
        for(auto x : gr[e]){
            ll to=x.first; ll len=x.second;
            if(d[e]+len<d[to]){
                q.erase({d[to],to});
                d[to]=d[e]+len;
                q.insert({d[to],to});
            }
        }
    }
	return d;
}
 
 
bool cycleutil(int u,vector<int> gr[],vector<bool>& vis,vector<int> &team,int par=0){
	vis[u]=1;
	team.push_back(u);
	for(int v:gr[u]){
		if(vis[v]==0){
			if(cycleutil(v,gr,vis,team,u))
				return 1;
		}else if(par!=v){
			team.push_back(v);
			return 1;
		}
	}
	team.pop_back();
	return 0;
}
 
void toposort(ll u,vector<pair<int,ll>> gr[],vector<bool> &vis,stack<int>& st){
	vis[u]=1;
	for(auto v:gr[u]){
		if(vis[v.first]==0) toposort(v.first,gr,vis,st);
	}
	st.push(u);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	// ------------------------------------------------------------------counting room
	// cin>>n>>m;
	// vector<string> ar(n);
	// for(int i=0;i<n;i++){
	// 	cin>>ar[i];
	// } 
	// vector<vector<bool>> vis(n,vector<bool>(m));
	// int ans=0;	
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(ar[i][j]=='.'&&vis[i][j]==0)
	// 			dfs(ar,i,j,vis),ans++;
	// 	}
	// }
	// cout<<ans<<endl;
	//----------------------------------------------------------------------labyrinth
	// cin>>n>>m;
	// vector<string> ar(n);
	// for(int i=0;i<n;i++){
	// 	cin>>ar[i];
	// } 
	// vector<vector<bool>> vis(n,vector<bool>(m));
	// string ans="";
	// pair<int,int> st,end;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(ar[i][j]=='A')
	// 			st={i,j};
	// 		if(ar[i][j]=='B')
	// 			end={i,j};
	// 	}
	// }
	// queue<pair<int,int>> q;
	// map<pair<int,int>,pair<pair<int,int>,char>> par;
	// q.push(st);
	// vis[st.first][st.second]=1;
	// while(!q.empty()){
	// 	auto cur=q.front();
	// 	q.pop();
	// 	for(int i=0;i<4;i++){
	// 		int xx=cur.first;
	// 		int yy=cur.second;
	// 		int x=xx+l[i];
	// 		int y=yy+r[i];
	// 		if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&(ar[x][y]=='.'||ar[x][y]=='B')){
	// 			par[make_pair(x,y)]=make_pair(make_pair(xx,yy),step[i]);
	// 			vis[x][y]=1;
	// 			if(x==end.first&&y==end.second) break;
	// 			q.push({x,y});			
	// 		}
	// 	}
	// }
	// if(vis[end.first][end.second]){
	// 	while(end.first!=st.first||end.second!=st.second){
	// 		ans+=par[end].second;
	// 		end=par[end].first;
	// 	}
	// 	reverse(ans.begin(), ans.end());
	// 	cout<<"YES"<<endl<<ans.size()<<endl<<ans<<endl;
	// }
	// else cout<<"NO"<<endl;
	// ---------------------------------------------------------------building road
	// cin>>n>>m;
	// vector<int> gr[n+1];
	// for(int i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	gr[u].push_back(v);
	// 	gr[v].push_back(u);
	// }
	// vector<bool> vis(n+1);
	// vector<pair<int,int>> ans;
	// int pre=-1;
	// for(int i=1;i<=n;i++){
	// 	if(vis[i]==0){
	// 		if(pre!=-1){
	// 			ans.push_back({pre,i});
	// 		}
	// 		pre=i;
	// 		dfs(i,gr,vis);
	// 	}
	// }
	// cout<<ans.size()<<endl;
	// for(auto x:ans){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }
	//------------------------------------------------------------------- message route
	// cin>>n>>m;
	// vector<int> gr[n+1];
	// for(int i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	gr[u].push_back(v);
	// 	gr[v].push_back(u);
	// }
	// vector<bool> vis(n+1);
	// map<int,int> par;
	// vector<int> ans;
	// queue<int> q;
	// q.push(1);
	// vis[1]=1;
	// while(!q.empty()){
	// 	int cur=q.front();
	// 	q.pop();
	// 	for(int v:gr[cur]){
	// 		if(vis[v]==0){
	// 			q.push(v);
	// 			par[v]=cur;
	// 			vis[v]=1;
	// 			if(v==n) break;
	// 		}
	// 	}
	// }
	// if(vis[n]){
	// 	while(n!=1){
	// 		ans.push_back(n);
	// 		n=par[n];
	// 	}
	// 	cout<<ans.size()+1<<endl<<1<<" ";
	// 	reverse(ans.begin(), ans.end());
	// 	for(int x:ans) cout<<x<<" ";
	// 		cout<<endl;
	// }else cout<<"IMPOSSIBLE"<<endl;
	//---------------------------------------------------------------------building team
	// cin>>n>>m;
	// vector<int> gr[n+1];
	// for(int i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	gr[u].push_back(v);
	// 	gr[v].push_back(u);
	// }
	// vector<bool> vis(n+1);
	// queue<int> q;
	// vector<int> color={0,2,1};
	// vector<int> team(n+1,-1);
	// for(int i=1;i<=n;i++){
	// 	if(vis[i]==0){
	// 		q.push(i);
	// 		team[i]=1;
	// 		dfs(i,gr,vis);
	// 	}
	// }
	// while(!q.empty()){
	// 	int u=q.front();
	// 	q.pop();
	// 	int colr=team[u];
	// 	for(int v:gr[u]){
	// 		if(team[v]==-1){
	// 			q.push(v);
	// 			team[v]=color[colr];
	// 		}else {
	// 			if(team[v]==team[u]){
	// 				cout<<"IMPOSSIBLE"<<endl;
	// 				return 0;
	// 			}
	// 		}
	// 	}
	// }
	// for(int i=1;i<=n;i++) cout<<team[i]<<" ";
	//---------------------------------------------------------------------------- round trip	
	// cin>>n>>m;
	// vector<int> gr[n+1];
	// for(int i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	gr[u].push_back(v);
	// 	gr[v].push_back(u);
	// }
	// vector<bool> vis(n+1);
	// vector<int> team;
	// for(int i=1;i<=n;i++){
	// 	if(vis[i]==0){
	// 		if(cycleutil(i,gr,vis,team)){
	// 			map<int,bool> mp;
	// 			vector<int> ans;
	// 			for(int j=team.size()-1;j>=0;j--){
	// 				ans.push_back(team[j]);
	// 				if(mp[team[j]])
	// 					break;
	// 				mp[team[j]]=1;
	// 			}
	// 			cout<<ans.size()<<endl;
	// 			for(int j=0;j<ans.size();j++) cout<<ans[j]<<" ";
	// 			return 0;
	// 		}else team.clear();
	// 	}
	// }
	// cout<<"IMPOSSIBLE"<<endl;
	//-------------------------------------------------------------------------------- monster
	// cin>>n>>m;
	// vector<string> ar(n);
	// queue<vector<int>> q;
	// int x,y;
	// int dis[1001][1001],d[1001][1001];
	// for(int i=0;i<1000;i++){
	// 	for(int j=0;j<1000;j++)
	// 		dis[i][j]=d[i][j]=1000000;
	// }
	// for(int i=0;i<n;i++){
	// 	cin>>ar[i];
	// 	for(int j=0;j<m;j++){
	// 		if(ar[i][j]=='A') x=i,y=j;
	// 		if(ar[i][j]=='M'){
	// 			dis[i][j]=0;
	// 			q.push({i,j});
	// 		}
	// 	}
	// }
	// while(!q.empty()){
	// 	auto cur=q.front();
	// 	q.pop();
	// 	int xx=cur[0];
	// 	int yy=cur[1];
	// 	for(int k=0;k<4;k++){
	// 		int i=xx+l[k];
	// 		int j=yy+r[k];
	// 		if(i>=0&&i<n&&j>=0&&j<m&&ar[i][j]=='.'&&dis[i][j]>dis[xx][yy]+1){
	// 			dis[i][j]=dis[xx][yy]+1;
	// 			q.push({i,j});
	// 		}
	// 	}
	// }
	// queue<vector<int>> q1;
	// map<pair<int,int>,pair<pair<int,int>,char>> mp;
	// q1.push({x,y});
	// d[x][y]=0;
	// pair<int,int> end={-1,-1};
	// while(!q1.empty()){
	// 	auto cur=q1.front();
	// 	q1.pop();
	// 	int xx=cur[0];
	// 	int yy=cur[1];
	// 	if(xx==0||yy==0||xx==n-1||yy==m-1){
	// 		end={xx,yy};
	// 		string ans="";
	// 		while(end.first!=x||end.second!=y){
	// 			ans+=mp[end].second;
	// 			end=mp[end].first;
	// 		}
	// 		reverse(ans.begin(), ans.end());
	// 		cout<<"YES"<<endl;
	// 		cout<<ans.size()<<endl;
	// 		cout<<ans<<endl;
	// 		return 0;
	// 	}
	// 	for(int k=0;k<4;k++){
	// 		int i=xx+l[k];
	// 		int j=yy+r[k];
	// 		if(i>=0&&i<n&&j>=0&&j<m&&ar[i][j]=='.'&&dis[i][j]>d[xx][yy]+1&&d[i][j]==1000000){
	// 			d[i][j]=d[xx][yy]+1;
	// 			mp[{i,j}]={{xx,yy},step[k]};
	// 			q1.push({i,j});
	// 		}
	// 	}
	// }
	// cout<<"NO"<<endl;
	// ----------------------------------------------------------------------shortest path 1
	// cin>>n>>m;
	// vector<pair<int,ll>> gr[n+1];
	// for(int i=0;i<m;i++){
	// 	int u,v,w;
	// 	cin>>u>>v>>w;
	// 	gr[u].push_back({v,w});
	// }
	// vector<ll> d=djkstra(gr,1);
	// for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	// ---------------------------------------------------------------------shortest path 11
	// int q;
	// cin>>n>>m>>q;
	// vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e15));
	// for(int i=1;i<=n;i++)dp[i][i]=0;
	// for(int i=0;i<m;i++){
	// 	ll u,v,w;
	// 	cin>>u>>v>>w;
	// 	dp[u][v]=min(dp[u][v],w);
	// 	dp[v][u]=min(dp[v][u],w);
	// }
	// for(int k=1;k<=n;k++){
	// 	for(int i=1;i<=n;i++){
	// 		for(int j=1;j<=n;j++){
	// 			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	// 		}
	// 	}
	// }
	// while(q--){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	if(dp[u][v]==1e15)dp[u][v]=-1;
	// 	cout<<dp[u][v]<<endl;
	// }
	// -----------------------------------------------------------------------high score
	// cin>>n>>m;
	// vector<pair<ll,ll>> gr[n+1];
	// vector<ll> dp(n+1,-1e15);
	// dp[1]=0;
	// for(int i=0;i<m;i++){
	// 	ll u,v,w;
	// 	cin>>u>>v>>w;
	// 	gr[u].push_back({v,w});
	// }
	// stack<int> st,st1;
	// vector<bool> vis(n+1);
	// toposort(1,gr,vis,st);
	// st1=st;
	// while(!st.empty()){
	// 	int cur=st.top();
	// 	st.pop();
	// 	for(auto i:gr[cur]){
	// 		if(dp[i.first]<dp[cur]+i.second)
	// 			dp[i.first]=dp[cur]+i.second;
 
	// 	} 
	// }
	// vector<int> chk;
	// while(!st1.empty()){
	// 	int cur=st1.top();
	// 	st1.pop();
	// 	for(auto i:gr[cur]){
	// 		if(dp[i.first]<dp[cur]+i.second){
	// 			chk.push_back(cur);
	// 		}
	// 	} 
	// }
	// for(int i=0;i<=n;i++) vis[i]=0;
	// bool neg=0;
	// for(int i=0;i<chk.size();i++){
	// 	go(chk[i],vis,gr,neg);
	// 	if(neg){
	// 		dp[n]=-1;
	// 		break;
	// 	}
	// }
	// cout<<dp[n]<<endl;
	// ---------------------------------------------------------------------flight discount
	// cin>>n>>m;
	// vector<pair<int,ll>> gr[n+1],rev[n+1];
	// vector<vector<ll>> edge;
	// for(int i=0;i<m;i++){
	// 	int u,v,w;
	// 	cin>>u>>v>>w;
	// 	gr[u].push_back({v,w});
	// 	rev[v].push_back({u,w});
	// 	edge.push_back({u,v,w});
	// }
	// vector<ll> d1=djkstra(gr,1);
	// vector<ll> d2=djkstra(rev,n);
	// ll ans=1e18;
	// for(auto x:edge){
	// 	ll u=x[0],v=x[1],w=x[2];
	// 	ans=min(ans,d1[u]+w/2+d2[v]);
	// }
	// cout<<ans<<endl;
	// ---------------------------------------
	cin>>n>>m;
	vector<vector<ll>> edge;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u;v;
		edge.push_back({u,v,w});
	}
	vector<ll> d(n+1,1e15);
	d[1]=0;
	vector<bool> vis(n+1);
	vector<int> path(n+1,-1);
	int till=-1;
	for(int i=1;i<=n;i++){
		till=-1;
		for(auto x:edge){
			ll u=x[0],v=x[1],w=x[2];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				path[v]=u;
				till=v;
			}
		}
	}
	if(till==-1){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++) till=path[till];
	vector<int> cycle;
	for(int a=till;;a=path[a]){
		cycle.push_back(a);
 		if(cycle.size()>1&&a==till){
 			break;
 		}
 	}
 	reverse(cycle.begin(), cycle.end());
 	for(auto x:cycle) cout<<x<<" ";
}
 
 
 
 
 
