#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
 
typedef pair<int,int> pii;
 
int main(){
 
    int n;
    cin >> n;
    vector<pii> customers(2*n);
    for(int i = 0 ; i < 2*n ; i++){
        cin >> customers[i].first;
        customers[i].second = i%2;
    }
    sort(customers.begin(),customers.end());
 
    int cur = 0;
    int max = 0;
    for(int i = 0 ; i < customers.size() ; i++){
        if(customers[i].second==0){
            ++cur;
            if(cur>max) max = cur;
        }
        else{
            --cur;
        }
    }
    cout << max << '\n';
}
