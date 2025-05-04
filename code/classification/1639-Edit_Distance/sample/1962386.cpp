#include <bits/stdc++.h>
using namespace std;
 
#define INF 20000
 
char s[5005];
char t[5005];
int n, m;
 
int dp[5005][5005];
 
int f(int ind0, int ind1) {
    if (ind0 == -1 && ind1 == -1) return 0;
    if (ind0 == -1) return ind1 + 1;
    if (ind1 == -1) return ind0 + 1;
    if (dp[ind0][ind1] != -1) return dp[ind0][ind1];
 
    int best = INF;
    
    if (s[ind0] == t[ind1])
        best = min(best, f(ind0 - 1, ind1 - 1));
    else
        best = min(best, f(ind0 - 1, ind1 - 1) + 1);
    
    best = min(best, f(ind0, ind1 - 1) + 1);
    best = min(best, f(ind0 - 1, ind1) + 1);
 
    return dp[ind0][ind1] = best;
}
 
int main() {
    memset(dp, -1, sizeof dp);
 
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s);
    m = strlen(t);
 
    printf("%d\n", f(n - 1, m - 1));
 
    return 0;
}