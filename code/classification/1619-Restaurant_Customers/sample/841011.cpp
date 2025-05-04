#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, i, j, k, m;
    cin >> n;
    vector<pair<lli, bool>>v;
    for (i=0;i<n;i++)
    {
        cin>>m>>k;
        v.push_back(make_pair(m, true));
        v.push_back(make_pair(k, false));
    }
    sort(v.begin(), v.end());
    m=0;k=0;
    for (i=0;i<v.size();i++)
    {
        k+= v[i].second ? 1 : -1 ;
        m=max(m,k);
    }
    cout<<m;
 
    return 0;
}
