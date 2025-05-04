/******************************************************************************
 
Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <bits/stdc++.h>
#define fi first
using namespace std;
 
int main(){
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int > > arr;
    for(int i=0;i<n;i++) {
        int ele;
        cin >> ele;
        arr.push_back({ele, i});
    }
    
    sort(arr.begin(), arr.end());
    
    // for(int i=0;i<n;i++){
    //     cout << arr[i].fi << " ";
    // }
    
    int i=0;
    int j=n-1;
    
    while(i < j){
        if(arr[i].fi + arr[j].fi == x) {
            cout << arr[i].second + 1 << " " << arr[j].second + 1 << endl;
            return 0;
        }
        else if(arr[i].fi + arr[j].fi > x) j--;
        else i++;
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    
    return 0;
}