#include <iostream>
using namespace std;

void pattern(int n){
	int i = 1;
	while(i <= n){
		int j = 1;
		while(j <= i){
			cout<<"*"<<"  ";
			j++;
		}
		cout<<endl;
		i++;
	}
}

int main(){
	int n; cout<<"Enter the lines of star pattern"<<endl; cin>>n;
	pattern(n);
	return 0;
}
