// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 6
// Filename: lab07_02.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: I LOVE C++
// Purpose: To check if a given string is a substring in a target string using a recursive function.
// Due Date: November 14, 2018
// *********************************************************************************************************************

/* Testing Scenarios:
 * target = "I love C++", substr = "love"
 * Checked if program returned true correctly with statement of "Substring inside target." outputted to console.
 *
 * target = " I LOVE C++", substr = "love"
 * Checked if program differentiated between lowercase and uppercase letters, returned false.
 *
 * target = "@Daniel", substr = "@Da"
 * Checked if program handled special symbols correctly as well, returned true.
 *
 * target = "12387", substr = "238"
 * Checked if program could detect substr of numbers within target, returned true.
 *
 * target = "I hate C++", substr = "te C++"
 * Checked if program returned true for substr and target containing spaces.
 *
 * target = "I love C++", substr = "loveC++"
 * Checked for false cases in which substr included no spaces, while target included spaces.
 *
 * target = "SYDE is best", substr = "hello"
 * Checked for obvious false cases
 *
 * Overall, I used a various combination of target and substr which included spaces, special symbols, numbers,
 * upper and lower cases.
 */

#include <iostream>
using namespace std;

bool check_if_contains(string target, string substr);
// PURPOSE: Checks if a given string is a substring in a target string
// INPUTS: target - the string that is checked to see if it contains the given substring
//         substr - the substring checked to see if it is contained inside target string
// RETURNS: Returns true if substr is a substring in target string, else, returns false

string move_letter(string target);
// PURPOSE: Shifts all of the char elements in the string to left by 1 index, with the last element being replaced
//          with null '\0' and the first element being removed
// Example: "SYDE" becomes "YDE\n"
// INPUTS: target - the string that is checked to see if it contains the given substring
// RETURNS: target - the modified target string with first element removed used to compare with substr

bool compare_str(string target, string substr);
// PURPOSE: Compares all "n" elements of substr with the first "n" elements of the target string to see if they match,
//          with n being natural number
// INPUTS: target - the string that is checked to see if it contains the given substring
//         substr - the substring checked to see if it is contained inside target string
// RETURNS: Returns true if all "n" substring elements match with the first "n" elements of target string, else
//          returns false

int main() {
    // Variable Declaration
    string target = "I love C++", substr = " love";

    // If the boolean returned evaluates to 0, then it's false, and substring is not inside target
    if(check_if_contains(target, substr) == 0) {
        cout << "Substring not inside target.";   // prints statements
    } else{ // otherwise, boolean evaluates to 1 and is true, so substring inside target
        cout << "Substring inside target.";
    }
    return 0;
}

bool check_if_contains(string target, string substr){

    if(target[0] == '\0') // Base case: If the target string is shortened until all its elements are null, then
        return false;     //            there were no matches with substr, so returns false
    else if(compare_str(target, substr)) // If compare_str function is true, then substr is contained within target
            return true;
    else
        return check_if_contains(move_letter(target), substr); // Recursive case: Calls function with new target string
}

string move_letter(string target){

    for (int i = 0; i < target.size() - 1; i++){ // iterates to reassign elements to new indexes
        target[i] = target [i + 1];
    }
    target[target.size() - 1] = '\0'; // last element in string becomes null
    return target;
}

bool compare_str(string target, string substr){
    for (int i = 0; i < substr.size(); i++){ // loop iterates to check if all "n" elements of substr match with first
                                             // "n" elements of target
        if (target.at(i) != substr.at(i)) // once a mismatch is detected, we know that substr not within target
            return false;
    }
    return true; // if no mismatches were detected, then we know that substr must be contained within target
}

