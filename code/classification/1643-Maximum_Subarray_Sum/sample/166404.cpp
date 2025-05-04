#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll N, sum = 0, maxsum = -1e12;
int main()
{
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        ll a;
        cin>>a;
        if(sum < 0)
            sum = a;
        else
            sum += a, maxsum = max(maxsum,sum);
        maxsum = max(a,maxsum);
    }
    cout<<maxsum<<endl;
}