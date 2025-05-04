#include <iostream>
#include <algorithm>
#include <map>
 
const bool debug = false;
 
using namespace std;
 
void setI(string filename) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(filename.c_str(), "r", stdin);
    //freopen(filename.c_str(), "w", stdout);
}
 
void setO(string filename) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(filename.c_str(), "r", stdin);
    freopen(filename.c_str(), "w", stdout);
}
int a,k,b;
 
//int apartments[200000];
map<int,int> apartments;
pair<int,int> desired[200000];
int counter=0;
 
int main() {
    if (debug) {
        setI("test.txt");
    }
    cin>>a>>b>>k;
    for(int i=0;i<a;i++){
        int x;
        cin>>x;
        desired[i]={x+k,x-k};
    }
    sort(desired,desired+a);
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        apartments[x]++;
    }
//    sort(desired,desired+a);
    for(int i=0;i<a;i++){
        auto apartment=apartments.lower_bound(desired[i].second);
        if(apartment==apartments.end()){
            continue;
        }
        if(apartment->first<=desired[i].first){
            apartment->second--;
            counter++;
            if(apartment->second==0){
                apartments.erase(apartment);
            }
        }
    }
    cout<<counter<<"\n";
}