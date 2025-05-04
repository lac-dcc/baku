#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll getSuboordinates(vector<vector<ll> > &adjList, int i, vector<ll> &subList) {
    if (subList[i] != -1) return subList[i];
    int suboordinates = 0;
    for (auto neighbor : adjList[i]) {
        suboordinates += 1 + getSuboordinates(adjList, neighbor, subList);
    }
 
    subList[i] = suboordinates; 
    return suboordinates;
}
 
int main() {
    ll nodes; cin >> nodes;
    vector<vector<ll> > adjList(nodes, vector<ll>());
    for (ll i = 1; i < nodes; i ++) {
        ll boss; cin >> boss; boss --;
        adjList[boss].push_back(i);
    }
 
    vector<ll> suboordinates(nodes, -1);
    for (int i = 0; i < nodes; i ++) {
        cout << getSuboordinates(adjList, i, suboordinates) << " ";
    }
    cout << "\n";
}
