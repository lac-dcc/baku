#include"bits/stdc++.h"
using namespace std;
using namespace chrono;
 
const int mod=1e9+7;
#define ys              cout<<"YES";
#define no              cout<<"NO";
#define int             long long 
#define ndl             cout<<'\n';
#define pb              push_back
#define gcd             
#define ps(x,y)         fixed<<setprecision(y)<<x
#define testcase()      int x; cin>>x; while(x--)
#define all(x)          x.begin(),x.end()
#define NikhilTiwari    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cin(arr,n)      for (int i = 0; i < n; ++i) {cin>>arr[i];} 
#define forr(i,a,b)     for(int i=a; i<b; i++)
#define fauto(a,x)      for (auto a : x)  
#define vi              vector<int>   
 
 
void dfs(int root,int parent ,vector<vector<int>> &adj,vector<int>&depth,int yoyo){
 
    depth[root]=yoyo;
    yoyo++;
 
    fauto(i,adj[root]){
        if(i != parent){
            dfs(i,root,adj,depth,yoyo);
        }
    }
    
   
}
 
void solve(){
 
    int n; cin>>n;
    vector<vector<int>> adj(n,vector<int>());
 
    for(int i=1;i<n;++i){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        
    }
    
    vector<int> depth(n);
    int yoyo=0;
    dfs(0,-1,adj,depth,yoyo);
    
    // for(int i=0;i<n;++i){
    //     cout<<depth[i]<<" ";
    // }ndl
 
    int element = max_element(all(depth))-depth.begin();
    // cout<<element; ndl
    dfs(element,-1,adj,depth,yoyo);
 
    element = *max_element(all(depth));
    cout<<element; 
 
    
    
    
 
 
    
    
 
}
 
int32_t main(){
 
        NikhilTiwari 
 
        #ifndef ONLINE_JUDGE
            freopen("Error.txt", "w", stderr);
        #endif
 
        auto start1 = high_resolution_clock::now();
        
            solve();
            ndl
 
        
        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
                
        #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration.count()  << endl;
        #endif
}
