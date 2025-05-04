#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<pair<int,bool>> v;
    int x; int y;
    while(n--){
    	cin>>x>>y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	sort(v.begin(),v.end());
   	long long ans =0,maxx =0;
   	for(int i=0;i<v.size();i++){
   		if(v[i].second==true){
   			ans++;
   			maxx = max(ans,maxx);
   		}else{
   			ans--;
   		}
   	}
   	cout<<maxx<<endl;
return 0;
}
