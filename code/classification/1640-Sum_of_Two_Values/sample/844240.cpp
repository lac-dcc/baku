#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    int data;
    for(int i=0 ; i < n; i++){
        cin >> data;
        a[i].first = data;
        a[i].second = i+1;        
    }
    sort(a.begin(), a.end());
    int sum = a[0].first+a[n-1].first;
    int i = 0, j = n-1;
    while(sum!=x && i<j){
        if(sum < x){
            i++;
        }
        else{
            j--;
        }
        sum = a[i].first+a[j].first;
    }
    if(i>=j){
        cout << "IMPOSSIBLE" << "\n";
    }
    else
    cout << a[i].second << " " << a[j].second << "\n";
    return 0;
}
