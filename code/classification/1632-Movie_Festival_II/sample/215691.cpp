#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
 
int K, N;
pii m[200005];
 
bool cmp (const pii &a, const pii &b) {
    return (a.second==b.second) ? (a.first<b.first) :  (a.second<b.second);
}
 
int main () {
    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++)
        scanf("%d %d", &m[i].first, &m[i].second);
    sort(m, m+N, cmp);
    int ans=0;
    multiset<int> fin;
    for (int i=0; i<N; i++) {
        bool add=false;
        if (!fin.size())
            add=true;
        else {
            set<int>::iterator it=fin.upper_bound(m[i].first);
            if (it!=fin.begin()) {
                fin.erase(--it);
                add=true;
            }
            else if (fin.size()<K)
                add=true;
        }
        if (add) {
            fin.insert(m[i].second);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
