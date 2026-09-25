#include <iostream>
#include <iomanip>
using namespace std;

double f(double x, double y){
	return x+y;
}

int main(){
	double x0, y0, h, x_end;
	cout<<"Enter x0 y0 h x_end: "; cin>>x0>>y0>>h>>x_end;
	cout<<endl;
	
	cout<< fixed <<setprecision(8);
	cout<<"x-values \t\t y-values\n\n";
	
	double x = x0; double y = y0;
	
	while(x < x_end){
		double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        // Calculate next x
        x = x + h;

        cout << x << "\t\t" << y << endl;
	}
	
}
