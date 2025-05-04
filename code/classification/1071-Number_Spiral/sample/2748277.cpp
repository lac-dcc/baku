#include<bits/stdc++.h>
using namespace std;
 
 
void io_txt_file(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
 
 
//Print entire list.<int>
void showlist(list <int> l){
	list <int> :: iterator it;
	for(it = l.begin(); it !=l.end(); ++it){
		cout << *it <<" ";
	}
	cout << '\n';
}
 
 
//Print entire array.<int>
void showarray(int array[], int size){
	for (int i = 0; i < size; ++i) {
        cout << array[i] << "  ";
    }
}
 
 
 
//Main function.
int main(){
	io_txt_file();
 
//<code_start>
	long long int t;
	cin >> t;
	while(t>0){
		t=t-1;
		long long int y,x;
		cin >> y >> x;
		if(y>=x){
			if(y%2==0){
				cout << (y*y)-(x-1) << endl;
			}
			else{
				cout << ((y-1)*(y-1))+x << endl;
			}
		}
		else{
			if(x%2==0){
				cout << (x-1)*(x-1)+y << endl;
			}
			else{
				cout << (x*x)-(y-1) << endl;
			}
		}
	}
//<code_end>
 
	return 0;
}
 