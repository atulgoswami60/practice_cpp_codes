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
	double threes = 0;
	double others = 0;
	for(int i=1; i<=n-1; i++){
		if (i%3 == 0){
			threes += y[i];
		}
		else{
			others += y[i];
		}	
	}
	I = ((3*h)/8)*((y[0]+y[n]) + 2*(threes) + 3*(others));
	cout<<"the answer is: "<<I;
	return 0;
}
