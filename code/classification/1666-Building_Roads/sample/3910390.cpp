#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define int long long
#define inf LLONG_MAX
#define endl '\n'
#define mod 1000000007
#define sort(x) sort(x.begin(),x.end())
 
template<class T>
T ceil(T a,T b){
    return (a+b-1)/b;
}
template<class T>
T floor(T a,T b){
    return a/b;
}
 
// int n,x,y;
 
// int check(int mid){
//     if(mid<min(x,y))
//         return 0;
//     mid-=min(x,y);
//     return mid/x+mid/y+1>=n ;
// }
// bool chk(int t)
// {
//    if(t<min(x,y))
//     return 0;
//    t-=min(x,y);
//    n--;
//    int k=t/x+t/y;
//    if(k>=n)
//    return 1;
//    return 0;
// }
 
void bfs(vector<vector<int>>& v,vector<int>& vis,int s){
    queue<int> q;
    q.push(s);
    // vis[1]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        vis[f]=1;
        for(auto &i:v[f]){
            if(!vis[i]){
                q.push(i);
            }
        }
    }
}
 
 
void solution(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    int t=m;
    while(t--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
 
    int sum=0;
    vector<int> vis(n+1);
    queue<int> q;
    q.push(1);
    // vis[1]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        vis[f]=1;
        for(auto &i:v[f]){
            if(!vis[i]){
                q.push(i);
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sum++;
            ans.pb(i);
            bfs(v,vis,i);
        }
    }
    if(sum!=0){
        cout<<sum<<endl;
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<" "<<ans[i+1]<<endl;
        }
        cout<<1<<" "<<ans[0]<<endl;
    }
    else
        cout<<0<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
 
    solution();
    return 0;
}
