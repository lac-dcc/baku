#include <bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
const int N = 2e5 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     
        int ap, appart, k; 
        cin>>ap>>appart>>k;
        int req[ap]; 
        for(int i = 0; i<ap; i++)
        {
         cin>>req[i];
        }
          int a[appart]; 
        for(int i = 0; i<appart; i++)
        {
         cin>>a[i];
        }
 
sort(
    req, req+ap
);
 
sort(
    a, a+appart
);int ans = 0; 
int  i = 0; int j  = 0; 
while(i < ap && j < appart){
if(abs(req[i] - a[j]) <=k){
    i++; j++; ans++; 
}
else if(req[i] >a[j])j++;
else i++; 
 
 
 
 
}
 
    cout<<ans<<endl;     
 
 
 
 
 
    return 0;
}
