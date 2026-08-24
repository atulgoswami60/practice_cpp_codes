#include <iostream>
using namespace std;
int fact(int n){
	if (n < 2){
		return 1;
		
	}else{
		return n*fact(n-1);
	}
}

int main(){
	int n; cout<<"Enter the number "; cin>>n;
	cout<<"Fatorial of "<<n<<" is : "<<fact(n)<<endl;
	return 0;
}
