/*
 * Project Title:
 * - The Great Escape
 * Description:
 * This program is and escape game that consist of main and 6 functions. Thses functions hold a majority of the game code.
 * This game progesses linearly as each function calls the next.
 *
 * Developers:
 * - Ryan Hardy - hardyrd@mail.uc.edu
 * - Tom Luers - studentk@mail.uc.edu
 *
 * Help Received:
 * Student: Peyton Hicks
 *
 *
 *
 * Special Instructions: // optional
 * No special instructions should be needed
 *
 *
 * Developer comments: // Not optional
 * Developer 1: Ryan
 * Developed the shop, kitchen, basement, and end functions. Learned how to manage functions and if-else statements in programs hundreds of line long.
 * Developer 2: Tom
 * Developed the library and classroom functions. Learned how to manage functions and if-else statements in programs hundreds of line long.
 */
#include <iostream>

using namespace std;

void library ();
void shop ();
void classroom();       //this declares all five room functions
void kitchen();
void basement();
void end();



int main()   {

    cout << "You wake up in a room dazed and confused. Something is off with this place and you must to escape!!" << endl;
    cout << "There are five rooms you must work your way through" << endl;
    library();
    return 0;
}

/* Function Name: Library
 *
 * Function Description:
 * Code for the library room
 *
 * Parameters:
 * No parameters but holds variables for items and choices
 *
 *
 * return value:
 * calls to shop
 */

void library()   {
bool choice = false;
char uselessvar;
bool choice2 = false;        //used this to fix a problem with a variable being uninitialized


A:
cout<<"You wake up and look around."<<endl<<"You are in a library full of books."<<endl<<"You see only one way out, and it is a door with a 4 digit code on it."<<endl<<"Anyway, you look around and see a librarian who"<<endl<<"has fallen asleep with a card in her hand."<<endl<<"You also hear a loud crash."<<endl;
cout<<endl<<"Do you go to the librarian (0) or investigate the loud noise (1)?"<<endl;

cin>>choice2;
if (choice2 ==true)   {       //You go investigate the loud sound
    cout<<"You decided to go and investigate the loud sound you heard earlier."<<endl<<"Upon arrival, you see that a stack of books has fallen."<<endl<<"You then decide to go see the librarian."<<endl;
    choice2 = false;

}
if(choice2 == false) {
    cout<<"You walk up to the librarian and notice"<<endl<<"she has a library card and a book with some numbers on it."<<endl<<"Do you take the book(0) or the library card(1)?"<<endl;
    cin>>choice2;

    if(choice2 == false)  {
        cout<<"You take the book, but in the process, you accidently wake up the librarian!"<<endl;
        cout<<"Librarian: 'Do you have a library card for that book'(Y/N)"<<endl;
        cin>>uselessvar;

        if(uselessvar == 'Y')   {
            cout<<"Librarian: You liar!"<<endl;
            cout<<"The librarian calls you out, takes the book back, and goes back to sleep."<<endl;
            cout<<endl<<"You lose. Do you want to play again?(Y/N)";
            cin>>uselessvar;
                if (uselessvar =='Y')   {
                    goto A;
        }
                else {
                    return;
                }
    }
        else {
            cout<<"Librarian: Well if you do not"<<endl<<"have a library card, you cannnot check it out."<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"You Lose!"<<endl;
            cout<<"Do you want to play again(Y/N)?"<<endl;
            cin>>uselessvar;
            if(uselessvar=='Y') {
                goto A;
        }
            else {
                return;
        }
    }
}

    if (choice2==true)   {
        B:
        cout<<"You decided to take the library card, but in doing so, you accidently wake the librarian up."<<endl<<"Librarian: 'What can I help you with?' "<<endl;
        cout<<endl<<"Do you ask to check out a book(0) or leave(1)"<<endl;
        cin>>choice;
        if(choice == true) {
            cout<<"You dont want to check out a book, so you decide to leave."<<endl<<"As you try to open the door, you realize its locked and you cannot leave"<<endl;
            cout<<"You are a moron. Who tries to leave a locked room by going"<<endl<<"through a locked door without the password? Obviously you,"<<endl<<"but well let you go back and change your answer.";
                   goto B;



        }

        if(choice==false)    {
            cout<<"You decided to check out a book. "<<endl;
            cout<<"The librarian picks up the book that was sitting on the desk, scans it, and hands it to you"<<endl;
            cout<<"After recieving the book, you notice a paper sticking out with 4 numbers on it."<<endl<<"You immediately think of the locked door"<<endl<<"You walk to the door and enter the code"<<endl<<"*click*"<<endl<<"The door is unlocked!"<<endl<<"Do you want to continue through the door(Y/N)?"<<endl;     //This gets you to the next room
            cin>>uselessvar;
            if ((uselessvar == 'Y') || (uselessvar == 'y'))     {
                shop();
                                                            }
                              }
        else{
            cout<<"Goodbye :)"<<endl;
            return;
                    }
    }

                        }


}

