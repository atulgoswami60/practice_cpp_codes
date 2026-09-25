#include <iostream>
#include <iomanip>
using namespace std;

// Define dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;   // Example: dy/dx = x + y
}

int main() {
    double x0, y0, h, x_end;
    cout<<"Enter x0 y0 h xn: "; cin>>x0>>y0>>h>>x_end;
	cout<<endl;
    double x = x0;
    double y = y0;

    cout << fixed << setprecision(8); 
  	cout<<"x_i-values: \t\t y_i-values\n\n";

    while (x < x_end) {
        y = y + h * f(x, y);
        x = x + h;

        cout << x << " \t\t " << y << endl;
    }

    return 0;
}

