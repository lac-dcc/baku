//
// Created by Kyle Zhou on 6/9/21.
//
 
 
#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define rep(i,a,b) for(int i = a; i < (b); i++)
#define trav(a, x) for(auto &a: x)
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
 
//short hand for usual tokens
#define pb push_back
#define f first
#define s second
 
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define sz(a) int((a).size())
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
 
 
int N, x;
vector<int> coins;
ll dp[10000000];
 
 
 
int main() {
 
    cin >> N >> x;
    coins.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
 
    for(int i = 0; i <= x; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for1(i, N){
        for(int weight = 0; weight <= x; weight++){
            if(weight - coins[i - 1] >= 0){
                dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
    return 0;
 
 
}