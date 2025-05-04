#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
using namespace std;
 
void FastIO();
int main(){
    
    FastIO();
    int n,m; cin >> n >> m;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n, 0);
    vector<int> route(n, 0);
 
    int u,v; 
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
        adjList[v - 1].push_back(u - 1);
    }
 
    function<void()> BFS = [&]() {
        queue<int> sendMessage;
        sendMessage.push(0);
        while(!sendMessage.empty()){
            int q = sendMessage.size();
            while(q--){
                int computer = sendMessage.front();
                sendMessage.pop();
 
                for(int comp : adjList[computer])
                    if(!visited[comp]){
                        visited[comp] = 1;
                        route[comp] = computer;
                        if(comp == n - 1)
                            return;
                        sendMessage.push(comp);
                    }
            }
        }
    };
 
    route[n - 1] = -1;
    BFS();
    if(route[n - 1] == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> theRoute;
    int curComp = n - 1;
    while(curComp){
        theRoute.push_back(curComp + 1);
        curComp = route[curComp];
    }
 
    cout << theRoute.size() + 1 << "\n1 ";
    for(int i = theRoute.size() - 1; i > -1; i--)
        cout << theRoute[i] << ' ';
    cout << '\n';
 
    return 0;
}
void FastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}