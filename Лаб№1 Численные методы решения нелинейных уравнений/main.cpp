#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return sqrt(x + 2) - 2 * cos(x);
}

double f_(double x) {
    return 1 / (2 * sqrt(x + 2)) + 2 * sin(x);
}

double dih(double a, double b, double eps) {
    double c;
    int k = 0;
    while (fabs(b - a) > 2 * eps) {
        c = (a + b) / 2;
        cout << "k=" << k << " a=" << a << " b=" << b << " f(a)=" << f(a) << " f(b)=" << f(b) << " b-a=" << b - a << endl;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        k++;
    }
    return c;
}

double New(double x0, double eps) {
    double x1;
    int k = 0;
    for(;;){
        x1 = x0 - f(x0) / f_(x0);
        cout << "k=" << k << " x_k=" << x0 << " |x_k-x_k-1|=" << fabs(x1 - x0) << endl;
        if (fabs(x1 - x0) < eps) break;
        x0 = x1;
        k++;
    }
    return x1;
}

double New_2(double x0, double eps) {
    double x1, proizv = f_(x0);
    int k = 0;
    for(;;){
        x1 = x0 - f(x0) / proizv;
        cout << "k=" << k << " x_k=" << x0 << " |x_k-x_k-1|=" << fabs(x1 - x0) << endl;
        if (fabs(x1 - x0) < eps) break;
        x0 = x1;
        k++;
    }
    return x1;
}

double Sec(double x0, double x1, double eps) {
    double x2;
    int k = 0;
    for(;;) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        cout << "k=" << k << " x_k=" << x1 << " |x_k-x_k-1|=" << fabs(x2 - x1) << endl;
        if (fabs(x2 - x1) < eps) break;
        x0 = x1;
        x1 = x2;
        k++;
    }
    return x2;
}

int main() {
    double a = 0.0, b = 2.0;
    double eps_dih = 0.01;
    double eps = 1e-7;

    double dihotomiya = dih(a, b, eps_dih);
    cout << "Корень, найденный методом дихотомии: " << dihotomiya << endl;
    double n = New(dihotomiya, eps);
    cout << "Корень, найденный методом Ньютона: " << n << endl;
    double n_2 = New_2(dihotomiya, eps);
    cout << "Корень, найденный методом Ньютона с постоянной поизводной: " << n_2 << endl;
    double s = Sec(dihotomiya, dihotomiya + 0.1, eps);
    cout << "Корень, найденный методом секущих: "  << s << endl;

    return 0;
}
