#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int>a(n / 2), b(n - n / 2);
    for(int i = 0;i < n / 2;++i){
        cin >> a[i];
    }
    for(int i = n / 2;i < n;++i){
        cin >> b[i - n / 2];
    }
    vector<long long>a1, b1;
    int sz = n / 2;
    for(int i = 0;i < (1 << (sz));++i){
        long long sum = 0;
        for(int j = 0;j < sz;++j){
            if(i & (1 << j))sum += a[j];
        }
        a1.push_back(sum);
    }
    sz = n - sz;
    for(int i = 0;i < (1 << (sz));++i){
        long long sum = 0;
        for(int j = 0;j < sz;++j){
            if(i & (1 << j))sum += b[j];
        }
        b1.push_back(sum);
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
//    cout << a1.size() << " " << b1.size();
    long long cnt = 0;
    for(int i = 0;i < a1.size();++i){
        auto itrU = upper_bound(b1.begin(), b1.end(), x - a1[i]);
        auto itrL = lower_bound(b1.begin(), b1.end(), x - a1[i]);
        cnt += (itrU - itrL);
    }
    cout << cnt;
}
