#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
 
const int N = 100005;
vector <int> v[N];
int col[N];
bool is = true;
 
void dfs(int x) {
    for (auto y : v[x]) {
        if (col[y]) {
            if (col[y] != 3 - col[x]) is = false;
        } else {
            col[y] = 3 - col[x];
            dfs(y);
        }
    }
}
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            col[i] = 1;
            dfs(i);
        }
    }
    if (is) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", col[i]);
        }
    } else {
        printf("IMPOSSIBLE");
    }
    return 0;
}
/*
5 3
1 2
1 3
4 5
*/
