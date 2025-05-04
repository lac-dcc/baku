#include <bits/stdc++.h>
using namespace std;
 
int a[200100];
int b[200100];
 
int main(){
    int N, M, K; scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int j = 1; j <= M; j++) scanf("%d", &b[j]);
    sort(a+1, a+1+N); sort(b+1, b+1+M);
    int cur = 1;
    int cnt = 0;
    for (int i = 1; i <= M; i++){
        while (cur <= N && a[cur]+K < b[i]){
            cur++;
        }
        if (cur <= N && a[cur] <= b[i]+K){
            cnt++;
            cur++;
        }
    }
    printf("%d\n", cnt);
}
