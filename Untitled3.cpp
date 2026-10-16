#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double p(double x) {
    return 0.0;
}

double q(double x) {
    return 0.0;
}

double r(double x) {
    return -2.0;
}

int main() {
    double h;

    double x_left = 0.0;
    double x_right = 1.0;
    double alpha_bc = 0.0;  // Left boundary value
    double beta_bc = 0.0;   // Right boundary value

    cout << "Enter the value of h step size: ";
    cin >> h;

    if (h <= 0.0) {
        cout << "Step size must be positive." << endl;
        return 0;
    }

    // Calculate the number of sub-intervals
    int n = static_cast<int>(
        round((x_right - x_left) / h)
    );

    if (n < 2) {
        cout << "Number of intervals must be at least 2."
             << endl;
        return 0;
    }

    // Adjust h to ensure the last point equals x_right
    h = (x_right - x_left) / n;

    cout << "Number of sub-intervals: " << n << endl;

    // Number of interior unknowns
    int m = n - 1;

    // Arrays for the tridiagonal system:
    // A = sub-diagonal, B = principal diagonal,
    // C = super-diagonal, D = right-hand side
    vector<double> A(m + 1), B(m + 1);
    vector<double> C(m + 1), D(m + 1);

    // Arrays used by the given tridiagonal algorithm
    vector<double> alpha(m + 1), beta(m + 1);
    vector<double> y(n + 1);

    // Construct the finite difference equations
    for (int j = 1; j <= m; j++) {
        int i = j;
        double x = x_left + i * h;

        double Pi = p(x);
        double Qi = q(x);
        double Ri = r(x);

        // Coefficients of the finite difference equation
        A[j] = 1.0 - h * Pi / 2.0;
        B[j] = -2.0 + h * h * Qi;
        C[j] = 1.0 + h * Pi / 2.0;
        D[j] = h * h * Ri;
    }

    // Apply the boundary conditions to the first and
    // last equations of the tridiagonal system
    D[1] -= A[1] * alpha_bc;
    D[m] -= C[m] * beta_bc;


 

    alpha[1] = B[1];

    // Remaining equations
    for (int i = 2; i <= m; i++) {
        if (fabs(alpha[i - 1]) < 1e-12) {
            cout << "Zero pivot encountered." << endl;
            return 0;
        }

        alpha[i] = B[i]
                 - (A[i] * C[i - 1]) / alpha[i - 1];
    }

    // ------------------------------------------------
    // Calculate beta values
    // ------------------------------------------------

    // First equation
    beta[1] = D[1] / B[1];

    // Remaining equations
    for (int i = 2; i <= m; i++) {
        beta[i] = (D[i] - A[i] * beta[i - 1])
                / alpha[i];
    }

    // ------------------------------------------------
    // Back substitution: calculate interior y values
    // ------------------------------------------------

    y[m] = beta[m];

    for (int i = m - 1; i >= 1; i--) {
        y[i] = beta[i] - (C[i] * y[i + 1]) / alpha[i];
    }

    // Insert the boundary values
    y[0] = alpha_bc;
    y[n] = beta_bc;

    // ------------------------------------------------
    // Display the numerical solution
    // ------------------------------------------------

    cout << fixed << setprecision(6);
    cout << "\nFinite Difference Solution\n";
    cout << "--------------------------------\n";
    cout << "     x          y(x)\n";
    cout << "--------------------------------\n";

    for (int i = 0; i <= n; i++) {
        double x = x_left + i * h;

        cout << setw(10) << x
             << setw(14) << y[i] << endl;
    }

    return 0;
}
