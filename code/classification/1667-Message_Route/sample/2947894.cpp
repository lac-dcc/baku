#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
//using ulli = __uint128_t;
typedef int64_t ti;
#define endl '\n'
lli mod=1e9 + 7;
 
 
//lli dp[101][151][2];
//lli dp[1001][1001];
 
/*int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
 
lli poww(lli a, lli b)
{
    lli res = 1;
    for(int i = 1; i<=b; ++i)
    {
        res=(res%mod)*(a%mod);
        res=res%mod;
    }
 
    return res;
}
 
lli bp(lli x,lli y,lli c)
{
    lli res=1;
    x=x%c;
    while(y)
    {
        if(y&1) res=(res*x)%9;
        x=(x*x)%c;
        y=y/2;
    }
    return res%c;
}*/
 
/*struct node
{
    int count;
    bool end;
    node* a[26];
};
 
node* getNode()
{
    node* n=new node;
    n->end=false;
    n->count=0;
    for(int i=0;i<26;i++)
    {
        n->a[i]=NULL;
    }
    return n;
 
}
 
void insert(node *root,string s)
{
    node* temp=root;
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
 
        if(temp->a[index]==NULL)
        {
            temp->a[index]=getNode();
        }
        temp->count++;
        temp=temp->a[index];
    }
    temp->count++;
    temp->end=true;
}
 
int search(node *root,string s)
{
    node* temp=root;
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
 
        if(temp->a[index]==NULL) return 0;
 
        temp=temp->a[index];
    }
    return temp->count;
}
 
 
 
 
void lightshu()
{
    node* root =getNode();
    lli n,m;
    cin>>n>>m;
    vector<string> a(n),b(m);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(root,a[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        cout<<search(root,b[i])<<endl;
    }
}*/
 
 
 
/*bool dfs(lli i,lli p,vector<lli> &par, vector<lli> &vis,vector<lli> adj[])
{
    vis[i]=1;
    par[i]=p;
    for(auto it:adj[i])
    {
        if(par[i]==it) continue;
        if(vis[it])
        {
            s=it;
            e=i;
            return true;
        }
        if(vis[it]==0)
        {
            if(dfs(it,i,par,vis,adj)) return true;
        }
    }
    return false;
}*/
 
int find(int v,vector<int> &par)
{
    if(par[v]<0)
    {
        return v;
    }
    return par[v]=find(par[v],par);
}
 
void dfs(int i,vector<int> adj[],vector<int> &vis)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(vis[it]==0)
        {
            dfs(it,adj,vis);
        }
    }
}
 
void bfs(vector<int> adj[],vector<int> &par,vector<int>& vis)
{
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto it:adj[a])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                q.push(it);
                par[it]=a;
            }
        }
    }
}
 
 void lightshu()
 {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<int> ans;
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    
    bfs(adj,par,vis);
    
    if(vis[n]==0) 
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    ans.push_back(n);
    int p=par[n];
    while(p!=-1)
    {
        ans.push_back(p);
        p=par[p];
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
 
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
 }
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    std::unordered_map<std::string, int>::iterator it;
 
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 
    int t;
    t=1;
    //cin>>t;
    for(int j=1;j<t+1;j++)
    {
        //cout<<"Case "<<j<<":"<<endl;
        lightshu();
 
    }
}
