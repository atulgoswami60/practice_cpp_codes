
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
    double alpha = 0.0;
    double beta = 0.0;

    cout << "Enter the value of h step size: " << endl;
    cin >> h;

    if (h <= 0.0) {
        cout << "Step size must be positive." << endl;
        return 0;
    }

    int n = static_cast<int>(
        round((x_right - x_left) / h)
    );

    if (n < 2) {
        cout << "Number of intervals must be at least 2."
             << endl;
        return 0;
    }

    // Adjust h so that the grid ends exactly at x_right
    h = (x_right - x_left) / n;

    cout << "Number of sub-intervals: " << n << endl;

    // Number of interior unknowns
    int m = n - 1;

    vector<double> A(m), B(m), C(m), D(m);
    vector<double> y(n + 1);

    // Construct the tridiagonal system
    for (int j = 0; j < m; j++) {
        int i = j + 1;
        double x = x_left + i * h;

        double Pi = p(x);
        double Qi = q(x);
        double Ri = r(x);

        A[j] = 1.0 - h * Pi / 2.0;
        B[j] = -2.0 + h * h * Qi;
        C[j] = 1.0 + h * Pi / 2.0;
        D[j] = h * h * Ri;
    }

    // Apply boundary conditions
    D[0] -= A[0] * alpha;
    D[m - 1] -= C[m - 1] * beta;

    // Forward elimination (Thomas algorithm)
    for (int i = 1; i < m; i++) {
        if (fabs(B[i - 1]) < 1e-12) {
            cout << "Zero pivot encountered." << endl;
            return 0;
        }

        double factor = A[i] / B[i - 1];

        B[i] -= factor * C[i - 1];
        D[i] -= factor * D[i - 1];
    }

    if (fabs(B[m - 1]) < 1e-12) {
        cout << "Zero pivot encountered." << endl;
        return 0;
    }

    // Back substitution
    y[n - 1] = D[m - 1] / B[m - 1];

    for (int i = m - 2; i >= 0; i--) {
        y[i + 1] =
            (D[i] - C[i] * y[i + 2]) / B[i];
    }

    // Insert boundary values
    y[0] = alpha;
    y[n] = beta;

    // Display the numerical solution
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
