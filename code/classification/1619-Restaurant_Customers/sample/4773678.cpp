#include<bits/stdc++.h>
using namespace std;
  int main() {
    int n;
    cin >> n;
    vector <pair<int, int> > times;
    for (int i=0; i<n; i++)
    {
        int start, end;
        cin >> start >> end;
        times.push_back({start, 1});
        times.push_back({end, -1});
        }
        sort(times.begin(), times.end());
        int currpp=0, maxpp=0;
        for (const pair<int, int> &t : times)
        {
            currpp+=t.second;
            maxpp=max(currpp, maxpp);
    }
    cout<<maxpp<<endl;
 
    }