/* Function Name: shop
 *
 * Function Description:
 * Holds code for glasses shop room.
 *
 * Parameters:
 * holds varaiable like bool glasses
 * char choice and code for the key pad.
 *
 * return value:
 * calls to classroom
 */

void shop()   {                 //function for shop room
    bool glasses = false;
    char choice = 'Y';
    int code = 1758;
    int code_enter = 0;

    A:
    cout << "You walk through the door and enter a glasses shop." << endl << "You notice there is only one way out. It requires a key code to leave" << endl;
    cout << "You can either look at some glasses(Y), or talk to the receptionist(N)." << endl;
    cin >> choice;

    if (choice == 'Y')   {
        cout << "you look at many types of glasses. You begin to leave in disapointment right as one catches your eye." << endl << "Do you investigate? (Y) to investigate or (N) to leave" << endl;
        cin >> choice;
        if (choice == 'Y')   {
            cout << "You pick up the glasses and put them on." << endl << "You notice that there is a 5 digit code on the wall that is 1758." << endl;
            glasses = true;
            cout << "You can (Y) walk over to the keycode and enter it in or (N) ignore it and continue enjoying your glasses" << endl;
            cin >> choice;
            if ((choice == 'Y') && (glasses = true))   {
                cout << "Enter the doors key code." << endl;
                cin >> code_enter;
                if(code == code_enter)   {
                    cout << "You did it! The door unlocks with as satisfying click." << endl;
                    classroom();
                }
                else {
                    cout << "Why wouldn't you leave moron?" << endl;
                    goto A;
                }
            }
            else  {
                cout << "You have solved the puzzle what are you thinking?!" << endl;
                goto A;
            }
            }
        else   {
            cout << "You go to try an open the door buy you dont have the KEYCODE." << endl;
            goto A;
        }
        }
    else   {
        cout << "The receptionist tells you to leave or buy something" << endl;
        goto A;
    }
    }

/* Function Name: classroom
 *
 * Function Description:
 * Holds the code for the classroom
 *
 * Parameters:
 * holds variable as char and bool for the game
 *
 *
 * return value:
 * calls to kitchen if completed
 */

void classroom()    {
char usefulvar;     //decision making variable. "do you want to do this(Y/N)"
bool uselesskey = false;//useless key lol

cout<<"You go through the door and walk"<<endl<<"into a classroom filled with desks and"<<endl<<"writing on the chalk board."<<endl;
cout<<"It appears that the door is again locked, with a key and a password "<<endl;
cout<<"As you walk around, you see"<<endl<<"a trashcan overflowing with papers."<<endl;
A:
cout<<"Do you want to search the"<<endl<<"trashcan?(Y/N)"<<endl;
cin>>usefulvar;
if((usefulvar == 'Y') || (usefulvar == 'y'))    {
    cout<<"You decide to check in the"<<endl<<"trashcan and find a key"<<endl;
          uselesskey = true;
    cout<<"Now that you have the key, do"<<endl<<"you want to try it in the door(Y/N)?"<<endl;
    cin>>usefulvar;
    if((usefulvar == 'Y') || (usefulvar == 'y'))    {
        cout<<"You decide to try to unlock the door."<<endl<<"As soon as you put the key in,"<<endl<<"you are electrocuted and die. Rip you"<<endl;
        cout<<"Do you want to play again?(Y/N)"<<endl;
        cin>>usefulvar;
            if((usefulvar=='Y')||(usefulvar=='y'))   {
                library();
}               //end usefulvar if
    else {
        cout<<"Goodbye :)";
            return;
}
}       //end else
}       //end if

if((usefulvar == 'N') || (usefulvar == 'n'))    {
    cout<<"You decide not to search in the"<<endl<<"trashcan. Probably a smart move, but who"<<endl<<"am I to say anything?"<<endl;
    cout<<"You start to observe your surroundings"<<endl<<"a little more and you decide to"<<endl<<"look at the chalk board"<<endl;
    cout<<"It's very dirty. Do you clean it?(Y/N)"<<endl;
    cin>>usefulvar;
    if((usefulvar == 'N') || (usefulvar == 'n')) {
            cout<<"Well, you have to pick the trash can"<<endl<<"or clean the chalk board, so"<<endl<<"lets try this again shall we?(Y/N)"<<endl;
            cin>>usefulvar;
            if((usefulvar == 'Y') || (usefulvar == 'y'))    {
            goto A;
}           //end if

            else {
                cout<<"Goodbye"<<endl;
                return;
            }

}
    else {
        cout<<"You go to the board and find an eraser. You clean the chalk board, revealing"<<endl<<"the numbers 1256. It must be the code to the door!"<<endl<<"You enter the code and..."<<endl<<"*click*"<<endl<<"The door unlocked!"<<endl;
        cout<<"Do you want to continue into the next room?(Y/N)"<<endl;
        cin>>usefulvar;
                if((usefulvar == 'Y') || (usefulvar == 'y'))
                  kitchen();
                else {
                   return;
                  }
    }
}    //end if




       //end else

}       //end classroom()

