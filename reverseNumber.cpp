#include <iostream>
using namespace std;

int reverseNumber(int n, int rev=0){
	if (n == 0){
		return rev;
	} return reverseNumber(n/10, rev*10 + n%10);
}


int main(){
	int n;
	cout<<"Enter the number: "<<endl;
	cin>>n;
	
	cout<<"Reversed Number is: "<<reverseNumber(n)<<endl;
	
	return 0;
}
