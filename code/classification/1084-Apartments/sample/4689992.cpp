#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<queue>
#include<map>
#include<set>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int people, apts, k;
    cin>>people>>apts>>k;
 
    vector<int> v1(people), v2(apts);
    for(int i=0; i<people; i++) {
        cin>>v1[i];
    }
    for(int i=0; i<apts; i++) {
        cin>>v2[i];
    }
 
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
 
    int ans = 0;
    int i = 0, j = 0;
    while(i < people && j < apts) {
        if(abs(v1[i] - v2[j]) <= k) {
            ans++;
            i++;
            j++;
        }
        else if(v1[i] - v2[j] > k) {
            j++;
        }
        else {
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
