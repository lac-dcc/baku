#include <bits/stdc++.h>
using namespace std;
 
vector<int> connections[200000];
 
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
 
pair<int, int> furthest_node(int index, int prev){
    if(connections[index].size() == 1 && connections[index][0] == prev) return(make_pair(0, index));
    pair<int, int> a = make_pair(-1, -1);
    for(int i: connections[index]){
        if(prev == i) continue;
        auto p = furthest_node(i, index);
        if(cmp(p, a)) a = p;
    }
    a.first++;
    return a;
}
 
int main(){
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    while(--n){
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    int end = furthest_node(0, -1).second;
    cout << furthest_node(end, -1).first;
}
