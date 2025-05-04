//MY code
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll dp[200005], down[200005], n;
vector<int>adj[200005];
void solve_depth(int cur, int par)
{
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]!=par)
        {
            solve_depth(adj[cur][i], cur);
            
            down[cur] = max(down[cur], down[adj[cur][i]]+1);
        }
    }
}
 
int arr[200005];
ll solve(int cur, int par, int papaka)
{
    //cout<<cur<<" "<<par<<" "<<papaka<<"\n";
    vector<pair<int, int> >dostlog;
    dostlog.clear();
    
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]!=par)
        {
            //cout<<adj[cur][i]<<" "<<cur<<"   hahahaha\n";
            dostlog.pb({down[adj[cur][i]]+1, adj[cur][i]});
        }
    }
    sort(dostlog.begin(), dostlog.end());
    int tot = dostlog.size();
    //cout<<cur<<" ------------"<<tot<<" \n";
    if(tot>=2)
    {
        for(int i=0;i<tot-1;i++)
        {
            arr[dostlog[i].ss]=dostlog[tot-1].ff;
        }
        arr[dostlog[tot-1].ss]=dostlog[tot-2].ff;
    }
    else if(tot==1)
    {
        arr[dostlog[0].ss]=0;
    }
    else
    {
        return dp[cur] = max(papaka, 0);
    }
    int res=0;
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]!=par)
        {
            res=max(arr[adj[cur][i]]+1, papaka+1);
            //cout<<cur<<" "<<adj[cur][i]<<" --> "<<arr[adj[cur][i]]+1<<" "<<papaka+1<<"\n";
            solve(adj[cur][i], cur, res);
        }
    }
    
    return dp[cur] = max(dostlog[tot-1].ff, papaka);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
	    cin>>a>>b;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	
	solve_depth(1,0);
	
	solve(1, 0, -1);
	
	for(int i=1;i<=n;i++)
	{
	    cout<<dp[i]<<" ";
	}
	return 0;
}
