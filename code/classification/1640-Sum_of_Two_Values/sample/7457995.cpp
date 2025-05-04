#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main(){
 
    int n, target; cin >> n >> target;
    vector< pair<int,int> > numbers;
    for( int i = 0; i < n; i++){
        int number; cin >> number;
        numbers.push_back(make_pair(number,i+1));
    }
 
    bool found = false;
    sort(numbers.begin(), numbers.end());
    int left = 0, right = numbers.size()-1;
    while( left < right ){
        LL currentSum = numbers[left].first + numbers[right].first;
        if ( currentSum == target ){
            cout << min(numbers[left].second, numbers[right].second) << " " << max(numbers[left].second, numbers[right].second) << endl;
            found = true;
            break;
        }
        else if ( currentSum > target )
            right--;
        else
            left++;
    }
    if ( !found )
        cout << "IMPOSSIBLE" << endl;
 
    return 0;
}
