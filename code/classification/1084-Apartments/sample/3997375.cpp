#include <bits/stdc++.h>
using namespace std;
 
int solve(int people[], int apart[], int n, int m, int k){
    int i=0, j=0, res = 0;
    while(i<n && j<m){
        if(abs(people[i] - apart[j])<=k){
            i++; j++;res++;
        }
        else if(people[i] > apart[j])
            j++;
        else 
            i++;
    }
    return res;
}
 
int main(){
    int n, m, k; 
    cin>>n>>m>>k;
    int people[n], apart[m];
    for(int i=0; i<n; i++) cin>>people[i];
    for(int i=0; i<m; i++) cin>>apart[i];
    sort(people, people+n);
    sort(apart, apart+m);
    cout<<solve(people, apart, n, m, k);
    
    return 0;
    
}