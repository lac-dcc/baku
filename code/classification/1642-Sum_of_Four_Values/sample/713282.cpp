#include <bits/stdc++.h>
 
#define Forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, c) for(auto e:c)
 
#define ar array
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000007;
 
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
ll n, x;
ar<ll, 2> arr[1010];
 
int main() {
    fast();
 
    cin >> n >> x;
    For (i, n) {
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }
    sort(arr, arr + n);
 
    For (i, n) {
        for (int j = i + 1; j < n; j++) {
            int l = j + 1, r = n - 1;
            while (l < r) {
                ll sum = arr[i][0] + arr[j][0] + arr[l][0] + arr[r][0];
                if (sum == x) {
                    cout << arr[i][1] << ' ' << arr[j][1] << ' ' << arr[l][1] << ' ' << arr[r][1] << '\n';
                    return 0;
                }
                if (sum < x) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
 
    cout << "IMPOSSIBLE\n";
 
    return 0;
}
