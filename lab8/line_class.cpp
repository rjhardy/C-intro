// Ryan Hardy

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// This is the version from Part B
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

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(const Point &p1_t, const Point &p2_t){
        P1 = p1_t;
        P2 = p2_t;
    }
    Line()  {
        P1.setx(0);
        P1.sety(0);
        P2.setx(0);
        P2.sety(0);
    }
    double slope()   {
        double temp;
        double tempTwo;
        temp = P1.gety() - P2.gety();
        tempTwo = P1.getx() - P2.getx();
        return temp/tempTwo;
    }

    double distance(){return(sqrt(pow(P2.getx() - P1.getx())))};
    double yintercept(){return(P1.gety() - (slope() * P1.getx()))};
    bool isHoriz()   {
        if (P1.gety() == P2.gety())   {
            return true;
        }
        else   {
            return false;
        }
    }
    void isPar()   {
        Point one;
        Point two;
        cout << "What line do you want to check?(Ex: 1 or 2)" << endl;
        cin >> one;
        cin >> two;
        Line lineOne(one,two);
        if(lineOne.slope() == slope())   {
            cout << "The lines are parallel" << endl;
        }
        else   {
            cout << "The lines are parallel" << endl;
        }
    }
    void display()   {
        cout << "Slope: " << slope() << endl
             << "Distance: " << distance() << endl
             << "y-intercept: " << yintercept() << endl
             << "Horizontal: " << isHoriz() << endl;

        isPar();

    }

private:
    Point P1, P2;
};

int main(){
    Point pointOne(3,9);
    Point pointTwo(2,5);
    Line L1;
    // Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;

    return 0;
}
