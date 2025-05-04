#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;
int main()
{
    int n, x;
    cin>>n>>x;
    map<int, int>PosOfValue;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        if(PosOfValue.count(x-value))
        {
            cout<<i+1<<" "<<PosOfValue[x-value]<<endl;
            return 0;
        }
        PosOfValue[value] = i + 1;
    }
    cout<<"IMPOSSIBLE";
}
