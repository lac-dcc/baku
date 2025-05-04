#include <iostream>
#define endl "\n"
#include <numeric>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <bitset>
#include <map>
#include <sstream>
#include <cmath>
#include <stdlib.h> // itoa
#include <cstring>
#include <queue>
#define for1(i,a,n) for(int i=a; i<n; ++i)
#define mod 1000000007
#define cyes cout << "YES\n"
#define cno cout << "NO\n"
#define mone cout << -1 << endl
#define all(s) s.begin(), s.end()
 
using ll=long long int;
using namespace std;
 
ll dp[1000001];
void myfunc()
{
        int n, k;
        cin >> n >> k;
        memset(dp, mod, sizeof(dp));
        int a[n];
        for(int i=0; i<n; ++i)
            cin >> a[i];
        sort(a, a+n);
        dp[0]=0;
        //cout << dp[0] << endl;
        for(int i=1; i<=k; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i-a[j]<0)
                    break;
                //cout << dp[i] << " " << dp[i-a[j]] << endl;
                dp[i]=min(dp[i], 1+dp[i-a[j]]);
                //dp[i]%=1000000007;
            }
        }if(dp[k]==506381209866536711)
            mone;
        else cout << dp[k] << endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
    {
        myfunc();
    }
 
	return 0;
}
