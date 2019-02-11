#include <iostream>
#include <cmath>

using namespace std;

int whichQuadrant(float x, float y)   {
    if(x == 0 && y == 0){
        return 'C';
    }
    else if(x > 0 && y > 0)   {
        return 1;
    }
    else if(x < 0 && y > 0)   {
        return 2;
    }
    else if(x < 0 && y < 0)   {
        return 3;
    }
    else if(x > 0 && y < 0)   {
        return 4;
    }
    else if(x == 0 && (y > 0 || y <0))   {
        return 'Y';
    }
    else if((x > 0 || x < 0) && y == 0)   {
        return 'X';
    }
}


int main()   {
    float x;
    float y;
    cin >> x;
    cin >> y;
    cout << whichQuadrant(x,y) << endl;
}
