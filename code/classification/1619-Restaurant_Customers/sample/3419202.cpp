// Example program
#include <bits/stdc++.h>
using namespace std;
vector<int> in,out;
int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        in.push_back(x);
        out.push_back(y);
    }
    sort(in.begin(),in.end());
    sort(out.begin(),out.end());
    int MAX=0, cur=0, i=0, j=0;
    while(j<out.size() and i<in.size()){
        if(in[i]<out[j]){
            cur++;
            MAX=max(cur,MAX);
            i++;
        }
        else if(in[i]>out[j]){
            cur--;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    cout << MAX;
}
