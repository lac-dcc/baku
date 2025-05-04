#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli n, m, k;
    cin>>n>>m>>k;
    vector<lli> desired(n);
    vector<lli> available(m);
    for(lli i=0;i<n;i++)
        cin>>desired[i];
    for(lli i=0;i<m;i++)
        cin>>available[i];
    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());
    lli ans=0, i=desired.size()-1, j=available.size()-1;
    while(i>=0 and j>=0){
        if(abs(desired[i]-available[j])<=k){
            ans++;
            j-=1;
            i-=1;
        }
        else if(desired[i]>available[j])
            i-=1;
        else
            j-=1;
    }
    cout<<ans<<"\n";
    return 0;
}
