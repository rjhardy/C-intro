// Add your information here

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    int getx()   {
        return x;               //Add your functions
    }

    int gety()   {
        return y;
    }

    void setx(int in_x)   {
        x = in_x;
    }
    void sety(int in_y)   {
        y = in_y;
    }

private:
    int x,y;
};

class Quadrilateral {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Quadrilateral &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2 << endl << "Point 3: " << L.P3 << endl << "Point 4: " << L.P4 << endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Quadrilateral &L ){
        input >> L.P1 >> L.P2 >> L.P3 >> L.P4;
        return input;
    }

public:
    // Add your functions/methods here //
    Quadrilateral(const Point &p1_t, const Point &p2_t, const Point &p3_t, const Point &p4_t){
        P1 = p1_t;
        P2 = p2_t;
        P3 = p3_t;
        P4 = p4_t;
    }
    Quadrilateral()  {
        P1.setx(0);
        P1.sety(0);
        P2.setx(0);
        P2.sety(0);
        P3.setx(0);
        P3.sety(0);
        P4.setx(0);
        P4.sety(0);
    }
    double Area()   {               //calculates the area
        double area;

        area = (.5) * ((P1.getx() * P2.gety()) + (P2.getx() * P3.gety()) + (P3.getx() * P4.gety()) + (P4.getx() * P1.gety()) - (P2.getx() * P1.gety()) - (P3.getx() * P2.gety()) - (P4.getx() * P3.gety()) - (P1.getx() * P4.getx()));

        return area;
    }

    bool Test()   {                 //Testing points to see if they're triangles
        double a, b, c, d;
         a = (P1.getx()*(P2.gety() - P3.gety())) + (P2.getx() * (P3.gety() - P1.gety())) + (P3.getx()* (P1.gety() - P2.gety()));

         b =  (P2.getx()*(P3.gety() - P4.gety())) + (P3.getx() * (P4.gety() - P1.gety())) + (P4.getx()* (P3.gety() - P1.gety()));

         c =  (P1.getx()*(P3.gety() - P4.gety())) + (P3.getx() * (P4.gety() - P1.gety())) + (P4.getx()* (P3.gety() - P2.gety()));

         d =  (P1.getx()*(P2.gety() - P4.gety())) + (P2.getx() * (P4.gety() - P1.gety())) + (P4.getx()* (P1.gety() - P2.gety()));


        if(a == 0.0)   {
            return true;
        }
        else if(b == 0.0)   {
            return true;
        }
        else if(c == 0.0)   {
            return true;
        }
        else if(d == 0.0)   {
            return true;
        }
        else {
            return false;
        }
        }


    bool operator == (Quadrilateral rhs)   {
        if((P1.getx() == rhs.P1.getx() && P1.gety() == rhs.P1.gety()) && (P2.getx() == rhs.P2.getx() && P2.gety() == rhs.P2.gety()) && (P3.getx() == rhs.P3.getx() && P3.gety() == rhs.P3.gety()))   {
        return true;
    }
    else   {
        return false;
}
}

private:
    Point P1, P2, P3, P4;

};

int main(){

    Point P1;
    Point P2;
    Point P3;
    Point P4;

    cout << "Enter x and y points for P1: ie 3 2 " << endl;
    cin >> P1;
    cout << P1 << endl;

    cout << "Enter x and y points for P2: ie 4 5 " << endl;
    cin >> P2;
    cout << P2 << endl;

    cout << "Enter x and y points for P3: ie 6 4 " << endl;
    cin >> P3;
    cout << P3 << endl;

    cout << "Enter x and y points for P4: ie 5 8" << endl;
    cin >> P4;
    cout << P4 << endl;
                                                                       //The equations for area and perimeter are called
    Quadrilateral T1(P1,P2,P3,P4);                                             //This assigns the point values for the triangle
    cout << endl;
    cout << "Quadrilaterl Area: " << T1.Area() << endl;
    cout << "collinearity test: " << T1.Test() << endl;

    if(T1.Test() == true)   {
        cout << "Not a quadrilateral" << endl;
    }
    else   {
        cout << "It is a quadrilateral" << endl;
    }
}
