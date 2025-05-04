#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
long long bit [400000];
int lowbit(int x){
    return x & -x;
}
void mod(int pos, long long val){
    while(pos < 400000){
        bit[pos] = max(bit[pos], val);
        pos += lowbit(pos);
    }
}
long long query(int pos){
    long long maxv = 0;
    while(pos != 0){
        maxv = max(bit[pos], maxv);
        pos -= lowbit(pos);
    }
    return maxv;
}
int main() {
    int n;
    cin >> n;
    vector <pair<int,int>> desc;
    int value [n];
    for(int i = 0; i < n; i++){
        int a,b,p;
        cin >> a >> b >> p;
        desc.push_back(make_pair(a,i));
        desc.push_back(make_pair(b,i+n));
        value[i] = p;
    }
    sort(desc.begin(), desc.end());
    pair<pair<int,int>,int> projects [n];
    for(int i = 0; i < 2*n; i++){
        if(desc[i].second < n){
            projects[desc[i].second].first.first = i+1;
        }else{
            projects[desc[i].second-n].first.second = i+1;
        }
    }
    for(int i = 0; i < n; i++){
        projects[i].second = value[i];
    }
    sort(projects, projects+n);
    long long mv = 0;
    for(int i = 0; i < n; i++){
        long long x = query(projects[i].first.first) + projects[i].second;
        mv = max(mv,x);
        mod(projects[i].first.second, x);   
    }
    cout << mv << endl;
}
