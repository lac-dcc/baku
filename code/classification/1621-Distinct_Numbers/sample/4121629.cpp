#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
        s.insert(ans[i]);
    }
 
    cout << s.size() << endl;
    return 0;
}