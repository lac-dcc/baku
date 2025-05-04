#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n ;
    cin >> n ;
 
    vector<int> uwu ;
 
    while (n--) {
        int a ;
        cin >> a ;
        uwu.push_back(a);
    }
 
    vector<int>A = uwu;
           sort(A.begin(),A.end());
           A.erase(unique(A.begin(),A.end()),A.end());
 
           cout << A.size() ;
 
}
