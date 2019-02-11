#include <iostream>
#include <cmath>

using namespace std;

double compareDelta(double num1, double num2, double delta)   {
    double difference;
    double difference2;
    double abs1;
    double abs2;
    difference = num1 - num2;                          //changing num1 and num2
    difference2 = num2 - num1;
    abs1 = fabs(difference);
    abs2 = fabs(difference2);
    if(abs1 == delta && abs2 == delta)  {    //changing to decision statement
        return 'T';

    }else   {
        return 'F';

    }
}

int main()   {
double num1;
double num2;
double delta;
cin >> num1;
cin >> num2;
cin >> delta;
cout << compareDelta(num1, num2, delta) << endl;
}
