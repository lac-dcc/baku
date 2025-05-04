#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for(int i = 0; i < n; i++){
        int ipt;
        cin >> ipt;
        h.insert(ipt);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        auto up = h.upper_bound(x);
        if(up != h.begin()){
            up--;
            cout << *up << endl;
            h.erase(up);
        }
        else{
            cout << -1 << endl;
        }
    }    
    return 0;
}
