#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll r,c;
        cin>>r>>c;
        ll ans;
 
        if(r >= c){
            ans = (r-1)*1ll*(r-1);
            if(r%2 == 0){
                ans+= r + r - c;
            }else{
                ans+=c;
            }
        }else{
            ans = (c-1)*1ll*(c-1);
            if(c%2 == 0){
                ans += r;
            }else{
                ans += c+c-r;
            }
        }
 
        cout<<ans<<endl;
    }
    
    return 0;
}
