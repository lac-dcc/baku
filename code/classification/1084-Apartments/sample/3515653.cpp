#include<iostream>
#include<algorithm>
using namespace std;
 
int main(){
    int manyppl,manybuilding,candiff,count=0;
    cin>>manyppl>>manybuilding>>candiff;
    int ppllist[manyppl],buildlist[manybuilding];
    for(int i=0;i<manyppl;i++){
        cin>>ppllist[i];
    }
    for(int i=0;i<manybuilding;i++){
        cin>>buildlist[i];
    }
    sort(ppllist,ppllist+manyppl);
    sort(buildlist,buildlist+manybuilding);
    int pointppl=0,pointbuild=0;
    while(pointppl<manyppl&&pointbuild<manybuilding){
        if(abs(ppllist[pointppl]-buildlist[pointbuild])<=candiff){
            count++;
            pointppl++;
            pointbuild++;
        }
        else{
            if(ppllist[pointppl]>buildlist[pointbuild]){
                pointbuild++;
            }
            else pointppl++;
        }
    }
    cout<<count;
}