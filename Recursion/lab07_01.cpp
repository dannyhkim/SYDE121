// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 6
// Filename: lab07_01.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Bowling Pins with Some Complexity
// Purpose: To retrieve non-negative integer input from user and print a corresponding pattern of * symbols that
//          represents bowling pins in a special configuration.
// Due Date: November 14, 2018
// *********************************************************************************************************************

/* Testing Scenarios:
 * 1st test: 1
 * Made sure that 1 space was printed before and after * symbol as directed by instructions for assignment
 *
 * 2nd test: 2
 * Checked if pattern was correctly printed, with a total of 3 rows, and proper spacing
 *
 * 3rd test: 4
 * Checked if bowling pin pattern was correctly printed with correct number of spaces, rows, number of * symbols
 *
 * 4th test: 10
 * Checked if program could handle correctly printing patterns with greater number of * symbols in middle row
 *
 * Overall, I checked using various numbers from 1-50.
 */

#include <iostream>
using namespace std;

void run_program();
// PURPOSE: Runs the program to draw bowling pin pattern based on integer value inputted
// INPUTS: none
// RETURNS: none

void print_pattern(int n, int p, int total);
// PURPOSE: Prints a pattern of * symbols representing bowling pins in special configuration
// INPUTS: n - represents number of * symbols that are printed in 1st and last row of pattern
//         p - represents maximum number of * symbols printed in middle row
//         total - total number of spaces in a single row
// RETURNS: none (only prints pattern)

void print_row(int n, int total);
// PURPOSE: Prints a single row in the pattern
// INPUTS: n - number of * symbols in a single row
//         total - total number of spaces in a single row
// RETURNS: none (prints a row in the pattern)

int main() {

    run_program(); // calls function to run program of printing pattern

    return 0;
}

void run_program(){
    int n, total; // Variable declaration
    cout << "Enter a non-negative integer to create pattern." << endl;
    cin >> n;

    total = n * 2 + 1; // calculates total number of spaces in each row

    print_pattern(1, n, total); // calls function to print pattern
}

void print_pattern(int n, int p, int total){

    if(n >= p){ // base case
        print_row(n, total); // Prints the middle row with greatest number of * symbols
    }else{  // recursive case
        print_row(n, total); // Prints 1st row to pth row
        print_pattern(n + 1, p, total); // Adds 1 to n and recalls function
        print_row(n, total); // Prints remaining rows after largest row
    }
}

void print_row(int n, int total){

    int spaces = (total - (2 * n) + 1) / 2; // calculates number of spaces to print before first and last * symbol
                                            // in each row
    for(int i = 0; i < spaces; i++){ // loop iterates to print correct number of spaces
        cout << " ";
    }
    for(int i = 0; i < n; i++){ // loop iterates to print * symbols and correct number of spaces between each * symbol
        cout << "*";
        if(i + 1 != n){
            cout << " ";
        }
    }
    for(int i = 0; i < spaces; i++){ // loop iterates to print correct number of spaces after stars
        cout << " ";
    }

    cout << endl; // moves to next line after row is printed
}


