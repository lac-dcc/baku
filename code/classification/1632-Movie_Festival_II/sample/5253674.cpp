#include <bits/stdc++.h>
 
using namespace std;
 
 
#define A first
#define B second
#define MP make_pair
#define ms(a, x) memset(a, x, sizeof(a)) 
 
 
#define boost() ios_base::sync_with_stdio(false); cin.tie(); cout.tie()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
 
const int mxN=2e5+5;
 
 
int main(){
    int n, m;
    cin >> n >> m;
    vector <pii> v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(MP(y, x));
    }
    sort(v.begin(), v.end());
    multiset <int> s;
    int cnt=0;
    for(int i=0; i<n; i++){
        auto itr = s.upper_bound(v[i].B);
        if(itr != s.begin() && !s.empty()){
            --itr;
            s.erase(itr);
            s.insert(v[i].A);
            cnt++;
        }
        else{
            if(s.size() < m){
                s.insert(v[i].A);
                cnt++;
            }
        }
    }
    cout << cnt;
}