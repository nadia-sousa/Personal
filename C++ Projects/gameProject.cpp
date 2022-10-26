#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime> 


int locX = 2; //initial horizontal location
int locY = 2; //initial vertical location
int turns = 20; //total of turns player begins with 


void obs1() //function def for obstacle 1
{
    int tries = 2; //tries user has until game over 
    char ansr1, ansr2; //stores value for first answer, then second 
    cout << "\nQuestion: What character(s) do you need to put before writing a comment?\n (type corresponding letter)\n";
    cout << "a. //    b. ;    c. ::    d. %\n"; //prompts user with questions and choices
    cin >> ansr1; //user prompts first answer
    while (tries > 0) //condition for when the tries > 0
    {
        if (ansr1 == 'a') //condition if user inputs 'a'
        {
            cout << "\nCorrect!\n"; //displays message 
            break; //breaks from function
        } else //if user inputs anything other than 'a'
        {
            cout << "\nWrong! Try again!\n"; //displays message 
            tries --; //tries decrease by 1
            cin >> ansr2; //user attempts second time with second answer
            if (ansr2 == 'a') //condition if user inputs 'a'
            {
                cout << "\nCorrect!\n"; //displays message 
                break; //breaks from the function
            } else //if user answers incorrectly again
            {
                cout << "\nWrong again! Game over :(\n"; //displays message 
                tries = 0; //tries set to 0
                turns = 0;//turns set to 0
            }
        }
        
    }
       
}

void obs2() //function def for obstacle 2
{
    int tries = 2; //tries user has until game over
    char ansr1, ansr2; //stores value for first answer, then second
    cout << "\nQuestion: What are the contents in parenthesis next to a called function?\n (type corresponding letter)\n";
    cout << "a. condition    b. parameters    c. statement    d. none of the above\n"; //prompts user with questions and choices
    cin >> ansr1;//user prompts first answer
    while (tries > 0) //condition for when the tries > 0
    {
        if (ansr1 == 'b') //condition if user inputs 'b'
        {
            cout << "\nCorrect!\n"; //displays message
            break;//breaks from function
        } else //if user inputs anything other than 'b'
        {
           cout << "\nWrong! Try again!\n"; //displays message
            tries --; //tries decrease by 1
            cin >> ansr2; //user attempts second time with second answer
            if (ansr2 == 'b') //condition if user inputs 'b'
            {
                cout << "\nCorrect!\n"; //displays message
                break;  //breaks from the function
            } else //if user answers incorrectly again
            {
                cout << "\nWrong again! Game over :(\n"; //displays message
                tries = 0; //tries set to 0
                turns = 0; //turns set to 0
            }
        }
        
    }    
}

void obs3() //function def for obstacle 3
{
    int tries = 2;  //tries user has until game over
    char ansr1, ansr2; //stores value for first answer, then second
    cout << "\nQuestion: What loop includes the condition before its body? \n(type corresponding letter)\n";
    cout << "a. for     b. do while     c. while    d. for and while\n"; //prompts user with questions and choices
    cin >> ansr1; //user prompts first answer
    while (tries > 0) //condition for when the tries > 0
    {
        if (ansr1 == 'd') //condition if user inputs 'd'
        {
            cout << "\nCorrect!\n"; //displays message
            break; //breaks from function 
        } else //if user inputs anything other than 'd'
        {
           cout << "\nWrong! Try again!\n"; //displays message
            tries --; //tries decrease by 1
            cin >> ansr2; //user attempts second time with second answer
            if (ansr2 == 'd') //condition if user inputs 'd'
            {
                cout << "\nCorrect!\n"; //displays message
                break; //breaks from the function
            } else //if user answers incorrectly again
            {
                cout << "\nWrong again! Game over :(\n"; //displays message
                tries = 0; //tries set to 0
                turns = 0; //turns set to 0
            }
        }
        
    }   
}

