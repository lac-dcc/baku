#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
    long long n,count=1;
    cin >> n;
    vector <long long> g(n);
    for (int i=0;i<n;i++){
        cin >> g[i];
    }
    sort(g.begin(),g.end());
    for (int i=1;i<n;i++){
        if (g[i]!=g[i-1]){
            count++;
        }
    }
    cout << count;
}
 