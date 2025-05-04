#include<bits/stdc++.h>
 
 
using namespace std;
 
vector<vector<long long > > T;
vector<long long> si;
vector<bool> V;
 
long long dfs(long long l){
    if(T[l].size()==0){
        si[l]=0;
        V[l]=true;
        return 1;
 
    }
    else{
        long long sum=0;
        for(auto e:T[l]){
            if(V[e]==true)
                sum+=si[e];
            else
                sum+=dfs(e);
        }
        si[l]=sum;
        V[l]=true;
        return sum+1;
    }
 
}
 
 
int main(){
    long long N,temp;
    cin>>N;
    T.resize(N);
    si.resize(N);
    V.resize(N);
    for(long long n=0;n<N-1;n++){
        cin>>temp;
        T[temp-1].push_back(n+1);
 
    }
 
 
 
 
    for(long long i=0;i<N;i++){
        if(V[i]==false){
           dfs(i);
 
        }
    }
 
 for(auto x:si){
   cout<<x<<" ";
 }
 
 
}
