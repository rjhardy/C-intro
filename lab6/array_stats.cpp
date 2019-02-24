#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int rand_num(int start, int end)   {  //maybe should delete
    int randNum;
  //FIX complete else if statement
     randNum = rand() % end + start;
     return randNum;
}

int sampleVector(int end, int sample)   {
    vector<int> frequency(end);

    int i;
    for(i = 0; i < sample; i++)   {
        int random = rand_num(0, end);
        frequency.at(random) += 1;
    }
    return frequency;
}

int maxVector()   {

}

int minVector()   {

}

//This function determines the sum of the vector
int sumVector(vector<int> v)   {
    int i;
    int sumVal = 0;
    for(i = 0; i < v.size(); ++i)    {               //should be looking for some vector. Have it set as frequency for now
    sumVal = sumVal + v.at(i);
}
    return sumVal;
}

int meanVector()   {

}


int main()   {
int end;
int sample;

cout << "Enter the end value" << endl;
cin >> end;

cout << "Enter the number of samples";
cin >> sample;

vector<int> v = sampleVector(end, sample);

//This begins the statistics functions outputs

cout << "Sum " << sumVector(v) << endl;

}
