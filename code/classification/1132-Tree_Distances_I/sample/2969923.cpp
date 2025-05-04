#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
 
using namespace std;
 
 
void fast() {
    ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
vector<ll> primes;
void sieve(ll n) {
    //bool checkPrime[n + 1] = {0};
    vector<bool> checkPrime(n + 1, 0);
    checkPrime[0] = 1; checkPrime[1] = 1;
    for (ll i = 2; i * i <= n; i++) {if (checkPrime[i] == 0) {for (ll j = i * i; j <= n; j += i) {checkPrime[j] = 1;}}}
    for (ll i = 0; i <= n; i++) {if (checkPrime[i] == 0) primes.pb(i);}
}
ll gcd(ll a, ll b) {if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
 
vector<int> tree[200005];
vector<int> ans(200005);
vector<int> depth(200005);
 
void findDepth(int src, int par) {
 
    bool leaf = 1;
    int d = 0;
    for (auto x : tree[src]) {
        if (x != par) {
            leaf = 0;
            findDepth(x, src);
            d = max(d, depth[x]);
        }
    }
 
    if (leaf) {
        depth[src] = 0;
    }
    else {
        depth[src] = 1 + d;
    }
 
}
 
 
 
void solve(int src, int par, int premax) {
 
    bool leaf = 1;
 
    vector<int> prefix;
    vector<int> suffix;
 
    for (auto x : tree[src]) {
        if ( x != par) {
            leaf = 0;
            prefix.pb(depth[x]);
            suffix.pb(depth[x]);
        }
    }
 
    if (leaf) {
        ans[src] = 1 + premax;
        return;
    }
 
    for (int i = 1; i < prefix.size(); i++) {
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }
 
    for (int i = suffix.size() - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }
 
    int cnt = 0;
    for (auto x : tree[src]) {
        if (x != par) {
            int leftmax = (cnt == 0) ? INT_MIN : prefix[cnt - 1];
            int rightmax = (cnt == prefix.size() - 1) ? INT_MIN : suffix[cnt + 1];
 
            int partial_ans = 1 + max(premax, max(leftmax, rightmax));
 
 
            solve(x, src, partial_ans);
            cnt++;
        }
    }
 
 
    ans[src] = 1 + max(premax, prefix.back());
 
 
}
 
 
int main() {
 
    fast();
 
 
    int n;
    cin >> n;
 
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
 
    findDepth(1, 0);
 
    solve(1, 0, -1);
 
 
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}
