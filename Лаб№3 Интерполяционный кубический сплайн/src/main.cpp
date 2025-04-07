#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
ofstream fout("output.txt");

double func(double x) {
    return cos(2 * x);
}
double f_1(double x){
    return -2 * sin(2 * x);
}
double f_2(double x){
    return -4 * cos(2 * x);
}
double s3(double* M, double* x, double* h, double* y, int n, double X) {
    int k;
    for (int i = 1; i <= n; i++) {
        if (X >= x[i-1] && X <= x[i]) {
            k = i;
            break;
        }
    }
    double res = 0;
    res += M[k - 1] * pow(x[k] - X, 3) / (6 * h[k])
           + M[k] * pow(X - x[k - 1], 3) / (6 * h[k])
           + (y[k - 1] - M[k - 1] * h[k] * h[k] / 6) * (x[k] - X) / h[k]
           + (y[k] - M[k] * h[k] * h[k] / 6) * (X - x[k - 1]) / h[k];
    return res;
}
int main() {
    int a = -2, b = 2;
    int n = 15;
    double shag = (double)(b - a) / n;
    double* x = new double[n + 1];
    double* t = new double[101];
    double* y = new double[n + 1];
    double* h = new double[n + 1];
    double* C = new double[n + 1];
    double* A = new double[n + 1];
    double* B = new double[n + 1];
    double* f = new double[n + 1];
    double* alpha = new double[n + 1];
    double* betta = new double[n + 2];
    double* M = new double[n + 1];

    for (int i = 0; i <= n; i++) {
        x[i] = a + i * shag;
    }
    for (int i = 0; i <= n; i++) {
        y[i] = func(x[i]);
    }
    for (int i = 1; i <= n; i++) {
        h[i] = x[i] - x[i - 1];
    }
    C[0] = h[1] / 3;
    C[n] = 1;
    for (int i = 1; i < n; i++) {
        C[i] = (h[i] + h[i + 1]) / 3;
    }
    for (int i = 1; i < n; i++) {
        A[i] = h[i] / 6;
    }
    A[n] = 0;
    B[0] = h[1] / 6;
    for (int i = 1; i < n; i++) {
        B[i] = h[i + 1] / 6;
    }
    f[0] = (y[1] - y[0]) / h[1] - f_1(a);
    f[n] = f_2(b);
    for (int i = 1; i < n; i++) {
        f[i] = (y[i + 1] - y[i]) / h[i + 1] - (y[i] - y[i - 1]) / h[i];
    }
    for (int i = 1; i <= n; i++) A[i] = -A[i];
    for (int i = 0; i < n; i++) B[i] = -B[i];

    alpha[1] = B[0] / C[0];
    betta[1] = f[0] / C[0];
    for (int i = 1; i < n; i++) {
        double delta = C[i] - A[i] * alpha[i];
        alpha[i + 1] = B[i] / delta;
        betta[i + 1] = (f[i] + A[i] * betta[i]) / delta;
    }
    betta[n + 1] = (f[n] + A[n] * betta[n]) / (C[n] - A[n] * alpha[n]);

    M[n] = betta[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        M[i] = alpha[i + 1] * M[i + 1] + betta[i + 1];
    }

    for (int i = 0; i < 101; i++) {
        t[i] = a + (double)i * (b - a) / 100;
    }
    double max = 0;
    for (int i = 0; i < 101; i++) {
        double diff = fabs(s3(M,x,h,y,n,t[i]) - func(t[i]));
        if (diff > max) max = diff;
    }
    cout << max << endl;
    for (int i = 0; i <= 100; i++) {
        double fx = func(t[i]);
        double sx = s3(M, x, h, y, n, t[i]);
        fout << t[i] << " " << fx << " " << sx << endl;
    }

    return 0;
}
