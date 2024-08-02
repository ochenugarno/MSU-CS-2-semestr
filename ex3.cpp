#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double dt = 0.05, t = 0, x1, x2;
    cin >> x1 >> x2;
    cout << t << " " << x2 << std::endl;
    double k1_1, k1_2, k1_3, k1_4;
    double k2_1, k2_2, k2_3, k2_4;
    k1_1 = dt * x2;
    k2_1 = -dt * sin(x1);
    k1_2 = dt * (x2 + 0.5 * k2_1);
    k2_2 = -dt * sin(x1 + 0.5 * k1_1);
    k1_3 = dt * (x2 + 0.5 * k2_2);
    k2_3 = -dt * sin(x1 + 0.5 * k1_2);
    k1_4 = dt * (x2 + k2_3);
    k2_4 = -dt * sin(x1 + k1_3);
    x1 += (k1_1 + 2*k1_2 + 2*k1_3 + k1_4)/6;
    x2 += (k2_1 + 2*k2_2 + 2*k2_3 + k2_4)/6;
    t += dt;
    cout << t << " " << x2 << std::endl;
    int i;
    for (i = 1; i < 3000; i++) {
        k1_1 = dt * x2;
        k2_1 = -dt * sin(x1);
        k1_2 = dt * (x2 + 0.5 * k2_1);
        k2_2 = -dt * sin(x1 + 0.5 * k1_1);
        k1_3 = dt * (x2 + 0.5 * k2_2);
        k2_3 = -dt * sin(x1 + 0.5 * k1_2);
        k1_4 = dt * (x2 + k2_3);
        k2_4 = -dt * sin(x1 + k1_3);
        x1 += (k1_1 + 2*k1_2 + 2*k1_3 + k1_4)/6;
        x2 += (k2_1 + 2*k2_2 + 2*k2_3 + k2_4)/6;
        t += dt;
        cout << t << " " << x2 << std::endl;
    }
}
