    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n, m;
        cin >> n >> m;
        multiset<int> s;
        int arr[m], x;
        for(int i = 0; i < n; i++) cin >> x, s.insert(x);
        for(int i = 0; i < m; i++) cin >> arr[i];
        for(int i = 0; i < m; i++){
            multiset<int>::iterator x = s.upper_bound(arr[i]);
            if(x != s.begin()) x--;
            if(s.size() == 0) cout << -1 << endl;
            else if(*x > arr[i]) cout << -1 << endl;
            else cout << *x << endl, s.erase(x);
        }
    }
