/*                                     MH_Nazmul
                                  Let it be as simple
                                                                             */
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define all_g(x) x.rbegin(), x.rend()
using ll = long long;
const int N = 1e5 + 10;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <class T> // o_set<ll> st;  st.order_of_key(x);
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void solve(void)
{
    int n, m, d;
    cin >> n >> m >> d;
    map<ll, ll> mp;
    o_set<ll> st;
    vector<ll> v(m);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
        mp[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    // v.push_back(1e10);
    sort(all(v));
 
    ll cnt = 0;
    for (int i = 0; i < m; i++)
    {
 
        // cout<<st.order_of_key(v[i]+d+1)<<" ";
        ll l, r, lf = 0, rf = 0;
        if (st.find(v[i] + d) == st.end())
        {
            rf = 1;
        }
 
        if (st.find(v[i] - d) == st.end())
        {
            lf = 1;
        }
        if (rf)
            st.insert(v[i] + d);
        if (lf)
            st.insert(v[i] - d);
        // cout<<lf<<" "<<rf<<" ";
        r = st.order_of_key(v[i] + d);
        l = st.order_of_key(v[i] - d);
        if (lf && rf && r - l > 1)
        {
            cnt++;
            // cout<<*st.find_by_order(l+1)<<" ";
            if (mp[*st.find_by_order(l + 1)] > 1)
                mp[*st.find_by_order(l + 1)]--;
            else
                st.erase(*st.find_by_order(l + 1));
        }
        else if (!lf)
        {
            // cout<<"lf ";
            cnt++;
            if (mp[*st.find_by_order(l)] > 1)
                mp[*st.find_by_order(l)]--;
            else
                st.erase(v[i] - d);
        }
        else if (!rf)
        {
            // cout<<"rf ";
            cnt++;
            if (mp[*st.find_by_order(l + 1)] > 1)
                mp[*st.find_by_order(l + 1)]--;
            else
                st.erase(*st.find_by_order(l + 1));
        }
        // cout << endl;
        if (rf == 1)
            st.erase(v[i] + d);
        if (lf == 1)
            st.erase(v[i] - d);
    }
    cout << cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
