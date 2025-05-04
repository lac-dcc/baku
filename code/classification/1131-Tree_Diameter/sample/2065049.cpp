#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
#define mod 1000000007
using namespace std;
 
vector<int> edges[200005];
vector<bool> visited(200005, false);
 
int dfs(int x, int& ans){
    visited[x]= true;
    int a = 0;
    int b = 0;
    int tmp;
    for(auto i: edges[x]){
        if(!visited[i]){
            tmp = 1+dfs(i, ans);
            if(tmp>a){
                b = a;
                a = tmp;
            }else if(tmp>b){
                b = tmp;
            }
        }
    }
    ans = max((a+b), ans);
    return a;
}
 
 
void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    visited[1] = true;
    int a = 0;
    int b = 0;
    int ans = 0;
    int tmp;
    for(auto i: edges[1]){
        tmp = 1+dfs(i, ans);
        if(tmp>a){
            b = a;
            a = tmp;
        }else if(tmp>b){
            b = tmp;
        }
    }
 
    cout << max(a+b,ans);
 
 
}
 
int32_t main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
