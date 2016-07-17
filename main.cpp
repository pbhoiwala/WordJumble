/* 
 * File:   main.cpp
 * Author: PARTH BHOIWALA
 *
 * Created on March 31, 2015, 11:25 AM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>



using namespace std;

string generateRandomWord();
void dispInst();


#define locateFile "G:\\CSc\\Personal practice ones\\WordJumbleGame\\dictionary2.txt"    
#define locateUser "G:\\CSc\\Personal practice ones\\WordJumbleGame\\userchoice.txt"
#define maxNum 69000

int main(int argc, char** argv) {

    dispInst();
    ifstream inputFile;
    ifstream userFile;
    userFile.open(locateUser);
    
    string mainWord;
    string hint;
    char playWith;
    cout << " DO YOU WANT TO PLAY WIH COMPUTER (C) or ANOTHER PLAYER (P)? : ";
    cin >> playWith;
    
    if (playWith == 'c' || playWith == 'C')
    {
         mainWord = generateRandomWord();
    }
    else if (playWith == 'P' || playWith == 'p')
    {
        userFile >> mainWord;
        getline(userFile, hint);
        hint = hint;
        //cout << " Enter a word. (Program will unscramble it) :  ";
        //cin >> mainWord;
    }
    else
    {
        cout << " *** ERROR: ENTER 'C' or 'P' ONLY ***" << endl;
    }
    int sizeWord = mainWord.length();
    
   
   // cout << " letters of word are: ";
    //for (int i =0; i < sizeWord; i++)
    //{
    //    cout << mainWord[i] << " ";
   // }
    cout << endl;
    
    // NOW LET'S SCRAMBLE IT
    char scramWord[20] = {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};
    int randScram = 0;
    
    int counter = 0;
    while(counter != sizeWord)
    {
        randScram = rand() % sizeWord;
        if (scramWord[randScram] == '*')
        {            
            scramWord[randScram] = mainWord[counter];
            counter++;
        }
        
    }
    
    
    
    
   // cout << endl << endl<< endl<< endl<< endl<< endl<< endl<< endl;
    cout << " scrambled word is : ";
    for (int i = 0; i < sizeWord; i++)
    {
        cout << scramWord[i];
    }
    cout << endl;
    
    
    // TIME TO PLAY WITH THE USER
    
    string userGuess = "xxx";
    int gameOver = 0;
    
    while( gameOver != 5)
    {
       
        cout << endl << " Guess the Word:  ";
        cin >> userGuess;
        
        if (userGuess == mainWord)
        {
            cout << " CONTRATS: YOU GOT IT !" << endl;
            break;
        }      
        
        else if (userGuess == "hint")
        {
            if (playWith == 'c' || playWith == 'C')
            {
                cout << " The word begins with '" << mainWord[0] << "' and ends with '" << mainWord[sizeWord-1] << endl; 
                // if playing with computer
            }
            else if (playWith == 'p' || playWith == 'P')
            {
                cout << endl;
                cout << hint << endl;
            }
            
        }
        else if (userGuess == "quit")
        {
            gameOver = 5;
           // break;
        }
        else
        {
            cout << endl << " Hmmm! Bad Guess! Try Again" << endl;
            gameOver = gameOver +1;
        }
    }
    
    if (gameOver == 5)
    {
        cout << endl << " Game Over " << endl;
        cout << " The Correct Word was: " << mainWord << endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    inputFile.close();
    
    return 0;
}

string generateRandomWord()
{
     ifstream inputFile;
    inputFile.open(locateFile);
    

    
    // GENERATE A RANDOM WORD
    string mainWord;
    srand (time(NULL));
    int randomNum = rand() % maxNum;
  //  cout << " randomNum is " << randomNum << endl;
    
    for (int i =0; i < randomNum; i++)
    {
        inputFile >> mainWord;
    }
    return mainWord;
    
}

void dispInst()
{
    cout << " !!!  WELCOME TO WORD JUMBLE !!! " << endl;
    cout << " ENTER 'c' TO PLAY WITH COMPUTER OR "<< endl;
    cout << " ENTER 'p' TO PLAY WITH ANOTHER PLAYER." << endl;
    cout << " ENTER 'hint' TO USE A HINT OR ENTER 'quit'" << endl;
    cout << " IF YOU WANT TO GIVE UP. ONLY 1 HINT WILL" << endl;
    cout << " GIVEN AND 5 MAXIMUM GUESSES WILL BE ALLOWED" << endl;
    cout << " ENJOY! " << endl;
    cout << endl << endl;
            
}