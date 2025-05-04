#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int N, n;
    long long int k;
    cin>>N;
    set<long long int> s;
    for(n=0; n<N; n++) {
        cin>>k;
        s.insert(k);
    }
    cout<<s.size();
    return 0;
}
