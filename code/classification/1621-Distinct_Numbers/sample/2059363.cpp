#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <list>
using namespace std;
 
#define psb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<long long, long long>
#define pl pair<long double, long double>
#define int long long
#define dd double double
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define len length()
#define sp " "
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    sort(a.begin(), a.end());
 
    int cnt = 1;
    for(int i = 1; i < n; i++)
        if(a[i] != a[i - 1])
            cnt++;
 
    cout << cnt;
    return 0;
}