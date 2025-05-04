#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define in(n) int n;cin>>n
#define do(n) double n;cin>>n;
//#define str(s) string s; getline(cin, s);
#define c(n) char n;cin>>n;
//#define wt int t;cin>>t;while(t--)
#define str(s) string s;cin>>s;
#define f(i,x,n) for(int i=x;i<n;i++)
#define fr(i,p,q) for(int i=p;i>=q;i--)
#define pb(x)  push_back(x)
#define inarray(n) int n;cin>>n;int arr[n];for(int i=0;i<n;i++)cin>>arr[i]
//#define map(c,m) map<c, c>m;
//#define m 1000000007
//#define wt int t;cin>>t;while(t--)
 
 
int32_t main(){
    in(n);in(m);
    
    vector<vector<pair<int, int>>>adj(n);
    
    f(i,0,m){
        in(u);in(v);in(w);
        adj[u-1].push_back({v-1, w});
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    
    pq.push({0, 0, 1});
    vector<vector<int>>dis(n, vector<int>(2, LONG_LONG_MAX));
    dis[0][1] = 0;
    
    while (!pq.empty()) {
        
        vector<int>s = pq.top();
        pq.pop();
        
        int distance = s[0];
        int node = s[1];
        int rem = s[2];
        
        if(dis[node][rem] < distance) continue;
        // imp else we get TLE
        
        
        for(auto it: adj[node]){
            if(rem==0){
                if(it.second+distance< dis[it.first][0]){
                    dis[it.first][0] =  it.second+distance;
                    pq.push({dis[it.first][0], it.first, 0});
                }
            }
            else{
                if(dis[it.first][1]>it.second+distance){
                    dis[it.first][1] = it.second+distance;
                    pq.push({dis[it.first][1], it.first, 1});
                }
                if(dis[it.first][0]>it.second/2+distance){
                    dis[it.first][0] = it.second/2 + distance;
                    pq.push({dis[it.first][0], it.first, 0});
                }
            }
            
        }
    }
    
    cout<<dis[n-1][0];
    return 0;
}
 
