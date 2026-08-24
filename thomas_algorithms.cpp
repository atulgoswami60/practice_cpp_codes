#include <iostream>
using namespace std;

int main(){
	int n;
	float a[100], b[100], c[100], d[100], x[100], alpha[100], beta[100];
	cout<<"enter the number of equations/variables\n";
	cin>>n;
	cout<<"Enter the values of principal diagonal\n";
	int i;
	for(i = 1; i<=n; i++){
		cin>>b[i];
	}
	cout<<"enter the values of sub-diagonal\n";
	for(i = 2; i<=n; i++){
		cin>>a[i];
	}
	cout<<"enter the values of super-diagonal\n";
	for(i = 1; i<=n-1; i++){
		cin>>c[i];
	}
	cout<<"enter the d- values of equations\n";
	for(i = 1; i<=n; i++){
		cin>>d[i];
	}
	alpha[1] = b[1];
	for(i=2; i<=n; i++){
		alpha[i] = b[i] - (a[i]*c[i-1])/alpha[i-1];
	}
	beta[1]=d[1]/b[1];
	for(i=2; i<=n; i++){
		beta[i] = (d[i] - a[i]*beta[i-1])/alpha[i];
	}
	x[n] = beta[n];
	for(i=n-1; i>=1; i--){
		x[i] = beta[i] - (c[i]*x[i+1])/alpha[i];
	}
	
	cout<<"The solutions that is x values are: ";
	for(i = 1; i<=n; i++){
		cout<<x[i]<<"  ";
	}
	
	cout<<"\nChecking the solution by substituting back in the equations\n";
	float first = 3*(x[1]) - x[2];
	float second = -1*(x[1]) + 3*(x[2]) - x[3];
	float third = -1*(x[2]) + 3*(x[3]);
	
	cout<<first<<endl<<second<<endl<<third<<endl;                                                       
	
	return 0;
}
