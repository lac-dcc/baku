#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006LL
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    LL i, n, cnt, l, r, ans;
 
    cin >> n;
 
    ans = 0;
    for(i = 1; i < MAXN; i++)
    {
        cnt = n/i;
        ans = (ans + cnt*i) % MOD;
    }
 
    for(i = 1; i < MAXN; i++)
    {
        cnt = i;
        r = n/i;
        l = n/(i+1);
 
        if(r < MAXN)
            break;
        
        l = max(MAXN-1, l);
 
        l = l%MOD;
        r = r%MOD;
        ans = (ans + ((r*(r+1)/2 - l*(l+1)/2)%MOD + MOD)*cnt) % MOD;
    }
 
    cout << ans << "\n";
}
