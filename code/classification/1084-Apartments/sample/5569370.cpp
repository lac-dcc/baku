#include <bits/stdc++.h>
using namespace std;
#define fast cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
const int INF = 0x3f3f3f3f;
#define maxlen 250
//char alphapet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int N=1e5+1;
int main(){
    int n, m, k, ans;
 
 
        cin >> n >> m >> k;
       int a[n], b[m];
        for (int i = 0; i < n; ++i){
            cin >> a[i];
 
        }
 
 
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
 
        sort(a, a + n);
 
        sort(b, b + m);
 
        int i = 0, j = 0;
        while (i < n && j < m){
            // Found a suitable apartment for the applicant
            if (abs(a[i] - b[j]) <= k){
                ++i;
                ++j;
                ans++;
            }
            else{
                // If the desired apartment size of the applicant is too big,
                // move the apartment pointer to the right to find a bigger one
                if (a[i] - b[j] > k){
                    j++;
                }
                    // If the desired apartment size is too small,
                    // skip that applicant and move to the next person
                else{
                    i++;
                }
            }
        }
        cout << ans << "\n";
}