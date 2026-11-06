#include <bits/stdc++.h>
using namespace std;  // ut = uxx, 0<x<1  u(x,0) = x(1-x), u(0,t) = u(1,t) = 0, delx = 0.25, delt = 0.025
                      // r = 0.4 as alpha = 1,  fiind ux values at t = 0.05


int main(){
	double delx, delt, alpha;
	delt = 0.025; delx = 0.25; alpha = 1.0;
	double u[50][10] = {};
	double u0, u1, u2;
	double r = (alpha*delt)/(delx*delx);
	
	int n = 1 + (1/delx);
	int t = 10;    // have to find at t = 0.05, and delt = 0.025
	
	for(int i = 0; i<n; i++){
		u[0][i] = (i*delx)*(1 - i*delx);
	}
	
	for(int i = 1; i<=t; i++){
		for(int j = 1; j<n-1; j++){
			u0 = u[i-1][j-1];
			u1 = u[i-1][j];
			u2 = u[i-1][j+1];
			u[i][j] = 0.4*u0 + 0.2*u1 + 0.4*u2;
		}
	}
	
	 cout << fixed << setprecision(4);
	
	for(int i = 0; i<=t; i++ ){
		for(int j = 0; j<n; j++){
			cout<<u[i][j]<<"    ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
