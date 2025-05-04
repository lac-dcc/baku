#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
 
int main()
{
    lli n,m;
    cin>>n>>m;
 
    multiset<lli> price;
    lli h,t;
    for(lli i=0;i<n;i++){
        cin>>h;
        price.insert(h);
    }
    for(lli i=0;i<m;i++){
        cin>>t;
        auto it=price.upper_bound(t);
        if(it==price.begin()){
            cout<<"-1\n";
        }
        else{
            cout<<*(--it)<<endl;
            price.erase(it);
        }
    }
    return 0;
}
