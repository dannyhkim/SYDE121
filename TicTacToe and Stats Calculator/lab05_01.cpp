// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 4
// Filename: lab05_01.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: 4x4 Tic-Tac-Toe
// Purpose: To allow two users to play 4x4 tic-tac-toe, give them the option to keep playing, and keep track of score.
// Due Date: October 26, 2018
// *********************************************************************************************************************

/* Testing Scenarios:
 * I first tested inputs of less than 1 and greater than 16 to check if program responded properly to that case by
 * saying it is an invalid input and allowing the player to re-enter a valid move.
 * I re-entered values on the board that were already taken to see if program would determine it to be an invalid
 * input and ask player to try again. I then simulated the game so that player X won with horizontal matches,
 * vertical matches, and both possible diagonal matches. I repeated the same for player O.
 * I also checked the case in which the entire board was full and there was no winning combinations, to see if program
 * could identify a tie game. Furthermore, I simulated a game in which a player won and the board was at full capacity
 * moves simultaneously to see if game would output that a player won the game instead of a tie.
 * I also played numerous games in a row to check if score was properly keeping track of wins and ties. This also
 * validated that the game was properly asking if users wanted to play again or not.
 */

#include <iostream>
#include <string>
using namespace std;

bool start_game();
// PURPOSE: Starts the tic-tac-toe game
// INPUTS: none
// RETURNS: returns true if the game(s) was run successfully, else, returns false

void input(string arr[4][4], int& move, string player, bool& game_cont, int& wins_X, int& wins_O, int& tie);
// PURPOSE: Handles the inputs made by the user and changes the values displayed on the board with X's and O's in
//          valid situations. Also checks for invalid inputs such as when the input is < 1 and > 16, and when the user
//          is trying to mark a location that is already marked.
// INPUTS: arr[4][4] - multidimensional string array holding the elements displayed on the tic-tac-toe board
//         move - integer value representing the location on board at which user would like to mark
//         player - string indicating the current player
//         game_cont - boolean controlling whether the current iteration of game should continue, or whether it is over
//         wins_X - number of games won by player X
//         wins_O - number of games won by player O
//         tie - indicates number of tie games between player X and O
// RETURNS: nothing

void has_won(string arr[4][4], int row, int col, bool& game_cont, int& wins_X, int& wins_O, int& tie);
// PURPOSE: Checks whether a player has won the game, or if a tie has occurred
// INPUTS: arr[4][4] - multidimensional string array holding the elements displayed on the tic-tac-toe board
//         row - indicates the index of the current row at which a move was made
//         col - indicates the index of the current column at which a move was made
//         game_cont - boolean controlling whether current iteration of game should continue or end
//         wins_X - number of games won by player X
//         wins_O - number of games won by player O
//         tie - indicates number of tie games between player X and O
// RETURNS: nothing

void print_board(string arr[4][4]);
// PURPOSE: Displays the current state of the tic-tac-toe board by printing multidimensional array
// INPUTS: arr[4][4] - multidimensional string array holding the elements displayed on the tic-tac-toe board
// RETURNS: nothing

int main() {

    // Calls boolean function that runs the game, and will continue to run more games if players choose to keep playing
    start_game();
    return 0;
}

// runs the entire tic-tac-toe game(s)
bool start_game(){

    bool cont = true; //boolean controlling whether more games are to be played if decided by players
    bool game_cont = true; //determines if the current iteration of a single game should continue or if it's over

    // Variable Declaration
    string player_X = "X", player_O = "O";
    string y_or_n;
    int games_played = 0;
    int wins_X = 0, wins_O = 0, tie = 0;
    int num_of_moves;

    // Players continue to play more games as long as cont == true
    while (cont){

        // Resets the tic-tac-toe board whenever a new game is started
        string game[4][4] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

        // Indicates value that player marked to change
        int move;

        // Switches which player begins the game depending on number of games played
        // If total number of games played is even, player X starts
        if(games_played % 2 == 0){
            num_of_moves = 1;
        // If total number of games played is odd, player O starts
        } else if(games_played % 2 != 0){
            num_of_moves = 0;
        }
        // Welcome message
        cout << "Welcome to 4x4 tic-tac-toe.\n" << endl;

        // Switches the players' turns based on number of moves in game, and allows them to make moves
        for (int i = 0; i < 16 && game_cont; i++){

            // Displays board every time a player makes a move
            print_board(game);

            // If total number of moves is odd, player X's turn
            if (num_of_moves % 2 != 0){
                cout << "Player " << player_X << ", enter the position you want to mark." << endl;
                cin >> move;
                num_of_moves++; // increases total number of moves played in single game
                // Calls function that handles the inputs and changes the board marks
                input(game, move, player_X, game_cont, wins_X, wins_O, tie);
            // Player Y's turn
            } else{
                cout << "Player " << player_O << ", enter the position you want to mark." << endl;
                cin >> move;
                num_of_moves++; // increases total number of moves played in single game
                // Calls function that handles the inputs and changes the board marks
                input(game, move, player_O, game_cont, wins_X, wins_O, tie);
            }
        }
        // Once game is finished, increases games played counter
        games_played++;

        // Asks users if they would like to play another game
        cout << "Would you like to play another game? Enter \"Y\" or \"N\"." << endl;
        cin >> y_or_n;

        if (y_or_n == "Y"){
            cont = true;
            game_cont = true;
        } else if (y_or_n == "N"){
            cont = false;
        } else {
            cout << "That is an invalid input. Game is exiting.\n" << endl;
            cont = false;
        }
    }

    // Outputs the score after the game play session
    cout << "Thank you for playing!" << endl;
    cout << "Player X wins: " << wins_X << endl;
    cout << "Player O wins: " << wins_O << endl;
    cout << "Ties: " << tie << endl;

    return true;
}

