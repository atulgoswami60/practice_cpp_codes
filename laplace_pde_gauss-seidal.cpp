#include <bits/stdc++.h>
using namespace std;

int main(){
	const int N = 3;
	const int max_iter = 1000000;
	const double tole = 1e-7;
	
	double u[N+1][N+1] = {};
	
	//setting the B.C
	for(int i = 1; i<N; i++){
		u[N][i] = 100;
	}
	int iteration;
	
	for(iteration = 1; iteration<max_iter; iteration++){
		
		double max_change = 0.0;
		for(int j = 1; j<N; j++){
			for(int i = 1; i<N; i++){
				double old_val = u[j][i];
				u[j][i] = (u[j][i-1] + u[j][i+1] + u[j-1][i] + u[j+1][i])/4.0;
				
				double change = fabs(old_val - u[j][i]);
				if(change > max_change){
					max_change = change;
				}
			}
		}
		if(max_change < tole){
			break;
		}
	}
	
	if (iteration > max_iter) {
        cout << "Method did not converge.\n";
        return 1;
    }

    // STEP 5: Print results
    cout << "Iterations: " << iteration << "\n";

    cout << fixed << setprecision(6);

    cout << "A = " << u[1][1] << "\n";
    cout << "B = " << u[1][2] << "\n";
    cout << "C = " << u[2][1] << "\n";
    cout << "D = " << u[2][2] << "\n";

    cout << "\nFinal grid:\n";

    for (int j = N; j >= 0; j--) {
        for (int i = 0; i <= N; i++) {
            cout << setw(12) << u[j][i];
        }
        cout << "\n";
    }
	
	
	
	
	
		
	return 0;
}
