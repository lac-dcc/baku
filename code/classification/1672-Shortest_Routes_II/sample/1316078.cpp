#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
// vector<pi> g[100010];
ll g[510][510];
int main() {
    memset(g,0x3f,sizeof(g));
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        // assert(a!=b);
        g[a][b]=min((ll)c,g[a][b]);
        g[b][a]=min((ll)c,g[b][a]);
    }
    for(int i=1; i<=n; i++)g[i][i]=0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",g[a][b]==0x3f3f3f3f3f3f3f3f?-1:g[a][b]);
    }
    return 0;
}
