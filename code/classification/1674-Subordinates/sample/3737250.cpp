#include <iostream>
#include <vector>
using namespace std;
 
int n, p[200005], ans[200005];
vector <int> v[200005];
 
void dfs(int x){
    for (auto i:v[x]){
        dfs(i);
        ans[x] += ans[i]+1;
    }
}
 
int main() {
    cin >> n;
    for (int i = 2; i <= n; i++){
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
