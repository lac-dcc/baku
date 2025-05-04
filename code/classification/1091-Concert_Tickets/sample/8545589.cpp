#include <bits/stdc++.h>
#define WhyAreWeHere ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=2e5+1;
int main() {
    WhyAreWeHere;
    int n,k;
    cin>>n>>k;
    int b;
    multiset<int>a;
    for (int i = 0; i < n; ++i) {
        cin>>b;
        a.insert(b);
    }
    for (int i = 0; i < k; ++i) {
        cin>>b;
        auto it = a.upper_bound(b);
        if(it == a.begin())
            cout<<-1<<endl;
        else {
            cout<<*(--it)<<endl;
            a.erase(it);
        }
    }
    return 0;
}
