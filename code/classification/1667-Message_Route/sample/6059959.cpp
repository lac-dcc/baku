#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
typedef long long ll;
 
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define deb2(x,y) cout<<"[ "<<#x<<"="<<x<<","<<#y<<"="<<y<<" ]\n"
#define deba(x,n) cout<<#x<<": [ ";for(int i=0;i<n;i++){cout<<x[i]<<" ";}cout<<"]\n"; 
#define deba2(x,n,m) cout<<#x<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<x[i][j]<<" ";cout<<"\n";}; 
#define debe(x) cout<<#x<<":[ ";for(auto i:x){cout<<i<<" ";}cout<<"]\n"; 
#else
#define deb(x) 
#define deb2(x,y) 
#define deba(x,n) 
#define deba2(x,n,m) 
#define debe(x) 
#endif
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
 
    vector<int>adj[n+1];
 
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    vector<int>parent(n+1,-1);
    function<bool(int,int)>bfs=[&](int s,int e)->bool{
 
	    fill(all(parent),-1);
 
    	queue<int>q;
    	parent[s]=-2;
    	q.push(s);
 
    	while(!q.empty())
    	{
    		int curr=q.front();
    		q.pop();
    		if(curr==e)
    			return true;
    		for(int nb:adj[curr])
    		{
    			if(parent[nb]==-1)
    			{
    				parent[nb]=curr;
    				q.push(nb);
    			}
    		}
    	}
    	return false;
    };
 
    if(bfs(1,n))
    {
    	int curr=n;
    	vector<int>path;
    	while(curr!=-2)
    	{
    		path.pb(curr);
    		curr=parent[curr];
    	}
    	reverse(all(path));
    	cout<<sz(path)<<"\n";
    	for(auto x:path)
    		cout<<x<<" ";
    }
    else
    	cout<<"IMPOSSIBLE\n";
   
 
    return 0;
}
