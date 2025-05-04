#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n, target;
    cin >> n >> target;
    
    vector<pair<int,int>> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i+1;
    }
    sort(A.begin(), A.end());
 
    int p1 = 0, p2 = n - 1;
 
    while(p1 < p2) {
        int sum = A[p1].first + A[p2].first;
 
        if(sum == target) {
            cout << min(A[p1].second, A[p2].second) << " ";
            cout << max(A[p1].second, A[p2].second) << endl;
            return 0;
        }
        else if(sum > target) {
            p2--;
        }
        else {
            p1++;
        }
    }
    cout << "IMPOSSIBLE\n";
}