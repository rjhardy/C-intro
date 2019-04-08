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

class Triangle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Triangle &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2 << endl << "Point 3: " << L.P3 << endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Triangle &L ){
        input >> L.P1 >> L.P2 >> L.P3;
        return input;
    }

public:
    // Add your functions/methods here //
    Triangle(const Point &p1_t, const Point &p2_t, const Point &p3_t){
        P1 = p1_t;
        P2 = p2_t;
        P3 = p3_t;
    }
    Triangle()  {
        P1.setx(0);
        P1.sety(0);
        P2.setx(0);
        P2.sety(0);
        P3.setx(0);
        P3.sety(0);
    }
    double Area()   {               //calculates the area
        double a, b, c, d, area;

        a = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2));
        b = sqrt(pow((P3.getx() - P1.getx()), 2) + pow((P3.gety() - P1.gety()), 2));                 //These calculations also used to compute perimeter
        c = sqrt(pow((P3.getx() - P2.getx()), 2) + pow((P3.gety() - P2.gety()), 2));
        d = (a + b + c) / 2;

        area = sqrt((d*(d-a)*(d-b)*(d-c)));

        return area;
    }

    double Perimeter()   {
        double a, b, c, perimeter;
        a = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2));
        b = sqrt(pow((P3.getx() - P1.getx()), 2) + pow((P3.gety() - P1.gety()), 2));                //Calculations are used for area too
        c = sqrt(pow((P3.getx() - P2.getx()), 2) + pow((P3.gety() - P2.gety()), 2));
        perimeter = (a + b + c);

        return perimeter;
    }

    bool Test()   {                 //Testing points to see if they're triangles
        double ans;

        ans = (P1.getx() * (P2.gety() - P3.gety())) + (P2.getx() * (P3.gety() - P1.gety())) + (P3.getx() * (P1.gety() - P2.gety()));
        if(ans == 0.0)   {
            cout << "Not a triangle" << endl;
            return false;
        }
        else   {
            cout << "Is a Triangle" << endl;
            return true;
        }
    }
    bool Equilateral()   {
        double a, b, c;
        a = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2));
        b = sqrt(pow((P3.getx() - P1.getx()), 2) + pow((P3.gety() - P1.gety()), 2));                //Calculates the sides
        c = sqrt(pow((P3.getx() - P2.getx()), 2) + pow((P3.gety() - P2.gety()), 2));

        if(a == b && b == c)   {
            cout << "The triangle is an equilateral" << endl;
            return true;
        }
        else   {
            cout << "The triangle is not an equilateral" << endl;
            return false;
        }
    }

    bool operator == (Triangle rhs)   {
        if((P1.getx() == rhs.P1.getx() && P1.gety() == rhs.P1.gety()) && (P2.getx() == rhs.P2.getx() && P2.gety() == rhs.P2.gety()) && (P3.getx() == rhs.P3.getx() && P3.gety() == rhs.P3.gety()))   {
        return true;
    }
    else   {
        return false;
}
}

private:
    Point P1, P2, P3;

};

int main(){

    Point P1;
    Point P2;
    Point P3;

    cout << "Point P1 should have 0,0 as values" << endl;
    cout << P1 << endl;
    cout << "Point P2 should have 7,6 as values" << endl;       //Dont really need this
    cout << P2 << endl;
    cout << endl;

    cout << "Enter x and y points for P1: ie 3 2 " << endl;
    cin >> P1;
    cout << P1 << endl;

    cout << "Enter x and y points for P2: ie 4 5 " << endl;
    cin >> P2;
    cout << P2 << endl;

    cout << "Enter x and y points for P3: ie 6 4 " << endl;
    cin >> P3;
    cout << P3 << endl;


                                                                       //The equations for area and perimeter are called
    Triangle T1(P1,P2,P3);                                             //This assigns the point values for the triangle
    cout << endl;
    cout << "Triangle Area: " << T1.Area() << endl;                   //It works
    cout << "Triangle Perimeter: " << T1.Perimeter() << endl;
    cout << "Test for if it is a Triangle: " << T1.Test() << endl;
    cout << "Is it an Equilateral: " << T1.Equilateral() << endl;

    Triangle T2(P1,P2,P3);
    bool c= T1 == T2;
    cout << c << endl;
    return 0;
}
