#include <iostream>
#include <vector>
#include <functional>
 
using namespace std;
 
vector<int> suboardinates(vector<int>& parents)
{
    function<void(vector<vector<int>>&, int, vector<int>&)> size = [&size](vector<vector<int>>& tree, int node, vector<int>& out)
    {
        for(auto child : tree[node])
        {
            size(tree, child, out);
            out[node] += 1 + out[child];
        }
    };
 
    int n = parents.size();
    vector<vector<int>> tree(n, vector<int>());
    for(auto i = 1; i < n; i++)
    {
        tree[parents[i]].push_back(i);
    }
    vector<int> ans(n, 0);
    size(tree, 0, ans);
    return ans;
}
 
int main() {
    int n;
    cin >> n;
    int parent;
    vector<int> parents {-1};
    for(int i = 0; i < n - 1; i++)
    {
        cin >> parent;
        parents.push_back(parent - 1);
    }
    for(auto i : suboardinates(parents))
    {
        cout << i << endl;
    }
    return 0;
}
