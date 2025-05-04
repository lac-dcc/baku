/*never stop learning
because life 
never stops teaching
                    ~Kirill Korshikov
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define pob pop_back()
#define ms0(s) memset(s,0,sizeof s)
#define ff first
#define ss second
typedef int ll;
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define prq priority_queue<ll> 
#define psq priority_queue<ll,vector<ll>,greater<ll>>  
#define mp make_pair
#define vcc vector<char>
#define vss vector<string>
#define output(x) {for(auto dsp:x)cout<<dsp<<" ";}
#define input(x) {for(auto &i :x) cin>>i;}
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define output(x) {for(auto dsp:x)cout<<dsp<<" ";}
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define ln cout<<endl
#define auto(i,m) for(auto i: m)
#define res(ans) cout<<ans
#define setbit(n) __builtin_popcountll(n)
const ll mxn = 2e5 + 5;
void init_code(){
    
    #ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
 
}
 
string tobinary(int n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}  
ll lcm(ll a,ll b){
    return (a/__gcd(a,b))*b;
}
 
 
vll ar[mxn];
ll par[mxn];
ll vis[mxn];
void dfs(ll n)
{
    vis[n]=1;
    for(auto i: ar[n])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}    
 
 
ll cal(ll a,ll b)
{
    ll ans=1;
    ll temp=a;
    while(b>0)
    {
        if(b%2)
            ans=(ans*temp)%mod;
        temp=(temp*temp)%mod;
        b=b/2;
    }
    // cout<<ans;
    return ans;
}
 
int main(){
    init_code();
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,x,y,x1,x2,y2,k,y1,flag=0,l=0,r=0,d=0,count=0,sum=0,mn=1e6,mx=-1e6;
        cin>>n>>m;
        vll ans(n+1);
        rep(i,m)
        {
            cin>>x>>y;
            ar[x].pb(y);
            ar[y].pb(x);
        }
        ans[1]=1;
        queue<ll>q;
        
        rep1(i,n)
        {
            if(!vis[i])
            {
                q.push(i);
                ans[i]=1;
                while(!q.empty())
                {
                    x=q.front();
                    vis[x]=1;
                    q.pop();
                    for(auto i: ar[x])
                    {
                        if(!vis[i])
                        {
 
                            vis[i]=1;
                            if(ans[x]==1)
                                ans[i]=2;
                            else
                                ans[i]=1;
                            q.push(i);
                        }
                        else if(ans[i]==ans[x])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
                
        }
        
        if(!flag)
        {
            rep1(i,n)
                cout<<ans[i]<<" ";
        }
        else
            cout<<"IMPOSSIBLE";
        // ln;
    }
    return 0;
}
