#include <bits/stdc++.h>
using namespace std;
 
void add(multiset<long long>& left, multiset<long long> &right, long long a, long long m, long long &sl, long long &sr) {
    if (left.size() < m) {
        left.insert(-a);
        sl += a;
    }
    else {
        long long b = *left.begin();
        left.erase(left.begin());
        b = - b;
        sl -= b;
        left.insert(-min(a, b));
        right.insert(max(a, b));
        sl += min(a, b);
        sr += max(a, b);
    }
}
 
void del(multiset<long long> & left, multiset<long long> &right, long long a, long long &sl, long long &sr) {
    if (right.find(a) != right.end()) {
        right.erase(right.find(a));
        sr -= a;
    }
    else {
        left.erase(left.find(-a));
        sl -= a;
        if (right.size() > 0) {
            long long b = *right.begin();
            right.erase(right.begin());
            sr -= b;
            left.insert(-b);
            sl += b;
        }
    }
}
 
bool comp(pair<int, int> & a, pair<int, int> &b) {
    return a.first < b.first;
}
 
int main() {
    long long n, k;
    cin >> n >> k;
    multiset<int> people;
    for (int i = 0; i < k; i ++) people.insert(0);
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i ++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), comp);
    int answer = 0;
    for (int i = 0; i < n; i ++) {
        pair<int, int> movie = movies[i];
        if (*people.begin() <= movie.first) {
            people.erase(people.begin());
            people.insert(movie.second);
            answer ++;
        }
        else if (*(--people.end()) > movie.second) {
            people.erase(--people.end());
            people.insert(movie.second);
        }
    }
    cout << answer;
}