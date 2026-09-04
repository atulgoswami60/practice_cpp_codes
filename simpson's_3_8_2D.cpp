#include <iostream>
using namespace std;

double f(double x, double y){
	return (1.0/(x+y));
}

int main(){
	double a, b, c, d;
	int n, m;
	cout<<"Enter the limits outer then lower: a b c d "<<endl;
	cin>>a>>b>>c>>d;
	cout<<"Enter the intervals in x dir and y dir: n m: "<<endl;
	cin>>n>>m;
	
	double hx = (b-a)/n; double hy = (d - c)/m;
	
	double sum = 0;
	for(int i=0; i<=n; i++){
		double x = a + i * hx;
		double wx;
		if(i==0||i==n){
			wx = 1;
		}else if(i%3 == 0){
			wx = 2;
		}else{
			wx = 3;
		}
		
		for(int j=0; j<=m; j++){
			double y = c + j*hy;
			double wy;
			if(j == 0 || j==m){
				wy = 1;
			}else if(j%3 == 0){
				wy = 2;
			}else{
				wy = 3;
			}
	
			sum += f(x, y)*wx*wy;
			

		}
		
		
	}
	
	double integral = sum*(hx*hy)*(9.0/64.0);
	cout<<"The double Integral is: "<<integral;
	
	return 0;
}
