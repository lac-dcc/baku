#include <bits/stdc++.h>
using namespace std;
string s,r;
int f[5004][5004];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s>>r;
    int m=s.size(), n=r.size();
    s='*'+s; r='^'+r;
    //for (int i=1;i<=m;i++)
        //dp[i]=1e18;
    for (int i=1;i<=m;i++) f[i][0]=i;
    for (int i=1;i<=n;i++) f[0][i]=i;
    for (int i=1;i<=m; i++)
    {
        for (int j=1;j<=n; j++)
            if (s[i]==r[j]) f[i][j]=f[i-1][j-1];
            else
            {
                int them =f[i][j-1]+1;
                int xoa =f[i-1][j]+1;
                int thay =f[i-1][j-1]+1;
                f[i][j]=min({them,xoa,thay});
            }
    }
 
    cout<<f[m][n];
    return 0;
}
