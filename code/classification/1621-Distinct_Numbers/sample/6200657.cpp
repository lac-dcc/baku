#include <stdio.h>
 
void swap(int *a,int *b){
    int T=*a;
    *a=*b;
    *b=T;
}
void heapify(int *a,int parent,int n){
    if((parent>=n)){
        return;
    }
    int largest=parent,left=2*parent+1,right=2*parent+2;
    if(right<n && a[right]>a[largest]) largest=right;
    if(left<n && a[left]>a[largest]) largest=left;
    if(largest!=parent){
        swap(&a[largest],&a[parent]);
        heapify(a,largest,n);
    }
}
 
void heapSort(int *a,int N){
    int i;
    for(i=N/2-1;i>=0;i--){
        heapify(a,i,N);
    }
    for(i=0;i<N;i++){
        swap(&a[0],&a[N-i-1]);
        heapify(a,0,N-i-1);
    }
}
void solve(){
    int n,i;
    fscanf(stdin,"%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        fscanf(stdin,"%d",&a[i]);
    }
    heapSort(a,n);  
    int ans=1;  
    for(i=1;i<n;i++){        
        if((a[i]^a[i-1])){
            ans+=1;
        }
    }
    fprintf(stdout,"%d\n",ans);
    return;
}
 
int main()
{
    int tt=1;
    // fscanf(stdin,"%d",&tt);
    while((tt--)>0){
        solve();
    }
}