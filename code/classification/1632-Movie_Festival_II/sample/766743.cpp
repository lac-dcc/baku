#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	array<int,3>a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][1]>>a[i][0];
        a[i][2] = i;
    }
    sort(a,a+n);
    set<array<ll,2>>s;
    int pp[n];
    int ans2=0;
    for(int i=0;i<n;i++)
    {
            auto lower = s.lower_bound({a[i][1]+1});
            if(lower != s.begin())
            {
                --lower;
                pp[a[i][2]] = (*lower)[1];
                s.erase(lower);
            }
            else
            {
                pp[a[i][2]] = s.size();
            }
            if(s.size()<k){
                s.insert({a[i][0],pp[a[i][2]]});
                ++ans2;
            }
    }
    cout<<ans2<<endl;
}
