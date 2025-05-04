#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int>nums;
    vector<int>nums2;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        nums.push_back(aux);
        nums2.push_back(aux);
    }
    sort(nums.begin(), nums.end());
    int cor1 = 0, cor2 = 0, fin1 = 0, fin2 = 0;
    int ini = 0, fim = n - 1;
    while(ini != fim){
        if(nums[ini] + nums[fim] == x){
            cor1 = nums[ini];
            cor2 = nums[fim];
            break;
        } else if(nums[ini] + nums[fim] < x){
            ini++;
        } else{
            fim--;
        }
    }
    if(cor1 == 0 || cor2 == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(cont == 0){
            if(nums2[i] == cor1 || nums2[i] == cor2){
                fin1 = i;
                cont++;
            }
        } else{
            if(nums2[i] == cor1 || nums2[i] == cor2){
                fin2 = i;
                break;
            }
        }
    }
    cout << fin1 + 1 << " " << fin2 + 1 << endl;
    return 0;
 
}