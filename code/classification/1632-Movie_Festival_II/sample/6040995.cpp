#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#define ll long long int
 
using namespace std;
 
class T
{
public:
    ll p, q;
};
 
bool sortby(const T &a, const T &b)
{
    if (a.q < b.q)
        return (true);
    else if (a.q == b.q)
        return (a.p < b.p);
    return (false);
}
 
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<T> A;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        A.push_back({a, b});
    }
    sort(A.begin(), A.end(), sortby);
    multiset<ll> M;
    for (ll i = 0; i < k; i++)
    {
        M.insert(0);
    }
    ll c = 0;
    for (ll i = 0; i < n; i++)
    {
        ll start = A[i].p;
        auto ptr = M.upper_bound(start);
        if (ptr != M.begin())
        {
            ptr--;
            c++;
            M.erase(ptr);
            M.insert(A[i].q);
        }
    }
    cout << c << endl;
}