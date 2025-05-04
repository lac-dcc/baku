#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<int> adjList[100001];
int teams[100001];
 
bool dfs(int startPerson, int startTeam) {
    stack<int> st;
 
    st.push(startPerson);
    teams[startPerson] = startTeam;
 
    while (!st.empty()) {
        int person = st.top(); st.pop();
        int team = teams[person];
 
        for (int fr: adjList[person]) {
            if (teams[fr] == 0) {
                teams[fr] = 3-team;
                st.push(fr);
            } else if (teams[fr] != 3-team) {
                return false;
            }
        }
    }
 
    return true;
}
 
int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
 
    for (int i=1; i<=n; i++) {
        if (teams[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
 
    for (int i=1; i<=n; i++) cout << teams[i] << " ";
    cout << endl;
}
