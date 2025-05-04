/**
 * @author      : szcz (szcz@$HOSTNAME)
 * @created     : 17/01/2022
 * @filename    : gridpaths
 */
#define ll long long
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    
 
    cin >> n >> m;
    vector<int> t(m);
    int z;
    multiset<int> s;
    for (int i=0;i<n;++i)
    {
        cin >> z;
        s.insert(z);
    }
    for (int i=0;i<m;++i)
    {
        cin >> t[i];
    }
    multiset<int>::iterator ix;
 
    for (int k=0; k < m; ++k)
    {
        if (s.size() == 0) cout << "-1" << endl;
        else
        {
            ix = s.upper_bound(t[k]);
            if (ix == s.begin()) cout << "-1" << endl;
            else
            {
                cout << *(--ix) << endl;
                s.erase(ix);
            }
        }
    }
    return 0;
}
 
