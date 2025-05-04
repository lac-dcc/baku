#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define all(x) x.begin(), x.end()
//fill(arrf.begin() + l-1, arrf.begin() + r, true);
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}
int sumOfDigits(string s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}
bool is_valid(ll x){
 
}
vector<string> vss;
unordered_map<int, int> mp1[6][6], mp2[6][6];
 
int psum(string &e, int L, int i) {
    int sum = 0;
    int k = (L + i) / 2;
 
    for (int j = 0; j < e.size(); j++)
        sum += (j < k) ? (e[j] - '0') : -(e[j] - '0');
 
    return sum;
}
 
int ssum(string &el, int i, int L) {
    int sum = 0;
    int k = (L + i) / 2;
 
    for (int j = 0; j < el.size(); j++)
        sum += (j + i >= k) ? -(el[j] - '0') : (el[j] - '0');
 
    return sum;
}
 
ll sum(vector<ll>&arr ,ll l,ll r){
    ll maxii=LLONG_MIN;ll sum=0;
    for (int i = l; i <= r-1; ++i) {
        sum+=arr[i];
        if(maxii<sum){
            maxii=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxii;
 
}
void GO() {
    int n,m,k;
    cin>>n>>m>>k;
    vi arrA(n);
    vi arrB(m);
    map<int,bool>vis;
    for (int i = 0; i < n; ++i) {
      cin>>arrA[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>arrB[i];
    }
    int ans=0;
    int i=0;
    int j=0;
    sort(all(arrA));
    sort(all(arrB));
 
    while (i<n && j<m){
            if(abs(arrA[i]-arrB[j])<=k){
//                vis[arrB[j]]=true;
                ans++;
                i++;
                j++;
            }else if(arrB[j]>arrA[i])i++;
            else j++;
 
    }
    cout<<ans;
 
}
 
int main() {
    fast;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    ll t=1;
//    cin>>t;
    while (t--) {
        GO();
    }
//if(is_prime(9679))cout<<"1";
    return 0;
}
