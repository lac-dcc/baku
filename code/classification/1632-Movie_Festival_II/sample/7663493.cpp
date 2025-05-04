#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
 
int main() {
    long long int n, m;
    cin >> n >> m;
    vector<pair< int, int>> movie;
 
    for (int i = 0; i != n; i++) {
         int s, f;
        cin >> s >> f;
        movie.push_back(std::make_pair(f, s));
    }
    sort(movie.begin(), movie.end());
    int count = 0;
    multiset<int> end;  
    for (int i = 0; i!=m; i++) end.insert(0);
    for (int i = 0; i != n; i++) {
        auto it = end.upper_bound(movie[i].second);
        if (it == end.begin()) {
            continue;
        }
        end.erase(--it);
        end.insert(movie[i].first);
        count++;
    }
    cout << count << '\n';
    return 0;
}
