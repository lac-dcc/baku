#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
int findFarthestNode(vector<int>arr[],int maxSize,int start =0){
    queue<int>q;
    int maxElem = start;
    int maxDist = 0;
    int temp;
    int visited[maxSize],level[maxSize];
    for(int i=0;i<maxSize;i++){
        visited[i]=0;
    }
    level[start]=0;
    q.push(start);
    while(!q.empty()){
        temp = q.front();
        visited[temp]=1;
        q.pop();
        for(int i=0;i<arr[temp].size();i++){
            if(!visited[arr[temp][i]]){
                level[arr[temp][i]]= level[temp] + 1;
                q.push(arr[temp][i]);
                if(level[arr[temp][i]]>maxDist){
                    maxDist = level[arr[temp][i]];
                    maxElem = arr[temp][i];
                }
            }
        }
    }
    return maxElem;
    
}
 
void updateDist(vector<int>arr[],int level[],int maxSize,int start){
    queue<int>q;
    int temp;
    int visited[maxSize];
    for(int i=0;i<maxSize;i++){
        visited[i]=0;
    }
    level[start]=0;
    q.push(start);
    while(!q.empty()){
        temp = q.front();
        visited[temp]=1;
        q.pop();
        for(int i=0;i<arr[temp].size();i++){
            if(!visited[arr[temp][i]]){
                level[arr[temp][i]]= level[temp] + 1;
                q.push(arr[temp][i]);
            }
        }
    }
}
 
int maxof(int a,int b) {
    if(a>b) return a;
    return b;
}
 
int main(){
    int n,a,b;
    cin>>n;
    vector<int>arr[n];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    int max1 = findFarthestNode(arr,n);
    int max2 = findFarthestNode(arr,n,max1);
    int dist1[n],dist2[n];
    updateDist(arr,dist1,n,max1);
    updateDist(arr,dist2,n,max2);
    for(int i=0;i<n;i++){
        cout<<maxof(dist1[i],dist2[i])<<" ";
    }
}
