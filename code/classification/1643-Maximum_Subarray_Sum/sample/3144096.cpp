#include <bits/stdc++.h>
using namespace std;
const long long N=1e7+10;
vector<long long> a(N);
vector<long long> sum(N);
 
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long mx=INT_MIN,sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>mx) mx=sum;
        if(sum<0) sum=0;
    }
    cout << mx << "\n";
    return 0;
}
