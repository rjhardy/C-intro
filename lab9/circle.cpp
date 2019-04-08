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
    //overloads == operator
    bool operator == (Point &rhs)   {
        return (rhs.x == x && rhs.y == y);
    }

private:
    int x,y;
};

class Circle {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        output << "Point 1: " << C.P1 << endl << "Point 2: " << C.P2 << endl;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Circle &C ){
        input >> C.P1 >> C.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Circle(const Point &p1_t, const Point &p2_t){
        P1 = p1_t;
        P2 = p2_t;
    }
    Circle()  {
        P1.setx(0);
        P1.sety(0);
        P2.setx(0);
        P2.sety(0);
    }
    double Area()   {               //calculates the area
        double area;
        double radius;

        radius = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2)); //Line distance formula

        area = 3.14 * pow(radius, 2);

        return area;
    }

    double Diameter()   {               //Function that calculates the Diameter
        double radius;
        double diameter;

        radius = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2)); //Line distance formula
        diameter = 2 * radius;

        return diameter;
    }

    double Circumference()   {          //Function calculates the Circumference
        double circumference;
        double radius;

        radius = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2)); //Line distance formula
        circumference = 2 * 3.14 * radius;

        return circumference;
    }
    bool operator==(Circle &rhs)   {
        return (rhs.P1 == P1 && rhs.P2 == P2);
    }
    void displaycircle()   {
        double radius;
        radius = sqrt(pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2)); //Line distance formula
        cout << "Radius: " << radius << endl;
        cout << "Diameter" << Diameter() << endl;
        cout << "Circumference: " << Circumference() << endl;
    }


private:
    Point P1, P2;

};

int main(){

   Circle C1;
   Circle C2;

   cout << "Enter points for radius 1: ";
   cin >> C1;
   cout << endl;
   cout << "Enter points for radius 2: ";
   cin >> C2;
   cout << endl;

   cout << "Circle 1: " << endl << C1 << endl;
   C1.displaycircle();
   cout << endl;

   cout << "Circle 2: " << endl << C2 << endl;
   C2.displaycircle();
   cout << endl;

   if(C1==C2)   {
       cout << "Circles are equal" << endl;
   }
   else   {
       cout << "Circles are not equal" << endl;
   }
    return 0;
}
