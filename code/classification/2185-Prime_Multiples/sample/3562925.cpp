#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}
template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}
void printArr(vector<vector<int>> &arr) {
    for (auto &x: arr) {
        for (auto y: x) cout << y << " ";
        cout << endl;
    }
    cout << "===" << endl;
}
vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}
vector<string> splitWord(string s, string delimiter) {
    size_t pos = 0;
    std::string token;
    vector<string> ans;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        ans.emplace_back(token);
        s.erase(0, pos + delimiter.length());
    }
    ans.emplace_back(s);
    return ans;
}
#define ll long long
ll mpow(long long x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
 
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
 
 
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl
#define pi pair<int, int>
#define ll long long
 
int rev(int num) {
    int res = 0;
    while (num > 0) {
        res = (res * 10) + (num % 10);
        num /= 10;
    }
    return res;
}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        ll MOD = 1e9 + 7;
        ll ans = 0;
        map<ll, ll> cnt;
        for (int i = 0; i < n; i++) {
            ll rs = (ll)nums[i] - rev(nums[i]);
            ans = (ans + cnt[rs]) % MOD;
            cnt[rs]++;
        }
        return ans;
    }
};
 
 
int main() {
//    ifstream cin("../test_input.txt");
    fastInputOutput();
 
    ll num, n;
    cin >> num >> n;
    vector<ll> primes(n);
    for (int i = 0; i < n; i++) cin >> primes[i];
 
    ll ans = 0;
    ll limit = 1 << n;
    vector<ll> counts(n + 1);
    for (int mask = 1; mask < limit; mask++) {
        ll cnt = 0;
        ll temp = num;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0)continue;
            cnt++;
            temp = temp / primes[i];
        }
        counts[cnt] += temp;
    }
    for (int i = 0; i < n + 1; i++) {
        if (i % 2 == 1) ans += counts[i];
        else ans -= counts[i];
    }
    print(ans);
 
 
    return 0;
}