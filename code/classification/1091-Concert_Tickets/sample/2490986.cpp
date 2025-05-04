#include <bits/stdc++.h>
using namespace std;
 
#define all(x) (x).begin(), (x).end()
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<int> prices(n);
    for (auto& it: prices) cin >> it;
    vector<int> max_prices(m);
    for (auto& it: max_prices) cin >> it;
 
    multiset<int> s(all(prices));
    for (auto customer : max_prices)
    {
        if (s.empty())
        {
            cout << -1 << endl;
            continue;
        }
        /*
        for (auto p : prices)
        {
            cout << p << " ";
        }
        cout << endl;
        */
        // this is the most I will pay for a ticket
        // find me a ticket that is less than this max price
        //
        // ticket <= max_price
        // max_price is an upperbound of ticket
        
        // subtract one so now I'm finding cust - 1 < cust <= upper_bound
        //                                 
        auto it = s.upper_bound(customer - 1);
        if (it == s.end())
        {
            if (it == s.begin())
            {
                cout << -1 << endl;
                continue;
            }
            it = prev(it);
        }
        // cout << "cus: " << customer << endl;
        // cout << "ub: " << *it << endl;
        // cout << "d1" << endl;
        if (*it <= customer)
        {
            cout << *it << endl;
            // cout << distance(s.begin(), it) << endl;
            // assert(it != s.end());
            s.erase(it);
            // cout << "d1 done" << endl;
            continue;
        }
 
        // cout << "d2" << endl;
        if (it == s.begin())
        {
            cout << -1 << endl;
            continue;
        }
        // if ~it~ is the first value greater than val,
        // then --it is the greatest value <= val;
        // cout << "d3" << endl;
        it--;
        cout << *it << endl;
        s.erase(it);
    }
}
