#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define ll long long int
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n, x;
    cin >> n >> x;
 
    map<ll, ll> m;
    map<ll, set<ll>> indices;
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
 
        auto q = m.find(a);
        auto jt = indices.find(a);
        if (q == m.end())
        {
            m.insert({a, 1});
        }
        else
        {
            q->second++;
        }
        indices[a].insert(i + 1);
    }
 
    bool flag = false;
    ll temp1 = 0, temp2 = 0;
    for (auto it : s)
    {
 
        ll temp = x - it;
        if (s.count(temp) != 0)
        {
            if (temp != it)
            {
                flag = true;
                auto ind1 = indices.find(it);
                auto firstone = ind1->second.begin();
                auto ind2 = indices.find(temp);
                auto secondone = ind2->second.begin();
                temp1 = *firstone;
                temp2 = *secondone;
            }
            else
            {
                auto q = m.find(temp);
                if (q->second > 1)
                {
                    flag = true;
                    auto ind1 = indices.find(it);
                    auto firstone = ind1->second.begin();
                    auto secondone = ind1->second.begin();
                    secondone++;
                    temp1 = *firstone;
                    temp2 = *secondone;
                }
            }
        }
    }
 
    if (flag)
    {
        cout << temp1 << " " << temp2 << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE"
             << "\n";
    }
}
