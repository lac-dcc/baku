#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
using ll = long long;
 
 
void sksolve()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i=0; i< n; i++){
        cin>>a[i];
    }
    for(int i=0; i< m; i++){
        cin>>b[i];
    }
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    int count=0;
    int i=0, j=0;
    while(i<n && j<m){
        if(a[i]+k>= b[j] && a[i]-k<= b[j]){
            count++;
            i++;
            j++;
        }
        else if(a[i]+k< b[j]){
            i++;
        }
        else if(a[i]-k> b[j]){
            j++;
        }
    }
    cout<<count<<endl;
}
int32_t main()
 
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        sksolve();
    // }
    return 0;
}