#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxN = 1e6;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    static int A[maxN + 1];
    static int B[maxN + 1];
    for ( int i = 0; i < n; i++ )
        cin >> B[i];
    sort(B, B + n);
    A[0] = 0;
    for ( int i = 1; i <= x; i++ )
    {
        int mi = 1e9;
        for ( int j = 0; j < n; j++ )
        {
            int a = i - B[j];
            if ( a >= 0)
                mi = min(mi, A[a]);
            else break;
        }
        if ( mi < 1e9)
            A[i] += mi + 1;
        else A[i] = 1e9;
    }
    if ( A[x] < 1e9)
        cout << A[x];
    else cout << "-1";
}
