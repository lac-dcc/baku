#include <cstdio>
#include <map>
 
std::map<int,std::pair<int,int> > half;
int as[1001];
 
int main(){
  int N,X;
  scanf("%d %d",&N,&X);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(half.count(X-as[i]-as[j])){
	auto v=half[X-as[i]-as[j]];
	printf("%d %d %d %d\n",v.first+1,v.second+1,i+1,j+1);
	return 0;
      }
    }
    for(int j=0;j<i;j++){
      half[as[i]+as[j]]=std::make_pair(j,i);
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
