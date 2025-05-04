#include <bits/stdc++.h>
 
#define log(x) std::cout << #x"=" << x << std::endl
 
using namespace std;
 
int main() { 
    int n;
    cin >> n;
    vector<int> arrive(n, 0);
    vector<int> leave(n, 0);
 
    for (int i = 0; i < n; i++) { 
        cin >> arrive[i];
        cin >> leave[i];
    }
 
    sort(arrive.begin(), arrive.end());
    sort(leave.begin(), leave.end());
 
 
   int i = 0, j = 0;
   int total = 0;
   int ans = 0;
   while (i < n && j < n) { 
 
       if (arrive[i] < leave[j]) { 
           total += 1;
           i++;
       } else if (arrive[i] > leave[j]) {
           total -= 1;
           j++;
       } else { 
           i++;
           j++;
       }
       ans = max(ans, total);
 
   }
   cout << ans << endl;
}
