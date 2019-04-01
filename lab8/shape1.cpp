#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setW(0);
    }

    Cube(double in_w){
        setW(in_w);
    }

    double getW(){
        return w;
    }

    void setW(double in_w){
        w = in_w;
    }

    void display(){
        cout << "Cube Parameters: " << endl;
        cout << "Width: " << getW() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "SurfaceArea: " << getSurfaceAreaCube() << endl;


    }

private:
    double getSurfaceAreaCube(){
        return 6 * (w * w);
    }
    double getVolume(){
        return (w * w * w);
    }

    double w;

};

int main(){

    Cube cube1;
    cube1.display();

    Cube cube2(2);
    cube2.display();

    cube2.setW(3);
    cube2.display();

    return 0;
}
