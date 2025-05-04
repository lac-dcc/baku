#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int n,m,a,b;
const int MAX = 1e5+100;
std::vector<int> G[MAX];
int st,en; int ck[MAX]; int pp[MAX];
 
void opt(int cur) {
    ck[cur]=1;
    for (int dd : G[cur]) {
        if (dd==pp[cur]) continue;
        if (!ck[dd]) {
            pp[dd]=cur;
            opt(dd);
            if (st) return;
        }
        else if (ck[dd]==1) {
            pp[dd]=cur;
            st=cur; en=dd;
            return;
        }
    }
    ck[cur]=-1;
}
 
int main() {
    scanf("%d%d",&n,&m); st=0;
    memset(ck,0,sizeof(ck));
    for (int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);G[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (st) break;
        if (!ck[i])
            opt(i);
    }
    if (!st) { printf("IMPOSSIBLE"); }
    else {
        std::vector<int> sol = {};
        int cur = st;
        while (cur!=en) {
            sol.push_back(cur); cur = pp[cur];
        }
        sol.push_back(en);
        sol.push_back(st);
        int len = sol.size();
        printf("%d\n",len);
        for (int i=0; i<len; i++) {
            if (i) { printf(" "); }
            printf("%d",sol[i]);
        }
    }
    return 0;
}
