#include <bits/stdc++.h>
using namespace std;
typedef long long int lln;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fo(i, j, n) for (lln i = j; i < n; i++)
#define pb push_back
#define ff first
#define ss second
#define pi 3.1415926536
#define mod 1000000000 - 7
int find(vector<int> &dis,vector<bool> &vis){
    int min=INT_MAX,ind=0;
    for(int i=1;i<vis.size();i++){
        if(vis[i]==false&&dis[i]<=min){
            min=dis[i];ind=i;
        }
    }
    return ind;
}
vector<int>ans;
void dfs(vector<vector<int> > &adj,vector<bool> &vis,int n){
    vis[n]=true;
    ans.push_back(n);
    for(int i=0;i<adj[n].size();i++){
        if(!vis[adj[n][i]]){
            dfs(adj,vis,adj[n][i]);
        }
    }
 
}
 
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int> > adj(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(1);
    vis[1]=true;
    vector<int>v,p(n+1),dis(n+1);
    dis[1]=1;
    while(!q.empty()){
        int u=q.front();
        vis[u]=true;
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]==n){
                cout<<dis[u]+1<<"\n";
                v.push_back(n);
                v.push_back(u);
                int temp;
                while(u!=1){
                    temp=p[u];
                    v.push_back(temp);
                    u=temp;
                }
               
                for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";
                return ;
                
            }
            if(!vis[adj[u][i]]){
                vis[adj[u][i]]=true;
                dis[adj[u][i]]=dis[u]+1;
            q.push(adj[u][i]);
            p[adj[u][i]]=u;
            }
        }
        
    }
    cout<<"IMPOSSIBLE";
}
 
int main()
{
    // ;or getting input from input.txt file
    //freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// #include <iostream>  
//     using namespace std;  
//     class Animal {  
//         public:  
//         string color = "Black";  
//         // void func(){
//         //     cout<<"sa";
//         // }
//         virtual void func(){
//             cout<<"sa";
//         }  
//     };   
//     class Dog: public Animal   
//     {    
//      public:  
//         string color = "Grey";
//         void func(){
//             cout<<"san";
//         }    
//     };  
//     int main(void) {  
//          Animal *d;   //is same s Animal d=Dog() but earlier one is running at runtime but later one is
//          Dog g;                  //on compile timr
//          Animal a;
//          d=&g;
//          d->func();    
//          cout<<d->color;
//          cout<<"\n";
//          d=&a ; 
//          d->func(); 
//     }  
