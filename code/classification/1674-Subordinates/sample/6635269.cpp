#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int> > v(202010);
vector<int> sizes(200010);
 
int subordinates(int employee)
{
    if(v[employee].size() == 0)
        return 1;
    for(int i = 0; i < v[employee].size(); i++)
        sizes[employee] += subordinates(v[employee][i]);
    return sizes[employee] + 1;
}
 
int main(void)
{
    int n, parent;
 
    cin >> n;
 
    for(int i = 2; i <= n; i++) {
        cin >> parent;
        v[parent].push_back(i);
    }
 
    subordinates(1);
 
    for(int i = 1; i <= n; i++)
        cout << sizes[i] << ' ';
 
    return 0;
}
