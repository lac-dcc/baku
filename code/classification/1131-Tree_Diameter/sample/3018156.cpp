#include "bits/stdc++.h"
using namespace std;
#define int long long int
int inf=1e15;
//solve here
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
 
vector<vector<int>> adj(2*1e5+1);
//*state define
vector<int> diameter(2*1e5+1);//max diameter of tree rooted at 'i'
vector<int> depth(2*1e5+1);//depth[i]=max depth of tree rooted at 'i'
 
 
//*state transition
/*
=>I have 2 choices for any node,1)diameter-path does not go through node
                                2)a diameter-path goes through node
1->children of node=C1,C2,...Ck
Problem is splitted into sub-problems=finding diameter of node rooted at child node(C1,C2,...Ck)
We will take maximum of all this children's diameter
=>ans_1=max(diameter[C1],diameter[C2],....,diameter[Cn])
 
2->If a path goes through node,I would choose a path such that it is formed by paths of max depth.
Now as a path can go only downwards,I choose 2 child-nodes with maximum depths.
Let maxD1,maxD2 be first maximum and second maximum depth from all the children nodes.
=>ans_2=maxD1+2+maxD2
 
Now diameter of tree rooted at node 'n' would be maximum of this two choices
diameter[n]=max(ans_1,ans_2)
*/
 
 
//depth decides by edges and not nodes
void getDepth(int u,int par){
    int maxd=0;
    int leaf=1;
    for(int v:adj[u]){
        if(v!=par){
            //get all the children depths
            leaf=0;
            getDepth(v,u);
            //now take maximum of all this children depths
            maxd=max(maxd,depth[v]);
        }
    }
    if(leaf==1) depth[u]=0;
    else depth[u]=1+maxd;
}
 
void getDiameter(int u,int par){
    int exclude=0;//diameter excluding curr node 'u'
 
    vector<int> childDepth;
    for(int v:adj[u]){
        if(v!=par){
            //we need to build answer bottom up
            //thus DFS to run dp bottom up
            getDiameter(v,u);
            childDepth.push_back(depth[v]);
            exclude=max(exclude,diameter[v]);
        }
    }
 
    int numOfChildren=childDepth.size();
    sort(childDepth.begin(),childDepth.end());
 
    if(numOfChildren==0) diameter[u]=0;//leaf node
 
    else if(numOfChildren==1) diameter[u]=1+childDepth[0];
 
    else diameter[u]=childDepth[numOfChildren-1]+2+childDepth[numOfChildren-2];
 
    diameter[u]=max(diameter[u],exclude);
}
 
 
void solve(){
    int n;
	cin>>n;
 
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    getDepth(1,0);
    getDiameter(1,0);
    cout<<diameter[1]<<endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
