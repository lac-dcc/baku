#include<bits/stdc++.h>
using namespace std;
int n;
set<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size();
}
