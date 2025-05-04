#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f freopen
#define endl '\n'
using namespace std;
const ll N=44;
ll a[N],n,sum;
vector <ll> vecx,vecy;
void duyetx(ll i,ll x) {
    if (x>sum) {
        return;
    }
    if (i >n/2) {
        vecx.pb(x);
    }
    else {
        duyetx(i+1,x);
        duyetx(i+1,x+a[i]);
    }
}
void duyety(ll i,ll x) {
    if (x>sum) return;
    if (i>n) {
        vecy.pb(x);
    }
    else {
        duyety(i+1,x);
        duyety(i+1,x+a[i]);
    }
}
signed main()
{
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n>>sum;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    duyetx(1,0);
    duyety(n/2+1,0);
    sort(vecy.begin(),vecy.end());
    ll cnt=0;
    for (ll x: vecx) {
        vector <ll> ::iterator it1,it2;
        it1=upper_bound(vecy.begin(),vecy.end(),sum-x);
        it2=lower_bound(vecy.begin(),vecy.end(),sum-x);
 
        cnt+=(it1-vecy.begin())-(it2-vecy.begin());
    ///    cout<<cnt<<endl;
    }
    cout<<cnt;
}
 
/*
#include <bits/stdc++.h>
#define f freopen
using namespace std;
const int N = 40 + 2;
int n, x;
int t[N];
vector<int> A, B;
 
void TryX(int i, int sum) {
    if (sum > x) return;
 
    if (i > n / 2) A.push_back(sum);
    else {
        TryX(i + 1, sum);
        TryX(i + 1, sum + t[i]);
    }
}
void TryY(int i, int sum) {
    if (sum > x) return;
 
    if (i > n) B.push_back(sum);
    else {
        TryY(i + 1, sum);
        TryY(i + 1, sum + t[i]);
    }
}
 
int main() {
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> t[i];
 
    // Quay lui 2 tập X và Y
    TryX(1, 0);
    TryY(n / 2 + 1, 0);
 
    // Sắp xếp mảng B
    sort(B.begin(), B.end());
 
    // Lặp qua mảng A và tìm kiếm nhị phân:
    // - Đếm số lượng phần tử trong B có giá trị bằng x - A[i]
    long long cnt = 0;
    for (int sum : A) {
        cnt += upper_bound(B.begin(), B.end(), x - sum)
             - lower_bound(B.begin(), B.end(), x - sum);
    }
    cout << cnt << '\n';
}
*/
