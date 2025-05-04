/*
    author:    Newplayers12
    created:   Sunday 07-08-2022  12:48:30
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
long long a[21];
long long b[21];
int main()
{
    fastio;
    int n;
    cin >> n;
    long long X;
    cin >> X;
    int half = n >> 1;
    int other = n - half;
    for(int i = 0; i < half; ++i) cin >> a[i];
    for(int i = 0; i < other; ++i) cin >> b[i];
    vector<long long> sA, sB;
    for(int i = 0; i < (1<<other); ++i){
        long long sum = 0;
        if (i < (1<<half)) {
            for(int j = 0; j < half; ++j){
                if ((i>>j) & 1){
                    sum += a[j];
                }
                if (sum > X) break;
            }
            if (sum <= X){
                sA.push_back(sum);
            }
        }
        sum = 0;
        for(int j = 0; j < other; ++j){
            if ((i>>j) & 1){
                sum += b[j];
            }
            if (sum > X) break;
        }
        if (sum <= X){
            sB.push_back(sum);
        }
    }   
    int h1, h2;
    sort(sA.begin(), sA.end());
    sort(sB.begin(), sB.end());
    h1 = 0;
    h2 = sB.size() - 1;
    long long ans = 0;
    while (h1 < sA.size() && h2 >= 0){
        if (sA[h1] + sB[h2] > X){
            --h2;
        } else if (sA[h1] + sB[h2] < X){
            ++h1;
        } else {
            long long n1, n2;
            n1 = n2 = 0;
            int temp = sA[h1];
            while (h1 < sA.size() && sA[h1] == temp) ++n1, ++h1;
            temp = sB[h2];
            while (h2 >= 0 && sB[h2] == temp) ++n2, --h2;
            ans += n1 * n2;
        }
    }
    cout << ans;
    return 0;
}