/* Function Name: Kitchen
 *
 * Function Description:
 * Holds the code for the kitchen room
 *
 * Parameters:
 * holds the bool bread and char choice
 * Also has intereger code for key pad which is check later on.
 *
 * return value:
 * calls basement
 */


void kitchen()   {              //function for kitchen room
    bool bread = false;
    char choice = 'A';
    int code = 1234;
    int code_enter = 0;

    E:

    cout << "You walk through the door and directly into a kitchen." << endl << "The kitchen is extremely modern and clean. Sharp angles every where."  << endl << "You see the basement door has a key pad on it" << endl;
    cout << "You see countertops, cabinets, and drawers." << endl << "You can search the cabinets and drawers.(Y)" << endl << "Or you can search the Countertops(N)" << endl;
                            //Making the choice of where to search
    cin >> choice;
    if(choice == 'Y')  {
        D:
        cout << "You begin to look through the cabients and drawers." << endl << "as you search you find some bread in a cabinet" << endl;
        cout << "Do you take the bread(Y) or leave it? (N)" << endl;
        cin >> choice;

        if(choice == 'Y')   {
            cout << "You take the bread. Realizing just how hungry this adventure has made you." << endl;
            cout << "As you finish you search you notice there is a toaster on the counter top" << endl;
            bread = true;
            F:
            cout << "Do you investigate?(Y/N)" << endl;

            cin >> choice;

            if((choice == 'Y') && (bread == true))   {                                       //Player will get the code for the door if they have bread
                cout << "You put the bread in the toaster and push it down with a satifying click" << endl;
                cout << "After a few moments the toaster bread pops out with a 'Ding'" << endl;
                cout << "As you move to pick up the bread you notice somthing has been toasted in..." << endl;
                cout << "Its a code that says 1234!" << "Then you remeber that the basement door has a keypad on it." << endl;
                cout << "Do you go to the door? (Y/N)" << endl;

                cin >> choice;

                if(choice == 'Y')   {
                    cout << "You enter the code. (type the code in)" << endl;
                    C:
                    cin >> code_enter;
                    if(code == code_enter)   {
                        cout << "The lock clicks open. A rush of cool air follows as the door creeps open revealing a damp staircase down to the basement." << endl;
                        basement();
                    }
                    else   {
                        cout << "Code is wrong try again" << endl;
                        goto C;
                    }
                } else   {
                    cout << "The toaster turns into a monster and destroys you" << endl;            //Silly endstate if they choose to not finish
                    goto E;
                }
            }
            else   {
            cout << "Go investigate you fool" << endl;
            goto F;
        }
        }                               //If the player doesn't choose to pick up the bread
        else   {
            cout << "You decide against taking the bread although you feel that you may want it later..." << endl;
            cout << "As you finish you search you notice there is a toaster on the counter top" << endl;
            cout << "You go to investigate(Y)" << endl;
            cin >> choice;
            if((choice == 'Y')  && (bread == true))   {
                cout << "You put the bread in the toaster and push it down with a satifying click" << endl;
                cout << "After a few moments the toaster bread pops out with a 'Ding'" << endl;
                cout << "As you move to pick up the bread you notice somthing has been toasted in..." << endl;
                cout << "Its a code that says 1234!" << "Then you remeber that the basement door has a keypad on it." << endl;
                cout << "Do you go to the door? (Y/N)" << endl;
            }
            else   {
                cout << "You dont have any bread moron!";
                goto D;
            }
        }
    }
    else   {                   //This is if the player decides to not investigate the countertops
        cout << "You decide to search the counter tops and notice a new toaster" << endl;
        cout << "you go to the toaster but have no reason to use it" << endl;
        goto E;
        }
}

