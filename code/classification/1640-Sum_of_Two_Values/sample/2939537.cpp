#include<bits/stdc++.h>
#define icantcode ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n,x;
int a[200005];
int b[200005];
int main(){
    icantcode
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    int l=1,r=n;
    while(r>l){
        if(b[l]+b[r] == x) break;
        else if(b[l]+b[r] > x) r--;
        else l++;
    }
    if(l>=r){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int ansl = -1,ansr = -1;
    for(int i=1;i<=n;i++){
        if(b[l] == a[i] && ansl == -1) ansl = i;
        else if(b[r] == a[i] && ansr == -1) ansr = i;
    }
    cout<< min(ansl,ansr) <<" "<< max(ansl,ansr);
    return 0;
}
