#include <iostream>
using namespace std;

int fibo(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	return (fibo(n-2) + fibo(n-1));
}

int main(){
	int n;
	cout<<"Enter the number: "<<endl;
	cin>>n;
//	cout<<n<<"th The fibonacci number is: "<<fibo(n)<<endl;
	for(int i = 0; i<n; i++){
		cout<<i<<"th fibonacci number is: "<<fibo(i)<<endl;
	}
	return 0;
}