/* Function Name: basement
 *
 * Function Description:
 * holds the code for the basement
 *
 * Parameters:
 *Holds the char key for escape and char choice for the choices the player makes.
 *
 * return value:
 * calls end function
 */

void basement()   {             //function for basement room IS IN PROGRESS FIXME
    char key = false;   //key
    char choice = 'A';
    A:
    cout << "You walk throught the door and are faced with stairs leading to a basement." << endl;
    cout << "Once you get to the basement, everything is pitch black." << endl;
    cout << "You can (Y) remain silent and move towards a wall or (N) call out for help and see if anybody is around." << endl;
    cin >> choice;

    if (choice == 'Y'){
        cout << "You begin moving around in hopes of findig a wall or quite possibly a way out of this place." << endl; // when you remain silent
        cout << "All of a sudden, you hear the quick and heavy patter of footseps in the opposite corner from you, so you hide behind one of the doors." << endl;
        cout << "You feel around and find two objects, which happen to be a flashlight and the other feels like a rock." << endl;   //After choosing
        cout << "You can (Y) toss the rock or (N) turn on the flashlight." << endl;

        cin >> choice;

        if (choice == 'Y') {
            cout << "You toss the rock from behind the door and hear the footsteps speed up towards the sound of the rock." << endl; //When tossing the rock
            cout << "After the rock is thrown you continue moving behind the doors." <<endl;
            cout << "The lights suddenly flicker and you catch a glimpse of a green figure with a big green eye in the corner and a glistening key in the center of the floor." << endl;
            cout << "You can either (Y) crawl slowly towards the center or (N) stay put." << endl;

            cin >> choice;

            if(choice == 'Y')   {
                cout << "You begin crawling towards the key." << endl; // Story of crawling towards the key
                cout << "Your silience and quick thinking is rewarded." << endl;
                key = true;
                cout << "You grab the key and make your way towards the door" << endl;
                cout << "Do you want to escape(Y/N)" << endl;
                cin >> choice;
                if((choice = 'Y') && (key = true))   {
                    cout << "You silently unlock the door and escape!!" << endl;
                    end();
                }
                else   {
                    cout << "Mike wazowski spots in an instant and slices you open!" << endl;
                    goto A;
                }
            }
            else  {
                cout << "Your hesitation is going to get you killed make a choice!" << endl;
                cout << "Do you go leave? (Y/N)" << endl;
                cin >> choice;
                if(choice == 'Y')   {
                    cout << "the creature sees you in an instant with no time to escape!" << endl;
                    cout << "The last thing you feel is sharp pain..." << endl;
                    goto A;
                }
                else   {
                    cout << "You see door that looks like it will be your escape..." << endl;
                    cout << "Do you run for it? (Y/N)" << endl;
                    key = false;
                    cin >> choice;
                    if((choice == 'Y') && (key == true))   {
                        cout << "You rush to the door and unlock it to make a quick escape!!!" << endl;
                        end();
                    }
                    else   {
                        cout << "You go to unlock the door but you dont have the key!!" << endl;
                        cout << "The green monster finally finds you and eats you!" << endl;
                        goto A;
                    }
                }
            }

        }else{
            cout << "You turn on the flashlight and you see a tiny green body fly past the light and disappear into the darkness."<< endl;
            cout << "You hear the figure get closer to you, when all of a sudden it is right beside you." << endl;
            cout <<"The last thing you see is a green hand with long sharp nails and a giant eyeball. " <<endl;
            goto A;
    }
    }else{
        cout << "Your hear something stratch along the wooden floor and move towards your direction..." << endl; //When call out for help is chosen
        cout <<"The last thing you see is a green hand with long sharp nails and a giant eyeball. " <<endl;
        goto A;
}
}

/* Function Name: End
 *
 * Function Description:
 * Last function called to end the game
 *
 * Parameters:
 * doesnt pass parameters just holds the code for the ending
 *
 *
 * return value:
 * 0 ends game.
 */

void end()   {
    cout << "CONGRATULATIONS YOU MADE IT AND ESCAPED!" << endl;
    cout << "thanks for playing the game" << endl;
            }
