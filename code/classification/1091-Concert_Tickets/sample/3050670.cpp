#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
 
using namespace std;
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        st.insert(a);
    }
    while(m--){
        int p;
        cin >> p;
        if(st.upper_bound(p) == st.begin()){
            cout << -1 << "\n";
        }
        else{
            cout << *prev(st.upper_bound(p)) << "\n";
            st.erase(prev(st.upper_bound(p)));
        }
    }
}
