#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2*1e5+5;
vector<int> adjl[N+1];
vector<bool> marked(N+1);
 
vector<int> ans;
vector<bool> special(N+1);
int node = 0;
bool XD = false;
map<int, int> mp;
int t = 0;
void dfs(int k){
   if(XD){
     return;
   }
   if(marked[k]){
      if(mp[k] > 0){
        ans.push_back(k);
        XD = true;
      }
      return;
   }
   ans.push_back(k);
   marked[k] = true;
   mp[k]++;
   for(auto i : adjl[k]){
      if(XD){
        break;
      }
      if(special[i]){
         continue;
      }
      if(i == t){
        continue;
      }
      t = k;
      dfs(i);
   }
 
}
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n, m; cin >> n >> m;
 
    vector<int> paths(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
        paths[a]++;
        paths[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(paths[i] <= 1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int k = q.front(); q.pop();
        paths[k] = 0;
 
        for(auto i : adjl[k]){
            paths[i]--;
            if(paths[i] == 1){
                q.push(i);
            }
        }
    }
    bool XD = false;
    for(int i = 1; i <= n; i++){
        if(paths[i] > 1 && XD == false){
            node = i;
            XD = true;
        }
        else if(paths[i] == 0){
            special[i] = true;
        }
    }
    if(node == 0){
        cout << "IMPOSSIBLE" <<"\n";
        return 0;
    }
    dfs(node);
    int k = ans.back();
    bool ok = false;
    vector<int> sol;
    for(auto i : ans){
        if(i == k){
            ok = true;
        }
        if(ok == true){
            sol.push_back(i);
        }
    }
    cout << sol.size() <<"\n";
    for(auto i : sol){
        cout << i <<" ";
    }
}
 
/*7 8
1 2
2 3
3 4
2 4
1 5
5 6
5 7
6 7
 
*/
 
 
 
