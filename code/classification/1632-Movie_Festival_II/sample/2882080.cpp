#include <bits/stdc++.h>
using namespace std;
const int MAXN = 212345;
pair <int, int> v[MAXN];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    multiset <int> s;
    multiset <int> :: iterator it;
    for(int i = 0; i < k; i++) s.insert(0);
    sort(v, v + n);
    int resp = 0;
    for(int i = 0; i < n; i++) {
        swap(v[i].first, v[i].second);
        it = s.upper_bound(v[i].first);
        if(it == s.begin()) {
            continue;
        }
        it--;
        resp++;
        s.erase(it);
        s.insert(v[i].second);
    }
    printf("%d\n", resp);
    return 0;
}