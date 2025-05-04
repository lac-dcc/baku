// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
 
// int main() {
//     // ifstream fin("input.in");
//     // ofstream fout("output.out");
//     ll n, k;
//     cin >> n >> k;
//     multiset<pair<ll, ll>> movies;
//     for (ll i = 0; i < n; i++) {
//         pair<ll, ll> p;
//         cin >> p.second >> p.first;
//         movies.insert(p);
//     }
//     ll ans = 0;
//     for (ll i = 0; i < k; i++) {
//         ll idx = 0;
//         ll lastTime = 0;
//         multiset<pair<ll, ll>>::iterator it = movies.begin();
//         // cout << "new\n";
//         while (idx < movies.size()) {
//             // for (pair<int, int> p : movies) {
//             //     cout << "(" << p.first << ", " << p.second << ") ";
//             // }
//             // cout << "\n";
//             // cout << "ans: " << ans << "\n";
//             // cout << "idx: " << idx << "\n";
//             // cout << (*it).second << ", " <<(*it).first << "\n";
//             if ((*it).second >= lastTime) {
//                 ans++;
//                 lastTime = (*it).first;
//                 multiset<pair<ll,ll>>::iterator newIt = next(it,1);
//                 movies.erase(it);
//                 it=newIt;
//                 // cout<<"yes\n";
//             } else {
//                 idx++;
//                 it = next(it, 1);
//                 // cout << "no\n";
//             }
//             // if(it != movies.)
//             // cout << "\n";
//         }
//     }
//     cout << ans;
// }
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;
    sort(movies.begin(),movies.end());
    multiset<int> endTimes;
    for (int i = 0; i < k; i++)
        endTimes.insert(0);
    
    int ans=0;
    for(int i=0; i<n; i++) {
        pair<int,int>movie = movies[i];
        int startTime = movie.second;
        auto it = endTimes.upper_bound(startTime);
        if(it!=endTimes.begin()) {
            endTimes.erase(prev(it));
            endTimes.insert(movie.first);
            ans++;
        }
    }
    cout << ans;
 
}
