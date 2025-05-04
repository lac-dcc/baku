#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<long int,list<long int>>&mp,long int node,long int parent,vector<long int>&depth)
{ for(auto child:mp[node])
  { if(child!=parent)
    { depth[child]=depth[node]+1;
      dfs(mp,child,node,depth);
    }
  }
}
int main()
{ long int n,q;
  cin>>n;
  unordered_map<long int,list<long int>>mp;
  for(int i=1;i<=n-1;i++)
  { long int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  vector<long int>depth(n+1,0);
  vector<long int>depth1(n+1,0);
  vector<long int>ans(n+1,0);
  dfs(mp,1,-1,depth);
  long int max_depth=-1;
  long int max_depth_node,max_depth_node1;
  for(int i=1;i<=n;i++)
  { if(max_depth<depth[i])
    { max_depth=depth[i];
      max_depth_node=i;
    }
    depth[i]=0;
  }
  max_depth=-1;
  dfs(mp,max_depth_node,-1,depth);
  for(int i=1;i<=n;i++)
  { if(max_depth<depth[i])
    { max_depth=depth[i];
      max_depth_node1=i;
    }
  }
  max_depth=-1;
  dfs(mp,max_depth_node1,-1,depth1);
  for(int i=1;i<=n;i++)
  { if(max_depth<depth1[i])
    { max_depth=depth1[i];
      max_depth_node1=i;
    }
  }
  for(int i=1;i<=n;i++)
  ans[i]=max(depth1[i],depth[i]);
  for(int i=1;i<=n;i++)
  cout<<ans[i]<<" ";
  return 0;
} 
