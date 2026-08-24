#include <iostream>
using namespace std;

int cube(int a){
	int y = a*a*a;
	return y;
}

int main(){
	cout<<"cube of 2 = "<<cube(2)<<endl;
	cout<<"cube of 5 = "<<cube(5)<<endl;
	cout<<"cube of 7 = "<<cube(7)<<endl;

	return 0;
}
