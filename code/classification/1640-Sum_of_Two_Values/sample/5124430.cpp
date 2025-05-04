#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
 
 
const int N = 2e5+6;
 
 
void solve(int tc){
    int n,k;
    scanf("%d %d",&n,&k);
 
    map<int,int>vis;
 
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(vis.count(k-x)){
            printf("%d %d\n",vis[k-x],i+1);
            return;
        }
        vis[x] = i+1;
    }
 
    printf("IMPOSSIBLE\n");
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}