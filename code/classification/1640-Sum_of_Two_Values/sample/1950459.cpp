#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;
 
int main(){
 
    vector< pair<int,int> > lst;
    int s,tg;
    cin >> s>>tg;
    lst.resize(s);
    for(int i = 0 ; i < s ; i++){
        cin>>lst.at(i).first;
        lst.at(i).second=i;
    }
    sort(lst.begin(),lst.end());
    int p1 = 0;
    int p2 = s-1;
    bool chk = 0;
    while(p1!=p2){
        int j = lst.at(p1).first+lst.at(p2).first;
        if(tg==j){
            cout << lst.at(p1).second+1 <<' ' << lst.at(p2).second+1;
            chk = 1;
            break;
        }
        else if(tg>j){p1++;}
        else{p2--;}
    }
    if(chk==0){cout<<"IMPOSSIBLE";}
    return 0;
}
