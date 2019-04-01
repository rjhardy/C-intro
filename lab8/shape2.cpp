
#include <iostream>
const double pi = 3.1415926535;

using namespace std;

class Cylinder {
public:
    Cylinder(){
        setR(0);        //setW
        setH(0);        //setL
    }

    Cylinder(double in_r, double in_h){
        setR(in_r);
        setH(in_h);
    }

    double getR(){
        return r;
    }

    double getH(){
        return h;
    }

    void setR(double in_r){
        r = in_r;
    }

    void setH(double in_h){
        h = in_h;
    }

    void display(){
        cout << "Cylinder Parameters: " << endl;
        cout << "Radius: " << getR() << endl;
        cout << "Height: " << getH() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Voume: " << getVolume() << endl << endl;
    }

private:
    double getSurfaceArea(){
        return ((2 * pi * r) * (r + h));
    }

    double getVolume(){
        return (pi * (r * r) * h);
    }

    double r;
    double h;

};

int main(){

    Cylinder rect1;
    rect1.display();

    Cylinder rect2(2,4);
    rect2.display();

    rect2.setR(3);
    rect2.display();

    return 0;
}
