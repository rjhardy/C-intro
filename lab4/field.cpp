#include <iostream>
#include <cmath>

using namespace std;

double Efield(double r, double a = 1)   {
    if (r < a){
        double Efield = 9 * (r / pow(a, 3));
        return Efield;
    }
    else if (r >= a)   {
        double Efield = 9 / pow(r, 2);
        return Efield;
    }
}

int main()   {

    int r;
    int a;

    cin >> r;

    cin >> a;
    cout << "Efield: " << Efield(r, a) << endl;

    return 0;
}
