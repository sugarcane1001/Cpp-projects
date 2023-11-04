/*
Fun program to play a tic-tac-toe game between two people.
*/

// To clear the screen each time, the program uses the library function “system”. The argument to system is 
// a command executed by the underlying operating system. This command is OS dependent.
// The line to be used with MS Windows is system("clear"). For Unix and its variants, use system("cls"). 

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void displayArray(char array[]) {
//Displays 1x9 array in 3 rows
    for ( int row = 0; row < 3; row++ ){
        for ( int col = 0; col < 3; col++ )
            cout << '\t' << array[col+row*3]; //Use row and col indexing the access each 1D array elements
        cout << endl << endl;
    }
}

// return value is:
// if the game is over, returns  X if X wins, O if O wins, T if there is a tie,
// else there are games left to be played, signaled by NULL (\0)
char score(char array[]){
    // Win if any of 3 rows same
    if ( array[0] == array[1] && array[1] == array[2] )
        return array[0];  
    if ( array[3] == array[4] && array[4] == array[5] )
        return array[3];
    if ( array[6] == array[7] && array[7] == array[8] )
        return array[6];

    // or any of 3 columns same
    if ( array[0] == array[3] && array[3] == array[6] )
        return array[0];
    if ( array[1] == array[4] && array[4] == array[7] )
        return array[1];
    if ( array[2] == array[5] && array[5] == array[8] )
        return array[2];

    // or any of 2 diagonals same
    if ( array[0] == array[4] && array[4] == array[8] )
        return array[0];
    if ( array[2] == array[4] && array[4] == array[6] )
        return array[2];
    // debugging code
    // cout << " In score. If we get here if there is no winner yet" << endl;

    int playsRemaining = 0;

    //  system ("cls");     // Use this if Windows
    system ("clear"); // Use this if Unix/Linux

    cout << "Tic-Tac-Toe" << endl;
    displayArray(array);

    //Comparing ASCII values
    for ( int i = 0; i < 9; i++) playsRemaining += (i + 1 + '0' == int (array[i]));
    cout << endl;
    cout << "There are " << playsRemaining
        << " plays yet to be made" << endl;

    if (0 == playsRemaining)
        return 'T'; 

    return '\0'; // if no winner, 
}

// calls displayArray() to display the array in rows.
// calls score to obtain the return values which are:
// if the game is over,
// returns  X if X wins, O if O wins, T if there is a tie,
// else there are games left to be played, signaled by NULL (\0)
char play( char p, char array[] ){
    char charMark;
    int mark;   //used for index value in the array
    char winner;
    cout << "Player " << p
        << ", please enter the number in the display (1 - 9)" 
        << endl
        << "where you wish your mark to be placed." << endl;

    cin >> charMark;
    mark = charMark - '0'; // deduct the ASCII value of '0' from charMark

    while ( array[mark-1]=='X' || array[mark-1]=='O' ) {//Use a method from cctype library to check if the move is legal
    //For example, if array[0] has already been updated with either X or O previously,
    //print the message below and wait for another input.
        cout  << "Illegal move. Place " << mark 
            << " is occupied." 
            << "\nPlease Make a different move." 
            << endl;
        cin >> charMark;
        mark = charMark - '0';
    }
    array[mark - 1] = p;

    //  system ("cls");     // Use this if Windows
    system ("clear"); // Use this if Unix/Linux

    cout << "Tic-Tac-Toe" << endl;
    displayArray(array);
    winner = score(array);
    if ( winner=='X' || winner=='O' ) //if winner is X or O
        cout  << "Player " 
            << winner 
            << " wins! Congratulations "
            << endl;
    else if ( winner=='T' ) //if it is a tie
        cout  << "Tie. Better luck next time. " << endl;
/*  Debug:  
    else if ( '\0' != winner )
    {  
        cout  << int (winner) << endl;
        cout  << "***** ERROR. return from score is " 
            << winner << endl;
        exit(1);
    }
*/
    return winner;
}

void playGame(char array[]){  
    // signal 'no winner yet' to get things started.
    char score = '\0'; 

    //  system ("cls");     // Use this if Windows
    system ("clear"); // Use this if Unix/Linux

    cout << "Tic-Tac-Toe" << endl;
    displayArray(array);

    while( '\0' == score ){
        score = play('X', array);
        if ( score=='X' || score=='T' ) break; //if the value of score is T or X
        score = play('O', array);
        if ( score=='O' || score=='T' ) break; //if the value of score is T or O
/*      Debug
        else 
        {
            cout  << int( score ) << endl;
            cout  << "Something is WRONG. Code should not get here!" 
                  << endl;
            exit(1);
        }
*/
    }
}

int main()
{
    char array[10];

    //initialize array prior to playing
    for ( int i = 0; i < 10; i++)
        array[i] = char ( '1' + i );
    array[9] = '\0';    

    playGame(array);
    return 0;
}
