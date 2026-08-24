#include <iostream>
using namespace std;

int fact(int n){
	int res=1;
	while (n>0){
		res *= n;
		n--;
	}
	
}

int main(){
	int n; cout<<"Enter the number you want to calculate factorial of: "<<endl; cin>>n;
	cout<<"Factorial of "<<n<<" is = "<<fact(n)<<endl;
	
	
	return 0;
}
