#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double TOLERANCE = .001;

double f(double nth)   {
    double fx;

    fx = pow(nth,4) + (2*(pow(nth,3))) - (31*(pow(nth,2))) - (32 * nth) + 60;

    return fx;
}

double fprime(double nth)   {
    double dfx;

    dfx = (4 * pow(nth,3)) + (6 * pow(nth,2)) - (62 * nth) - 32;

    return dfx;
}

double newtonRoot(double x0)   {
    double xone;

    xone = x0 - (f(x0)/fprime(x0));
    double tol = abs(xone - x0);

    while(tol > TOLERANCE)   {
        x0 = xone;
        xone = x0 - (f(x0)/fprime(x0));
        tol = abs(xone - x0);
    }
    return xone;
}

int main()   {
    double guess;
    char go = 'y';
    do{
        cout << "Enter a guess" << endl;
        cin >> guess;
        cout << "Root: " << newtonRoot(guess) << endl;
        cout << "Enter Another Guess: y/n?";
        cin >> go;
    }while(go == 'y');

    return 0;
}
