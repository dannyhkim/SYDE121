// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 4
// Filename: lab05_02.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Minimum, Maximum, Mean, and Population Standard Deviation Calculator
// Purpose: To allow users to input a list of double values with the list size being less than 21, and calculating
//          the max, min, mean, and std. dev. values from the list. Also allows users to modify the values in the list
//          and then outputs the recalculated set of values.
// Due Date: October 26, 2018
// *********************************************************************************************************************

/* Testing Scenarios:
 * 1st test: Entering a list containing less than 20 values to see if the statistics would calculate the figures
 * based on only those figures (Ex. Enter only 10 values).
 * 2nd test: Entering a list containing more than 20 values to see if program disregards all values after index 19.
 * 3rd test: Checking if entering "d" or "done" ended the inputting of values and outputted the calculated figures.
 * 4th test: Entering valid index values and replacing values at those indexes with new values to see if the statistics
 * outputted were updated.
 * 5th test: Entering invalid index values to see if program would notice them, and then inform user and allow them to
 * try again.
 * 6th test: Enter combination of valid and invalid index values to see if program would continue running with no issues
 * 7th test: Checking if the replacement of values stops once user enters "q" or "quit", and that program terminates.
 * Throughout all these tests, I manually calculated the minimum, maximum, mean, and standard deviation for some cases
 * to see if they were calculated correctly (Ex. Enter numbers 1-10. Min = 1, Max = 10, Mean = 5.50, Std. Dev. = 2.87)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

bool start_calc();
// PURPOSE: Starts the process of calculating all the statistics
// INPUTS: none
// RETURNS: returns true if the calculation processes were run successfully, else, returns false

void change_val(vector<double> &list);
// PURPOSE: Changes the values in the list by control of the user
// INPUTS: list - a vector containing all the values in the list
// RETURNS: none

void output_stats(vector<double> list);
// PURPOSE: Outputs all the statistics based on the values in the list
// INPUTS: list - a vector containing all the values in the list
// RETURNS: none

double calc_min(vector<double> list);
// PURPOSE: Finds the minimum value in the list
// INPUTS: list - a vector containing all the values in the list
// RETURNS: minimum - min value in the list

double calc_max(vector<double> list);
// PURPOSE: Finds the maximum value in the list
// INPUTS: list - a vector containing all the values in the list
// RETURNS: maximum - max value in the list

double calc_mean(vector<double> list);
// PURPOSE: Calculates the mean from the values in the list
// INPUTS: list - a vector containing all the values in the list
// RETURNS: mean - the "average" of the values in the list

double calc_std_dev(vector<double> list);
// PURPOSE: Calculates the population standard deviation from the values in the list
// INPUTS: list - a vector containing all the values in the list
// RETURNS: std_dev - a quantity calculated to indicate the extent of deviation for a group as a whole

int main() {

    // Calls function to run calculations
    start_calc();
    return 0;
}

bool start_calc(){

    // Initializes double vector that will contain list of values in future
    vector<double> list;
    string input;

    // Asks users to enter a list of double values with the list size being < 21.
    cout << "Enter a list of double values of size less than 21. Enter \"d\" or \"done\" when finished." << endl;

    // for loop iterates to retrieve value inputs
    for(int i = 0; cin.fail() == false; i++) {

        cin >> input;
        // If user inputs "d" or "done", they are done inputting values
        if(input == "d" || input  == "done") {
            break;
        }
        // Values are introduced into the double vector
        list.push_back(stod(input));
    }

    // If the vector list size is greater than 20, ignore all values greater than the index of 19
    if (list.size() > 20){
        list.resize(20);
    }

    // Outputs the statistics by calling function
    output_stats(list);

    // Gives users option of changing values in the list by calling function
    change_val(list);

    return true;
}

// Outputs the statistics by calling functions that return double values of each statistic calculated
void output_stats(vector<double> list){

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); // Formats statistics to two decimal places
    cout << "Statistics" << endl;
    cout << "Minimum: " << calc_min(list) << endl;
    cout << "Maximum: " << calc_max(list) << endl;
    cout << "Mean: " << calc_mean(list) << endl;
    cout << "Population Standard Deviation: " << calc_std_dev(list) << endl;

}
// Function that replaces values in the list with new ones that user inputs
void change_val(vector<double> &list){

    // Variable Declaration
    string index_val;
    int real_index;
    double val;

    // While loop iterates to ask users for indexes at which they want to change values, then users input new values
    while (cin.fail() == false){
        cout << "\nYou may now replace values in the list if you wish. Enter an index value for an element you would like "
                "to replace. Otherwise, enter \"q\" or \"quit\" to quit." << endl;
        cin >> index_val;
        // If user inputs "q" or "quit", user is done replacing values in list
        if (index_val == "q" || index_val == "quit"){
            cout << "Goodbye!" << endl;
            break;
        }
        // Converts index numbers from string to integer in case that user doesn't quit
        real_index = stoi(index_val);

        // If the user input does not equate to a valid index number in the vector, ask them to try again.
        if (real_index < 0 || real_index > list.size()){
            cout << "That is an invalid index. Please try again." << endl;
        }else{
            cout << "What value would you like to replace this element with?" << endl;
            cin >> val;
            // Replace the value at real_index with the new value inputted by the user
            list.at(real_index) = val;
            // Output the statistics calculated based on the new changes
            output_stats(list);
        }

    }

}

double calc_min(vector<double> list){
    double min = list[0];
    for (int i = 0; i < list.size(); i++){
        // Iterates through loop to make min equal to the element with lowest value
        if (list[i] < min){
            min = list[i];
        }
    }
    return min;
}

double calc_max(vector<double> list){
    double max = list[0];
    for (int i = 0; i < list.size(); i++){
        // Iterates through loop to make max equal to element with greatest value
        // If the current element is greater than the current max, replace max with the current element
        if (list[i] > max){
            max = list[i];
        }
    }
    // Returns maximum value of the double vector list
    return max;
}

double calc_mean(vector<double> list){
    double mean;
    // Iterates through all the values
    for (int i = 0; i < list.size(); i++){
        // Sums up all the values
        mean += list[i];
    }
    // Divides the total sum of values by the number of elements in list
    mean /= list.size();
    // Returns mean value
    return mean;
}

double calc_std_dev(vector<double> list){
    // Calculates the mean by calling function and equating it to variable called "avg"
    double avg = calc_mean(list);
    double std_dev;
    // Declare new double vector variable
    vector<double> diff_squared;
    // Iterates through all elements
    for (int i = 0; i < list.size(); i++){
        // Finds difference between each element and the avg, then squares it.
        diff_squared.push_back((list[i] - avg) * (list[i] - avg));
    }
    std_dev = sqrt(calc_mean(diff_squared)); // Sums up the differences squared, then adds them up and divides by
                                             // number of elements in list, and then calculates sqrt to find std. dev.
    return std_dev;
}

