#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adjList(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    queue<int> q;
    vector<int> v(n, 0);
    vector<int> p(n);
    int flag=1;
    int s, e;
    for(int i=0; flag && i<n; i++){
        if(v[i]){
            continue;
        }
        q.push(i);
        v[i] = 1;
        p[i] = -1;
        while(flag && !q.empty()){
            int sz = q.size();
            while(flag && sz--){
                int cur = q.front();
                // cout << cur << " "; 
                q.pop();
                for(auto i: adjList[cur]){
                    if(v[i] && p[cur]!=i){
                        flag = 0;
                        s = i;
                        e = cur;
                        break;
                    }
                    if(!v[i]){
                        v[i] = 1;
                        p[i] = cur;
                        q.push(i);
                    }
                }
            }
        }
    }
    if(flag){
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> re;
    while(e!=-1){
        re.push_back(e);
        e = p[e];
    }
    vector<int> rs;
    while(s!=-1){
        rs.push_back(s);
        s = p[s];
    }
    reverse(re.begin(), re.end());
    reverse(rs.begin(), rs.end());
    int i=0;
    while(re[i]==rs[i]){
        i++;
    }
    cout << rs.size()+re.size()-2*i+2 << "\n";
    for(int j=rs.size()-1; j>=i; j--){
        cout << rs[j]+1 << " ";
    }
    cout << rs[i-1]+1 << " ";
    for(int j=i; j<=re.size()-1; j++){
        cout << re[j]+1 << " ";
    }
    cout << rs[rs.size()-1]+1 << "\n";
}
 
int main(){
    solve();
    return 0;
}
