//rect0r's yard
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S secoond
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef float ft;
typedef double db;
 
void solve() {
    ll r,c;
    cin >> r >> c;
    ll ans=0,p;
    if(r==c){
        ans=r*r-r+1;
    } else {
        p=max(r,c);
        if(p==r){
            if(r%2==0){
                ans=r*r-c+1;
            } else {
                ans=(r-1)*(r-1)+c;
            }
        } else if(p==c){
            if(c%2==0){
                ans=(c-1)*(c-1)+r;
            } else {
                ans=c*c -r +1;
            }
        }
    }
    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    //T = 1;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
