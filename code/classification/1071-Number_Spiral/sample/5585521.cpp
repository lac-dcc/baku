#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long i,j,t;
    cin >> t;
    vector<long long> v(t);
 
    for(int k = 0; k < t; ++k)
    {
        cin >> i >> j;
 
        if(i == 1LL)
        {
            if(j%2 == 1LL)
                v[k] = (long long)(pow(j,2));
            else
                v[k] = (long long)(pow(j-1,2)+1);
        }
 
        else if(i%2 == 0LL)
        {
            if(j <= i)
                v[k] = (long long)( (i*i) - (j-1) );
            else if(j%2 == 0LL)
                v[k] = (long long)((j-1)*(j-1)+i);
            else
                v[k] = (long long)((j*j)-(i-1));
        }
 
        else
        {
            if(j <= i)
                v[k] = (long long)((i-1)*(i-1)+j);
            else if(j%2 == 0LL)
                v[k] = (long long)((j-1)*(j-1)+i);
            else
                v[k] = (long long)((j*j)-(i-1));
        }
    }
 
    for(int k = 0; k < t; ++k)
        cout << ::fixed << (long long)(v[k]) << "\n";
 
    return 0;
}