void obs4() //function def for obstacle 4
{
    int tries = 2; //tries user has until game over
    char ansr1, ansr2; //stores value for first answer, then second
    cout << "\nQuestion: What comes before printing a message to the terminal? \n(type corresponding letter)\n"; 
    cout << "a. cin    b. ::    c. cout    d. int\n"; //prompts user with questions and choices
    cin >> ansr1; //user prompts first answer
    while (tries > 0) //condition for when the tries > 0
    {
         if (ansr1 == 'c') //condition if user inputs 'c'
        {
            cout << "\nCorrect!\n"; //displays message
            break; //breaks from function
        } else //if user inputs anything other than 'c'
        {
           cout << "\nWrong! Try again!\n"; //displays message
            tries --; //tries decrease by 1
            cin >> ansr2; //user attempts second time with second answer
            if (ansr2 == 'c') //condition if user inputs 'c'
            {
                cout << "\nCorrect!\n"; //displays message
                break; //breaks from the function
            } else //if user answers incorrectly again
            {
                cout << "\nWrong again! Game over :(\n"; //displays message
                tries = 0; //tries set to 0
                turns = 0; //turns set to 0
            }
        }
    }    
}

void obstacle(int locX, int locY) //function def for if user runs into obstacle/end of grid 
{
    if (locX < 0) //condition if horizontal loc is less than 0
    {
        cout << "\nWoahhh there you fell off the island! Game over. :(\n"; //displays message 
        turns = 1; //turns set to 1, will decrease to 0 to end game 
    } else if (locY < 0) //conditipn if vertical loc is less than 0
    {
        cout << "\nWoahhh there you fell off the island! Game over! :(\n"; //displays message 
        turns = 1; //turns set to 1, will decrease to 0 to end game
    } else if (locX > 4) //condition if horizontal loc is greater than 4
    {
        cout << "\nWoahhh there you fell off the island! Game over! :(\n"; //displays message 
        turns = 1; //turns set to 1, will decrease to 0 to end game
    } else if (locY > 4) //condition if vertical loc is greater than 4 
    {
        cout << "\nWoahhh there you fell off the island! Game over! :(\n"; //displays message 
        turns = 1;//turns set to 1, will decrease to 0 to end game
    } else if ( locX == 1 && locY == 4) //condition if loc is (1, 4)
    {
        cout << "\nYou've hit an obstacle!\n"; //displays message 
        obs1(); //calls function for first question/obstacle   
    }
    else if (locX == 1 && locY == 1) //condition if loc is (1, 1)
    {
        cout << "\nYou've hit an obstacle!\n"; //displays message 
        obs2(); //calls function for second question/obstacle
    } else if (locX == 3 && locY == 3) //condition if loc is (3, 3)
    {
        cout << "\nYou've hit an obstacle!\n"; //displays message 
        obs3(); //calls function for third obstacle/question
    } else if (locX == 4 && locY == 1) //condition if loc (4, 1)
    {
        cout << "\nYou've hit an obstacle!\n"; //displays message 
        obs4(); //calls function for fourth question/obstacle 
    } else //condition if no obstacle/endpoint is met 
    {
        cout << "\nGetting closer to your treasure! Keep going!\n"; //displays message 
    }
}

void location(char newLoc) //function def for the changing loc of user, carries parameter 'newLoc'
{
    if (newLoc == 'n') //condition if user chooses north
    {
        locY++; //vertical loc increases by 1
    } else if (newLoc == 's') //condition if user chooses south
    {
        locY--; //vertical loc decreases by 1 
    } else if (newLoc == 'w') //condition if user chooses west
    {
        locX--; //horizontal loc decreases by 1 
    } else if (newLoc == 'e') //condition if user chooses east 
    {
        locX++; //horizontal loc increases by 1 
    } else //condition if user inputs a different answer 
    {
        cout << "\nInvalid input, try again.\n"; //displays message, user tries again 
    }
    obstacle(locX, locY); //calls obstacle function carrying parameters of the current loc 
}

