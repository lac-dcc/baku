#include<bits/stdc++.h>
using namespace std;
 
void printVector(vector<int> &v){
    if(v.size()){
        for(int i = 0; i<(int)v.size(); i++){
            cout<<v[i]<<" ";
        }
    }
    else{
        cout<<"\n";
    }
}
 
void printMatrix(vector<vector<int>> &v){
    if(v.size()){
        for(int i = 0; i<(int)v.size(); i++){
            cout<<"(";
            for(int j = 0; j < (int)v[0].size(); j++){
                cout<<v[i][j]<<" ";                
            }
            cout<<")";
        }
    }
    else{
        cout<<"\n";
    }
}
 
int main()
{
    //--------------- Input-output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);
    //--------------- Reading input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants, apartments;
 
    for(int i = 0; i < n; i++){
        int currentApplicant;
        cin >> currentApplicant;
        applicants.push_back(currentApplicant);
    }
    for(int i = 0; i < m; i++){
        int appSize;
        cin >> appSize;
        apartments.push_back(appSize);
    }
 
    //--------------- Sorting of applicants' desired sizes    
    sort(applicants.begin(), applicants.end());
    //--------------- Sorting of sizes
    sort(apartments.begin(), apartments.end());
 
    int applicantsIdx = 0, apartmentsIdx = 0, maxMatches = 0;
    while(applicantsIdx < n && apartmentsIdx < m){
        if(abs(applicants[applicantsIdx]-apartments[apartmentsIdx])<=k){
            applicantsIdx++;
            apartmentsIdx++;
            maxMatches++;
        }
        else if((applicants[applicantsIdx]-apartments[apartmentsIdx])>k){
            apartmentsIdx++;
        }
        else{
            applicantsIdx++;
        }
    }
 
    cout << maxMatches << "\n"; 
    return 0;
}