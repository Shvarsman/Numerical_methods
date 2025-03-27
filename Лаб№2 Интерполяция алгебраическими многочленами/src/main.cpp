#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double f1(double x) {
    return cos(2 * x);
}

double f2(double x) {
    return sin(fabs(x)) + 1;
}

double newtonInterpolation(const vector<double>& x, const vector<double>& y, double xi) {
    int n = x.size();
    vector<double> coeffs = y;

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coeffs[i] = (coeffs[i] - coeffs[i - 1]) / (x[i] - x[i - j]);
        }
    }

    double result = coeffs[0];
    double product = 1.0;

    for (int i = 1; i < n; i++) {
        product *= (xi - x[i - 1]);
        result += coeffs[i] * product;
    }

    return result;
}

vector<double> equidistantNodes(int n) {
    vector<double> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = -2 + i * (4.0 / (n - 1));
    }
    return nodes;
}

vector<double> chebyshevNodes(int n) {
    vector<double> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = cos(M_PI * (2 * i + 1) / (2 * n));
        nodes[i] = -2 + (nodes[i] + 1) * 2;
    }
    return nodes;
}

int main() {
    int n_values[] = {6, 11, 16, 21, 31};
    for (int n : n_values) {
        vector<double> x_eq = equidistantNodes(n);
        vector<double> y1_eq(n), y2_eq(n);
        for (int i = 0; i < n; i++) {
            y1_eq[i] = f1(x_eq[i]);
            y2_eq[i] = f2(x_eq[i]);
        }

        double max_error_P1 = 0.0, max_error_P2 = 0.0;
        for (double xi = -2; xi <= 2; xi += 0.01) {
            double P1_n = newtonInterpolation(x_eq, y1_eq, xi);
            double P2_n = newtonInterpolation(x_eq, y2_eq, xi);
            max_error_P1 = max(max_error_P1, fabs(P1_n - f1(xi)));
            max_error_P2 = max(max_error_P2, fabs(P2_n - f2(xi)));
        }

        cout << "n = " << n - 1 << ":\n";
        cout << "max |P1,n(xi) - f1(xi)| = " << max_error_P1 << "\n";
        cout << "max |P2,n(xi) - f2(xi)| = " << max_error_P2 << "\n";

        vector<double> x_ch = chebyshevNodes(n);
        vector<double> y1_ch(n), y2_ch(n);
        for (int i = 0; i < n; i++) {
            y1_ch[i] = f1(x_ch[i]);
            y2_ch[i] = f2(x_ch[i]);
        }

        max_error_P1 = 0.0;
        max_error_P2 = 0.0;
        for (double xi = -2; xi <= 2; xi += 0.01) {
            double C1_n = newtonInterpolation(x_ch, y1_ch, xi);
            double C2_n = newtonInterpolation(x_ch, y2_ch, xi);
            max_error_P1 = max(max_error_P1, fabs(C1_n - f1(xi)));
            max_error_P2 = max(max_error_P2, fabs(C2_n - f2(xi)));
        }

        cout << "max |C1,n(xi) - f1(xi)| = " << max_error_P1 << "\n";
        cout << "max |C2,n(xi) - f2(xi)| = " << max_error_P2 << "\n";
    }

    return 0;
}
