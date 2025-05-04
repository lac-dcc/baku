#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int val, step;
    Node *pre;
 
    Node(int val, int step, Node *pre) : val(val), step(step), pre(pre) {}
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<int> connect[n + 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
 
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
 
    vector<bool> used(n + 1);
    queue<Node*> q;
    q.push(new Node(1, 1, nullptr));
 
    used[1] = true;
 
    while (!q.empty()) {
        Node* from = q.front();
        q.pop();
 
        if (from->val == n) {
            cout << from->step << '\n';
            stack<int> res;
 
            while (from != nullptr) {
                res.push(from->val);
                from = from->pre;
            }
            
            while (!res.empty()) {
                cout << res.top() << ' ';
                res.pop();
            }
 
            return 0;
        }
 
        for (const int &to: connect[from->val]) {
            if (used[to]) {
                continue;
            }
 
            q.push(new Node(to, from->step + 1, from));
            used[to] = true;
        }
    }
 
    cout << "IMPOSSIBLE\n";
}
