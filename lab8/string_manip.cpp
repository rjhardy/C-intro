// Ryan Hardy
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}
void stringManip::setString(string input){
    tobeEdited = input;
}

void stringManip::chop(){
    int x = tobeEdited.length();
    if(x != 0)   {
        while((isspace(tobeEdited.at(0))) || isspace(tobeEdited.at(x - 1)))   {
            if(isspace(tobeEdited.at(0)))   {
                tobeEdited.erase(tobeEdited.begin() + 0);
                x = tobeEdited.length();
            }
            if(isspace(tobeEdited.at(x - 1)))  {
                tobeEdited.erase(tobeEdited.begin() + (x - 1));
                x = tobeEdited.length();
            }
        }
    }
}

void stringManip::padString(int n){
    int x = tobeEdited.length();
    while(x < n)   {
        tobeEdited.append(" ");
        x = x + 1;
    }
}

void stringManip::center(int length)   {
    int x = tobeEdited.length();
    int count = 0;
    for(int i = 0; i < x; i++)   {
        if(isalpha(tobeEdited.at(i)))   {
            count = count + 1;
        }
    }
    for(int i = 0; i > count; i++)   {
        if(isspace(tobeEdited.at(i)))   {
            tobeEdited.erase(tobeEdited.at(i));
            x = tobeEdited.length();
        }
    }
    int count1 = 0;
    int count2 = 0;
    int difference = abs(length - x);
    int numSpaces = difference / 2;
    while(count1 < numSpaces && count2 < numSpaces)   {
        tobeEdited.insert(0, " ");
        count1 = count1 + 1;
        tobeEdited.insert((x), " ");
        count2 = count2 + 1;
        int x = tobeEdited.length();
    }
}

void stringManip::truncate(int n)   {
    int x = tobeEdited.length();
    while(x > n)   {
        tobeEdited.erase(tobeEdited.begin() + (x - 1));
        x = tobeEdited.length();
    }
}

void stringManip::removeNonAlpha()   {
    int x  = tobeEdited.length();
    int count = 0;
    for(int i = 0; i < x; i++)   {
        if(isalpha(tobeEdited.at(i)))   {
            count = count + 1;
        }
    }
    while(x > count)   {
        for(int i = 0; i < x; i++)   {
            if(!isalpha(tobeEdited.at(i)))   {
                tobeEdited.erase(tobeEdited.begin() + (i));
                x = tobeEdited.length();
            }
            x = tobeEdited.length();
        }
    }
}

void stringManip::convertToUpperCase()   {
    int x = tobeEdited.length();
    int i = 0;
    for(i; i < x; i++)   {
        if(islower(tobeEdited.at(i)))   {
            tobeEdited.at(i) = toupper(tobeEdited.at(i));
        }
    }
}

void stringManip::convertToLowerCase()   {
    int x = tobeEdited.length();
    int i = 0;
    for(i; i < x; i++)   {
        if(isupper(tobeEdited.at(i)))   {
            tobeEdited.at(i) = tolower(tobeEdited.at(i));
        }
    }
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123");

    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;


    return 0;
}
