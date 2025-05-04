#include<bits/stdc++.h>
using namespace std;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define int long long
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
 
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    f(i,0,n)
    {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,true));
        v.push_back(make_pair(y,false));
 
    }
    sort(v.begin(),v.end());
    int sum = 0;
    int ans = 0;
    f(i,0,2*n)
    {
    if(v[i].second == true )
    {
        ans ++;
        sum = max(sum,ans);
    }
    else
    {
        ans --;
    }
 
    }
    cout << sum << endl;
    return 0;
}
