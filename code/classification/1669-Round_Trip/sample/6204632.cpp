 #include <bits/stdc++.h>
    using namespace std;
     
     
    int n, m;
    int sv, ev;
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> parent;
     
     
    bool dfs(int u, int p)
    {
    	vis[u] = true;
    	parent[u] = p;
    	for(auto v: g[u])
    	{
    		if(v == p) continue;
    		if(vis[v]) 
    		{
    			sv = v; 
    			ev = u; 
    			return true;
    		} 
    		if(!vis[v]) 
    			if(dfs(v,u)) 
    				return true;
    	}
    	return false;
    }
     
     
    bool visit_all()
    {
    	for(int i = 1; i <= n; ++i)
    	{
    		if(!vis[i])
    			if(dfs(i,-1)) return true;
    	}
    	return false;
    }
     
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cin >> n >> m;
    	g.resize(n+1);
    	vis.resize(n+1);
    	parent.resize(n+1);
    	for(int i =0 ; i < m; ++i)
    	{
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
     
    	if(!visit_all())
    	{
    		cout << "IMPOSSIBLE" << endl;
    		return 0;
    	}
     
    	int tv = ev;
    	vector<int> ans;
    	ans.push_back(ev);
    	while(tv != sv)
    	{
    		ans.push_back(parent[tv]);
    		tv = parent[tv];
    	}
    	ans.push_back(ev);
    	cout << ans.size() << endl;
    	for(auto c: ans)
    	{
    		cout << c << " ";
    	}
     
    }
