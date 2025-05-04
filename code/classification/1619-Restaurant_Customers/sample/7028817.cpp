#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
 
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
 
template<class A> bool umin(A& a, const A& b) {
    return b<a?a=b, 1:0;
}
 
template<class A> bool umax(A& a, const A& b) {
    return a<b?a=b, 1:0;
}
 
template<class A> void print(A vect) {
    for (auto x:vect)
        cout << x << " ";
    cout << endl;
}
 
void print(int arr[], int sz) {
    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a, b;
    priority_queue<pair<int, int>> pq;
    while (n--) {
        cin >> a >> b;
        pq.push({a*-1, 1});
        pq.push({b*-1, -1});
    }
    int c = 0;
    int mass = 0;
    int last = 1;
    while (!pq.empty()) {
        auto [a, b] = pq.top();
        pq.pop();
        if (a != last) {
            mass = max(mass, c);
            last = a;
        }
        c += b;
    }
    mass = max(mass, c);
    cout << mass << endl;
 
    return 0;
}
