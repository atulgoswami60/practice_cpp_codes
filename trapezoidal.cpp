#include <iostream>
using namespace std;              // lower upper is 0 2, int(1/16+x^2)

double f(double x){
	double exp = 1/(16 + x*x);
	return exp;
}

int main(){
	int a, b, n; double h, x0, I;
	double y[100];
	cout<<"Enter the limits (lower upper): ";
	cin>>a>>b;
	cout<<"Enter the number of intervals: ";
	cin>>n;
	h = (double)(b-a)/n;
	x0 = a;
	for(int i = 0; i<=n; i++){
		y[i] = f(x0);
		x0 = x0 + h;
	}
	double sec_exp = 0;
	for(int i=1; i<=n-1; i++){
		sec_exp += y[i];
	}
	I = (h/2)*((y[0]+y[n]) + 2*(sec_exp));
	cout<<"the answer is: "<<I;
	return 0;
}
