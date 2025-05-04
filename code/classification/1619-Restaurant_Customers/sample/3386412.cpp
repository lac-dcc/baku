#include<bits/stdc++.h> 
#include <string>
using namespace std;
 
 
 
 
int main()
{
    int n;
    cin >> n;
    vector<int> now(n),leave(n);
    for(int i = 0; i< n; i++){
        cin >> now[i] >> leave[i];
    }
    sort(now.begin(),now.end());
    sort(leave.begin(),leave.end());
    int in1 = 0,in2 = 0;
    int current= 0,max = 0;
    while(in1 != n){
        if(now[in1] < leave[in2]){
            current+=1;
            in1+=1;
            if(current > max) max =current;
        }
        else if(now[in1] > leave[in2]){
            current-=1;
            in2++;
        }
        else{
            in2++;
            in1++;
        }
    }
    cout << max;
}
 
    
    
 
 
    
    
    
  
