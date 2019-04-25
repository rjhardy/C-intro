/*
 * Project Title:
 * Evolution
 * Description: 2D array based game that involes the evolution of cells
 * This program does.......
 *
 * Developer:
 * Ryan Hardy hardyrd@mail.uc.edu
 *
 * Help Received:
 * Online research
 *
 *
 * Special Instructions:
 * If u want to change the text file the game runs off then you will have to change the ifstream path in the code.
 * You can see the path now in the code. I will upload the text file so you can see the numbers i used. You will have to
 * change the path to something simular like mine inorder to get it to work.
 * Once it is run it tells you what to do.
 *
 * Developer 1:
 * This project helped me learn how to develop with object oriented programming.
*/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int gridSize = 25;
void printGrid(bool gridOne[gridSize+1][gridSize+1]);
void determineState(bool gridOne[gridSize+1][gridSize+1]);
void clearScreen(void);

int main(){

    cout << "                                   EVOLUTION "<< endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Rules" << endl;
    cout << "each of which is in one of two possible states, life or dead. Every" << endl;
    cout << "cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent." << endl;
    cout << "The Evolution rules were modified form the rules of the game of life:" << endl;
    cout << "1. Any live cell with fewer than 4 live neighbours dies, as if caused by under-population." << endl;
    cout << "2. Any live cell with four live neighbours lives on to the next generation." << endl;
    cout << "3. Any live cell with more than 6 live neighbours dies, as if by over-population." << endl;
    cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
    cout << endl;
    cout << "Also universe changing rules can abruptly impact how the cells respond" << endl;
    cout << "O - living cell" << endl;
    cout << ". - dead cell" << endl;
    cout << endl;
    cout << "Enter the number of cells, or 'r' to read cells from file: ";
    cout << endl;

    ifstream inFS;      //input file steam

    system( "color A" );
    bool gridOne[gridSize+1][gridSize+1] = {};
    int x,y,n;
    string nc;
    string start;
    string filename;        //string file name is here

    cin >> nc; //insert command

    if ( nc == "r" )
      {
    while (true)
      {

        cout << "File name is already inputed: "<<endl;
                                                            //cin  >> filename;

                                                            //try to open file

        inFS.open("C:\\Ryan\\testboard2.txt");

        if (!inFS.is_open()) {
            cout << "could not open file " << filename << endl;
            return 1;
        }
        else {
            string fileline,xx,yy;

            while (getline(inFS,fileline))
              {
                stringstream ss(fileline);

                getline(ss,xx,' ');
                getline(ss,yy,' ');

                x = stoi(xx);
                y = stoi(yy);

                gridOne[x][y] = true;
              }
            break;
        }
      }
      }
    else
      {

    for(int i=0;i<stoi(nc);i++)
      {
        cout <<stoi(nc)<< "Enter the coordinates of cell " << i+1 << " : ";
        cin >> x >> y;
        gridOne[x][y] = true;
        printGrid(gridOne);
      }
      }
    cout << "Grid setup is done. Start the game ? (y/n)" << endl;
    printGrid(gridOne);
    cin >> start;
    if( start == "y" || start == "Y" )
      {
        while (true)
      {
            printGrid(gridOne);
            determineState(gridOne);
            usleep(200000);
      }
      }
    else
      {
        return 0;
      }
}

//Main ends here!!


/* Function Name: printGrid
 *
 * Function Description:
 * boolean function that prints the grid
 * the game uses
 *
 * Parameters:
 * parameter one is gridOne,
 * works off gridSize
 *
 * return value:
 * returns grid. I learned a lot
 */


//class Gameboard   {

//public:

void printGrid(bool gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == true)
            {
                cout << " O ";
            }
            else
            {
                cout << " . ";
            }
            if(b == gridSize-1)
            {
                cout << endl;
            }
        }
    }
}


/* Function Name: CompareGrid
 *
 * Function Description:
 * This funtion compares the gridOne with gridTwo. Involes the cells
 * and compares their location
 *
 * Parameters:
 * Parameter of gridOne
 * Parameter of gridTwo
 *
 * return value:
 * Learned how to compare the two grid. Returns that information
 */


void compareGrid (bool gridOne[gridSize+1][gridSize+1], bool gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}
//};              //This is the end of the game board class


/* Function Name: DetermineState
 *
 * Function Description:
 * D
 *
 * Parameters:
 * runs the information of gridOne through
 * to check the state of the cell. aka Dead or Alive
 *
 * return value:
 * This is where the rules were changed. Returns the state of the cells dead of alive
 */

//class Cell {

//public:

void determineState(bool gridOne[gridSize+1][gridSize+1]){
    bool gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);

    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)                 //Rules are changed here when determing the state of the cells
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(gridTwo[a+c][b+d])
                {
                    ++alive;
                }
                    }
                }
            }
            if(alive < 2)
            {
                gridOne[a][b] = false;
            }
            else if(alive == 3)
            {
                gridOne[a][b] = true;
            }
            else if(alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }
}
//};
