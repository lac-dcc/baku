#include <bits/stdc++.h>
 
using namespace std;
 
 
int src(vector<int> &arr, int k){
    int l = 0;
    int r = arr.size() - 1;
    int mid;
    while(l < r){
        mid = r - (r-l)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[mid] > k){
            r = mid -1;
        }
        else{
            l = mid;
        }
    }
    if(arr[r] <= k){
        return r;
    }
 
    return l;
}
 
int main() {
    
    
    int n,m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        ms.insert(z);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        auto it = ms.upper_bound(t);
        if(it == ms.begin()){
            cout<<-1<<endl;
        }
        else{
            cout<<*(--it)<<endl;
            ms.erase(it);
        }
    }
    
    
    
    
    
    
    return 0;
}
