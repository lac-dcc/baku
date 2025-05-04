#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef int64_t ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 
 
const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    int n;cin>>n;
    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }
 
    vector<int> d(n,0);            
    function <void(int)> bfs = [&](int r){                
        queue<int> q;
        q.push(r);
        d[r]=1;                
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i: v[x]){
                
                if(d[i]==0){
                    d[i] = d[x]+1;
                    q.push(i);
                }
            }
        }                
        for(auto &i: d){
            i--;
        }
    };
 
    int r1=0,r2;
    bfs(r1);
    for(int i=0;i<n;i++){
        if(d[i]>d[r1])r1=i;
    }
    d=vector<int>(n,0);
    r2=r1;bfs(r1);
    for(int i=0;i<n;i++){
        if(d[i]>d[r2])r2=i;
    }
 
    vector<int> d1=d;
    d=vector<int>(n,0);
 
    bfs(r2);
    for(int i=0;i<n;i++){
        cout<<max(d[i],d1[i])<<" ";
    }
    cout<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}
