#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    ll x[n];
    ll curr_max_sum=-999999999999999999;
    ll max_ending_here=0;
    bool isallnegative=true;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        if(x[i]>0)
        {
            isallnegative=false;
        }
    }
    if(isallnegative)
    {
        sort(x,x+n);
        cout<<x[n-1];
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            max_ending_here+=x[i];
            if(max_ending_here<0)
            {
                max_ending_here=0;
            }
            else if(curr_max_sum<max_ending_here)
            {
                curr_max_sum=max_ending_here;
            }
        }
        cout<<curr_max_sum;
    }
}
