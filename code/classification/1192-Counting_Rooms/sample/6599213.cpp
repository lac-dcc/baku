#include <bits/stdc++.h>
#define ll pair <long long ,long long>
#define int long long
using namespace std;
 
vector <int> v;
vector <ll> v2;
int a[2000][2000];
int danhdau[2000][2000];
int sz=0;
int h[5],h2[5];
int n,m;
queue<ll> q;
string s[1001];
 
void dfs(int i3,int i4)
{
    // danhdau[i3][i4]=1;
    // sz++;
    while (q.size()) q.pop();
    q.push({i3,i4});
    sz=1;
    danhdau[i3][i4]=1;
    while (q.size())
    {
        int i3=q.front().first;
        int i4=q.front().second;
        q.pop();
        // sz++;
        // danhdau[i3][i4]=1;
        for (int i5=1;i5<=4;i5++)
        {
            int i=i3+h[i5];
            int i2=i4+h2[i5];
            if ((i<1) or (i2<1) or (i>n) or (i2>m)) continue;
            if (danhdau[i][i2]==1) continue;
            if (a[i][i2]==0) continue;
            danhdau[i][i2]=1;
            sz++;
            q.push({i,i2});
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    h[1]=1;
    h2[1]=0;
    h[2]=-1;
    h2[2]=0;
    h[3]=0;
    h[4]=0;
    h2[3]=1;
    h2[4]=-1;
    //cin >> n >> m;
    while (cin >> n >> m)
    {
        if ((n==0) and (m==0)) return 0;
        for (int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]='#'+s[i];
        }
        v.clear();
        for (int i=1;i<=n;i++)
        {
            for (int i2=1;i2<=m;i2++)
            {
                if (s[i][i2]=='.') a[i][i2]=1;
                if (s[i][i2]=='#') a[i][i2]=0;
                //cin >> a[i][i2];
                danhdau[i][i2]=1-a[i][i2];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int i2=1;i2<=m;i2++)
            {
                if (danhdau[i][i2]==0) 
                {
                    sz=0;
                    dfs(i,i2);
                    if (sz!=0) v.push_back(sz);
                }
            }
        }
        cout << v.size() << '\n';
    }
}
