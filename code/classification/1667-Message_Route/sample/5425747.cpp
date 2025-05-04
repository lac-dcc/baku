#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
#define mod2 998244353
#define pb push_back
#define mp make_pair
#define count_1(n) __builtin_popcountll(n)
#define F first
#define S second
#define MEM(a, b) memset(a, (b), sizeof(a))
#define all(x) x.begin(),x.end()
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        vector<int>g[n+1];
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<pair<int,int>>q;
        vector<int>vis(n+1,0);
        vector<int>bt(n+1,0);
        q.push({1,1});
        int f=0;
        while(!q.empty()){
            int cur = q.front().first;
            int val = q.front().second;
            q.pop();
            if(vis[cur])continue;
            vis[cur]=1;
            if(cur==n){
                cout<<val<<endl;
                int j=cur;
                vector<int>bb;
                bb.push_back(cur);
                while(bt[j]!=0){
                    bb.push_back(bt[j]);
                    j=bt[j];
                }
 
                reverse(bb.begin(),bb.end());
                for(int i=0;i<bb.size();i++){
                    cout<<bb[i]<<" ";
                }
                f=1;
                break;
            }
            for(auto &child:g[cur]){
                if(vis[child])continue;
                if(bt[child]==0)bt[child]=cur;
                q.push({child,val+1});
            }
        }
        if(f==0)cout<<"IMPOSSIBLE\n";
    return 0;
}