// Displays the current iteration of the tic-tac-toe board
void print_board(string arr[4][4]){

    // Display the 4x4 game board
    for (int row = 0; row < 4; row++){
        for (int col = 0; col < 4; col++){
            cout << arr[row][col] << "\t\t";
        }
        cout << "\n";
    }
    cout << endl;
}

// Input function - checks validation of inputs, replaces values on board with X and O marks made by player
void input(string arr[4][4], int& move, string player, bool& game_cont, int& wins_X, int& wins_O, int& tie){

    bool move_exists = false;

    do {
        for (int row = 0; row < 4; row++){
            for(int col = 0; col < 4; col++){
                // If player input is equal to a value displayed on board, replaces value on board with player's mark
                if(arr[row][col] == to_string(move)){
                    arr[row][col] = player;
                    // boolean indicates whether a valid move was made by player
                    move_exists = true;
                    //Function checks if a player has won game.
                    has_won(arr, row, col, game_cont, wins_X, wins_O, tie);
                }
            }
        }
        // If move is invalid, asks user to try and input a valid number
        if (!move_exists || move < 1 || move > 16){
            cout << "That is an invalid input. Please try again." << endl;
            cin >> move;
        }
      // Continues to iterate until player makes a valid move
    } while (!move_exists || move < 1 || move > 16);
}

// Checks if a player has won, or if tie has occurred
void has_won(string arr[4][4], int row, int col, bool& game_cont, int& wins_X, int& wins_O, int& tie){

    // Win conditions for player X and O
    string player_X_win = "XXXX";
    string player_O_win = "OOOO";
    // Initialize 4 strings that represent 4 cases we need to check to see if a player has won
    string case1 = "", case2 = "", case3 = "", case4 = "";

    // Find the bottom to top diagonal sequence of moves
    for (int i = 0; i < 4; i++)
        case1 += arr[3 - i][i];

    // Find the top to bottom diagonal sequence of moves
    for (int i = 0; i < 4; i++)
        case2 += arr[i][i];

    // Finds horizontal sequence of moves at row in which most recent move was made
    for (int i = 0; i < 4; i++)
        case3 += arr[row][i];

    // Finds vertical sequence of moves at column in which most recent move was made
    for (int i = 0; i < 4; i++)
        case4 += arr[i][col];

    //Checks if board is fully occupied with moves, and there is no win condition
    int count = 0;
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == "X" || arr[i][j] == "O"){
                count++;
            }
        }
    }

    // Checks if any of 4 cases equal to player X winning
    if(case1 == player_X_win || case2 == player_X_win || case3 == player_X_win || case4 == player_X_win){
        // Outputs congratulations message for X
        cout << "Player X has won the game!\n" << endl;
        print_board(arr);
        // Ends current iteration of the game
        game_cont = false;
        wins_X++;
    // Checks if any of 4 cases equal to player O winning
    } else if (case1 == player_O_win || case2 == player_O_win || case3 == player_O_win || case4 == player_O_win){
        cout << "Player O has won the game!\n" << endl;
        print_board(arr);
        // Ends current iteration of game by making boolean false
        game_cont = false;
        wins_O++;
        // If all the marks on the board are O's and X's, and there is no winning combination, game is tied.
    } else if(count == 16){
        cout << "It's a tie game!\n" << endl;
        print_board(arr);
        game_cont = false;
        tie++;
    }
}
