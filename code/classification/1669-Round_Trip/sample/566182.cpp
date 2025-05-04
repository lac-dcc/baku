      #include <bits/stdc++.h>
        #define ll long long
        #define MOD 1000000007
        #define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #define test ll t; cin>>t; while(t--)
        #define int long long
        #define INF 1000000000000000005
        #define pb push_back
        #define pi 3.1415926
        #define MAX 300006
        #define MAX_N 1000000
        #define mp make_pair
        ll fpow(ll x,ll y,ll p=MOD){x=x%p;ll sum=1;while(y){if(y&1)sum=sum*x;sum%=p;y=y>>1;x=x*x;x%=p;}return sum;}
        ll fact[1000007]={0};
        void facto() {fact[0]=1;fact[1]=1;for(int i=2;i<100007;i++)fact[i]=(fact[i-1]*i)%MOD;}
        ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(fpow(fact[r],MOD-2)))%MOD; res=(res*(fpow(fact[n-r],MOD-2)))%MOD; return res;}
        ll npr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(fpow(fact[n-r],MOD-2)))%MOD; return res;}
        ll modmul(ll x, ll y){return (x*y)%MOD;}
        ll modadd(ll x, ll y){return (x+y)%MOD;}
        ll modsub(ll x, ll y){return (x-y+MOD)%MOD;}
        ll xx[4]={1,0,-1,0};
        ll yy[4]={0,1,0,-1};
 
        using namespace std;
 
 
        int col[200005];
        vector<int> v[200005];
        int vis[200005];
        int height[200005];
        vector<int> curr;
        void dfs(int root){
            //cout<<root<<endl;
            curr.push_back(root);
            vis[root]=1;
            height[root]=curr.size();
            for(auto it:v[root]){
                if(!vis[it]){
                    dfs(it);
                }
                if(vis[it] && height[root]-height[it]>1){
                    //cout<<root<<" "<<it<<endl;
                    cout<<height[root]-height[it]+2<<endl;
                    for(int i=height[it]-1;i<=height[root]-1;i++){
                        cout<<curr[i]<<" ";
                    }
                    cout<<curr[height[it]-1];
                    exit(0);
                }
 
            }
            curr.pop_back();
            height[root]=1e18;
 
        }
 
        signed main(){
          int n,m;
          cin>>n>>m;
          for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
          }
          for(int i=1;i<=n;i++){
            if(!vis[i])
            dfs(i);
          }
        cout<<"IMPOSSIBLE";
 
 
 
 
 
        }
