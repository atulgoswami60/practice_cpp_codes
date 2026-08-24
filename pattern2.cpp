#include <iostream>
using namespace std;

void pattern(int n){
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if (j > i){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int n; cout<<"Enter the lines of star pattern"<<endl; cin>>n;
	pattern(n);
	return 0;
}
