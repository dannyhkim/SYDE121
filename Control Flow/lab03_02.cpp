// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 2
// Filename: lab03_02.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Ball dropped from drone
// Purpose: Shows the distance travelled by ball during each time interval until it reaches the ground.
// Due Date: Friday, September 28, 2018

/*
   In this program, there were no values we used to test the program logic as the users were unable to input anything,
   and the answers were concrete. Instead, we manually computed the first few results of the table and matched them
   with the outputs of the program. As well, we calculated the distance during interval and total distance at random
   time intervals like 18 seconds, or 22 seconds to see if the program was outputting the correct information.

   Output for question (b):
    The time it takes the ball to fall 15000m is around 55.500 seconds.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //Variable declaration
    double GRAVITY = 9.80665;
    double distance = 0, total_distance = 0, last_distance = 0;
    double time = 0;

    //outputs to a precision of 3 decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    //Outputs the headers
    cout << left << "Time (in sec):\tDistance during interval (in m):\tTotal distance (in m):   " << endl;

    //continues to loop as long as total distance is less than 15000, (the height of the drone)
    while (total_distance <= 15000){
        //when time starts at 0, the distance is computed with formula that has does not subtract previous distance
        //as there is no previous distance travelled
        if (time == 0) {
            distance = 0.5 * GRAVITY * pow(time, 2);
        } else{
            //computes the distance travelled in the 1 second by calculating total distance travelled during the entire
            //time and subtracting the distance travelled up to 1 second before
            distance = 0.5 * GRAVITY * pow(time, 2) - last_distance; //last_distance is previous distance travelled up to
            //1 second before
        }
        //computes total distance by summing up the distances travelled during each interval
        total_distance += distance;

        //when the drone has travelled less than 14000 metres in total
        if (total_distance < 14000){

            //outputs the time, distance during interval, and total distance in intervals of 1 second time
            cout << time << "\t\t\t" << distance << "\t\t\t\t\t\t\t\t" << total_distance << endl;
            time++; //increases time by 1 second
            last_distance = 0.5 * GRAVITY * pow (time - 1, 2); //calculates previous total distance travelled

        } else{ //as drone is in its last 1000m of travel, the time intervals change to increments of 0.1 seconds
            time += 0.1;
            last_distance = 0.5 * GRAVITY * pow (time - 0.1, 2);
            //outputs in intervals of 0.1s
            cout << time << "\t\t\t" << distance << "\t\t\t\t\t\t\t\t" << total_distance << endl;
        }
    }
    //final statement saying the approximate time it takes drone to fall 15000m.
    cout << "\nThe time it takes the ball to fall 15000m is around " << time << " seconds." << endl;
    return 0;
}