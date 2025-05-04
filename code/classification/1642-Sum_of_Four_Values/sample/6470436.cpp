#include<bits/stdc++.h>
// #define ul unsigned long
// #define long unsigned long long
#define endl '\n' 
using namespace std;
void o()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("test_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
void solve(long arr[], int n, long x){
    unordered_map<long, pair<int,int>> um;
    bool flag=true;
    for(int i=0; i<n; i++){
        for(int k=0; k<=(i-2); k++){
            um[arr[i-1]+arr[k]] = make_pair(i-1, k);
        }
        for(int j=i+1; j<n; j++){
            long curSum = arr[i]+arr[j];
            auto it = um.find(x-curSum);
            if(it!=um.end()){
                flag=false;
                cout<< (*it).second.first+1<<" "<<(*it).second.second+1<<" "<<i+1<<" "<<j+1<<'\n';
                break;
            }
        }
        if(flag==false){
            break;
        }
    }
    if(flag==true){
        cout<<"IMPOSSIBLE";
    }
}
 
int32_t main()
{
    o();
    int n; long x; cin>>n>>x;
    long arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    solve(arr,n,x);
 
    return 0;
}
