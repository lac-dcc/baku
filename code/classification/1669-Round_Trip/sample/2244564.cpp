#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int lca = 0;
int curroot = 0;
deque <int> dq;
bool vis [150000];
bool vis2 [150000];
vector <int> edgs [150000];
 
 
 
pair<bool,bool> pt(int cur, int par, int a, int b){
  //  cout << cur << endl;
  //  cout << a << b << endl;
    vis2[cur] = true;
    bool afound = false;
    bool bfound = false;
    if(cur == a){
        afound = true;
    }
    if(cur == b){
        bfound = true;
    }
    for(int i = 0; i < edgs[cur].size(); i++){
        if(edgs[cur][i] != par && !vis2[edgs[cur][i]]){
            pair<bool,bool> p = pt(edgs[cur][i], cur,a,b);
            afound = (afound || p.first);
            bfound = (bfound || p.second);
        }
    }
  //  cout << cur << " " << par << " " << a << " " << b << " " << afound << " " << bfound << endl;
    if(afound && bfound && lca == 0){
        lca = cur;
    }else if(afound && !bfound){
        dq.push_front(cur);        
    }else if(!afound && bfound){
        dq.push_back(cur);
    }
    return make_pair(afound,bfound);
    
}
 
void dec(int cur, int par){
//    cout << cur << endl;
    vis[cur] = true;
    for(int i = 0; i < edgs[cur].size(); i++){
        if(lca != 0){
            break;
        }
        if(edgs[cur][i] != par){
            if(vis[edgs[cur][i]]){
         //       cout << "*" << endl;
                
                pt(curroot,0,cur, edgs[cur][i]);
            } 
            if(lca == 0){
                dec(edgs[cur][i],cur);    
            }
        }
    }
}
 
 
 
int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        edgs[a].push_back(b);
        edgs[b].push_back(a);
    }
    
    dq.push_back(0);
    for(int i = 1; i <= n; i++){
        if(!vis[i] && lca == 0){
            curroot = i;
            dec(i,0);    
        }
    }
    if(lca == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        
        dq.push_back(dq.front());
        cout << dq.size() << endl;
        
        while(!dq.empty()){
           // cout << dq.front() << "*";
            if(dq.front() == 0){
                cout << lca << " ";
            }else{
                cout << dq.front() << " ";
            }
            dq.pop_front();
        }
    }
    
}
