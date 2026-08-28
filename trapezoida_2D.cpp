#include <iostream>
#include <cmath>
using namespace std;              // lower upper is 0 2, int(1/16+x^2)

double f(double x, double y){
	double exp = 1.0/(x + y);
	return exp;
}

int main(){
	int n, m;
	double a, b, c, d;
	
	cout<<"Enter the limits of the outer integral: "<<endl;
	cin>> a>>b;
	cout<<"Enter the limits of the inner integral: "<<endl;
	cin>> c>>d;
	cout<<"Enter the number of intervals (n m): "<<endl;
	cin>> n>>m;
	double y[n+1][m+1];

	double h = (b-a)/n;
	double k = (d-c)/m;
	
	double x0, y0;
	x0 = a;
	for(int i=0; i<=n; i++){
		y0 = c;
		for(int j=0; j<=m; j++){
			y[i][j] = f(x0, y0);
			y0 = y0 + k;
		}
		x0 = x0 + h;
	}
	double I = 0; // multiply with hk/4 later
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if((i==0 && j==0) || (i==0 && j==m) || (i==n && j==0) || (i==n && j==m)){
				I += y[i][j];
			}else if(i==0 || i==n || j==0 || j== m){
				I += 2*y[i][j];
			}else{
				I += 4*y[i][j];
			}
		}
	}
	
	I = ((h*k)/4)*I;
	cout<<"the answer is : "<<I<<endl;
	return 0;
}
