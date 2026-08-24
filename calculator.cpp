#include <iostream>
using namespace std;
float add(float a, float b){
	return (a+b);
}
float mult(float a, float b){
	return (a*b);
}
float sub(float a, float b){
	return (a-b);
}
float div(float a, float b){
	if (b != 0){
		return (a/b);
	}else{
		return 999999;
	}
}

int main(){
	float a, b, res;
	int op; 
	cout<<"Enter two numbers "; cin>>a>>b;
	cout<<"Enter 1 for +"<<endl;
	cout<<"Enter 2 for x"<<endl;
	cout<<"Enter 3 for sub"<<endl;
	cout<<"Enter 4 for div"<<endl;
	cin>>op;
	switch(op){
		case 1:
			cout<<add(a, b)<<endl;
			break;
		case 2:
			cout<<mult(a, b)<<endl;
			break;
		case 3:
			cout<<sub(a, b)<<endl;
			break;
		case 4:
			cout<<div(a, b)<<endl;
			break;
	}
	
	return 0;
}
