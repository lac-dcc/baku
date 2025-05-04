#include <cstdio>
#include <map>
using namespace std;
map<int,int> m;
int n, x, a[200005];
int main(){
    scanf("%d%d", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        m[a[i]]=i;
    }
    for(int i=0; i<n; i++){
        int b = x - a[i];
        if(m.find(b)!=m.end() && i != m[b]){
            printf("%d %d", i+1, m[b]+1);
            return 0;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}