#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define ull unsigned long
unsigned long long int fastspcexp(unsigned long long int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return (((fastspcexp(n / 2)) * (fastspcexp(n / 2))) % 1000000007);
    else
        return ((((fastspcexp(n / 2)) * (fastspcexp(n / 2)) * 2) % 1000000007));
}
vector<ull> fact(ull n)
{
    vector<ull> res;
    res.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        ull carry = 0;
        for (int j = 0; j < res.size(); j++)
        {
            ull val = res[j] * i + carry;
            res[j] = val % 10;
            carry = val / 10;
        }
        while (carry != 0)
        {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
vector<vector<ll>> subsetsgeneration(vector<ll> &inp, ll &n)
{
    vector<vector<ll>> subsets;
    ll subset_ct = (1 << n);
    for (int mask = 0; mask < subset_ct; mask++)
    {
        vector<ll> subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
                subset.push_back(inp[i]);
        }
        subsets.push_back(subset);
    }
    return subsets;
}
// set a i'th bit  then or the given number with (1<<i) and to unset it again and it with complement of ~(1<<i)
//  and to toggle the bit xor it with (1<<i)
// a+b = a^b + 2*(a&b)
// from multiple of 4 to next 4 cons numbers xor would be zero
void binary(ll num)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
}
int main()
{
 
    ll t;
    cin >> t;
    set<int> s;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}