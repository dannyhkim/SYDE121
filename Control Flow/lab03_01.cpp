// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 2
// Filename: lab03_01.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Prime Numbers, Palindromic Prime Numbers, and Prime Numbers with sum of digits that are odd
// Purpose: Finds all prime numbers, indicates palindromic prime numbers, and prime numbers where their sum of digits is odd
// Due Date: Friday, September 28, 2018

/*
 In the beginning, I tested the value of 13 to make sure all the early common prime numbers were being indicated
 as palindromic, and that their sum of digits were odd (because numbers like 3, 5, 7 are).
 Later, I tested values like 100, 267, and 1000 to see if the program was correctly indicating prime numbers as
 palindromic or sum of digits odd for higher valued numbers.
 I also inputted 101 to check if the program would indicate 101 as palindromic at the end.
 Theoretically speaking, this program should work for values from 2 all the way up to the maximum integer range,
 which is 2,147,483,647. However, this may not be reasonable for the user as it will take very long for the program
 to compute all those prime numbers. I would suggest keeping the upper bound input at 100,000.
 */

#include <iostream>

using namespace std;
int main() {
    //Variable declaration
    int num;
    int counter = 0;
    //Asks user for integer. cin retrieves number from user.
    cout << "Enter an integer greater than 1. We will find all prime numbers up to that integer." << endl;
    cin >> num;

    //If user inputs an invalid number, the program will keep asking for valid number until user inputs a proper one.
    while (num <= 1)
    {
        cout << "Enter a number greater than 1. Please try again." << endl;
        cin >> num;
    }

    //nested for loop
    //first for loop is used to loop all the numbers from 2 to the inputted number.
    for (int i = 2; i <= num; i++)
    {
        //loops all numbers from 1 to one less value of the number being checked in order to check for factors
        for (int j = 1; j < i; j++)
        {
            //if there is no remainder when dividing, 1 is added to counter to keep track of factors
            if (i % j == 0)
            {
                counter++;
            }
        }
        //if there is only 1 factor in the number (divisible by 1), then we know that it is a prime number
        if (counter == 1) {
            cout << i << " is a prime number";

            //for all primes less than 10,000, we need to check if they are palindromic
            if (i < 10000) {
                int reversed_num = 0, remainder;
                int i2 = i;
                //use a while loop to reverse number
                while(i2 != 0) {
                    //modulus obtains last digit of number, assigns it to remainder
                    remainder = i2%10;
                    reversed_num = reversed_num*10 + remainder; // multiplies by 10 to have zero at the end, and then
                    // adds the single digit remainder to reverse the digit
                    i2 /= 10; //divided by 10 to get rid of last digit
                }
                //checks if reversed prime number equals prime number
                if (i == reversed_num) {
                    //indicates it is palindromic
                    cout << ", palindromic";
                }
            }
            //must check for all primes less than 100,000 if their sum of digits is odd
            if (i < 100000)
            {
                //variables used to find sum of digits
                int i3 = i;
                int temp, sum;
                sum = 0;
                //loop continues until prime number is 0
                while (i3 != 0){
                    //modulus to temporarily assign last digit of number to variable "temp"
                    temp = i3%10;
                    sum += temp; //adds value of last digit to sum
                    i3 /= 10; // gets rid of last digit of prime number
                }
                //checks if sum of digits is odd
                if (sum % 2 != 0)
                {
                    //indicates sum of digits of prime is odd
                    cout << ", sum of digits is odd";
                }

            }
            cout << "\n";
        }
            counter = 0; //resets the counter after looping through all divisors in 2nd for loop to start at 0 for next num
    }

    //program terminates
    return 0;
}