void treasureHunt(int treasureX, int treasureY, int pirateX, int pirateY) //defines treasureHunt function, carries parameters for treasure and pirate's loc
{
    char newLoc, ansr; //stores char values for the user's new location and answer to question
    while (turns > 0) //condition for while turns > 0 
    {
        int hintX = (rand() % 5); //randomizes horiz location of the hint throughout game
        int hintY = (rand() % 5); //randomizes vert location of the hint throughout game 
        if (locX == hintX && locY == hintY) //condition if player loc = hint loc 
        {
            int diffX = treasureX - locX; //calc horiz distance between player loc and treasure loc
            int diffY = treasureY - locY; //calc vert distance between player loc and treasure loc
            cout << "Wow! You found a magic compass! It tells you how far from the treasure you are!\n"; //displays message
            cout << "Hint: You are " << diffX << " steps horizontally and " << diffY << " steps vertically from your treasure.\n";
        }    
        if (locX == treasureX && locY == treasureY) //condition for if current loc = treasure loc 
        {
            cout << "\nLooks like you might have found something, but you need to answer this riddle first.\n"; //displays message 
            cout << "I come before a variable, mainly when it is greater than 10 or a decimal. (type corresponding \nletter, you only have one shot or game over)\n"; 
            cout << "What am I? \n a. int    b. double    c. float\n"; //displays choices 
            cin >> ansr; //user inputs their answer, only one shot 
            if (ansr == 'b') //condition for if answer = b
            {
                cout << "\nYOU FOUND THE TREASURE! YAY!\n"; //displays message 
                turns = 1; //turns set to 1, will decrease to 0 to end game
                break; //breaks from function
            } else //condition for if answer is incorrect 
            {
                cout << "\nWrong answer. Game over. :(\n"; //displays message 
                turns = 1; //turns set to 1, will decrease to 0 to end game
                break; //breaks from function 
            }
        } else //condition for if treasure loc isnt found 
        {
            cout << "\nWhere would you like to go? (enter n, s, e, w)\n"; //displays message 
            cin >> newLoc; //inputs answer for new loc 
            location(newLoc); //calls function for location carrying newLoc parameter 
            turns--; //number of turns decreases by 1 
            cout << "You have " << turns << " turns left.\n"; //displays message with amount of turns left 
            cout << "Current location: (" << locX << ", " << locY << ").\n"; //displays current loc 
            if (locX == pirateX && locY == pirateY) //condition if new loc =  pirate's loc 
            {
                cout << "\nOh no! You ran into a pirate! Answer his question to continue.\n"; //displays message
                cout << "Pirate: 'cin' is followed by >> (type corresponding letter, you only have one shot or \ngame over)\n";
                cout << "a. true    b. false\n"; //displays choices 
                cin >> ansr; //user inputs answer, only one shot  
                if (ansr == 'a') //condition for if user inputs 'a'
                {
                    cout << "\nCorrect! You gained 3 more turns!\n"; //displays message 
                    turns = turns + 3; //user is awarded 3 more turns 
                
                } else //condition for if answer is not 'a'
                {
                    cout << "\nWrong! You lost 5 turns!\n"; //displays message 
                    turns = turns - 5; //user loses 5 turns  
                }
                if (turns <= 0) //condition for if turns reach 0
                {
                    cout << "You have no turns left.\n"; //displays message, game will end 
                } 
            }
        } //temporarily displayed treasure, pirate, hint locs
    }     //showed how treasure and pirate are constant loc, hint is a changing loc
}

int main()
{
    srand(time(0)); //sets seed for random generator 
    int treasureX = (rand() % 5); //generates random x loc between 0 and 4 for treasure
    int treasureY = (rand() % 5); //generates random y loc between 0 and 4 for treasure 
    int pirateX = (rand() % 5); //generates random x loc between 0 and 4 for pirate 
    int pirateY = (rand() % 5); //generates random y loc between 0 and 4 for pirate 
    string playerName; //string stores player's name
    char ansr; //stores answer val 
    cout << "Please enter your name: "; //prompts user for name
    cin >> playerName; //player inputs their name 
    cout << "\nWelcome to the game " << playerName << "! Let's hunt for treasure!\n";
    //displays welcome message with user name 
    treasureHunt(treasureX, treasureY, pirateX, pirateY); //calls treasureHunt function with treasure and pirate loc 
    cout << "\nThanks for playing, " << playerName << "!\n"; //displays message after game is over 
    return 0;
} 