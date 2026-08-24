#include <iostream>
using namespace std;

void TOH(int n, string A, string B, string C){
	if(n == 1){
		cout<<"move "<<A<<"---> "<<C<<endl;
		return;
	}
	TOH(n-1, A, C, B);
	cout<<"move "<<A<<"---> "<<C<<endl;
	TOH(n-1, B, A, C);
}

int main(){
	int n; cout<<"enter number of discs\n"; cin>>n;
	TOH(n, "A", "B", "C");
	
	return 0;
}
