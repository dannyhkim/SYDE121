// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 3
// Filename: lab04_01.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Soccer Simulation Game
// Purpose: Simulates a soccer game between Team A and Team B, which contains 1-30 random events in a single game.
// Due Date: Friday, October 12, 2018
// *********************************************************************************************************************
/*
 Testing scenarios:
 In order to test whether my simulator was working correctly, I completed test runs where I outputted the random value
 between 1-30 that is generated. I made sure that certain values were not repeating and that no values outside of 1-30
 were being generated.

 Next, I made sure that there were no repetitions or patterns in the 6 possible events that were being outputted.
 As well, I made sure that the cards on fouls being distributed were randomized, and not a single type of card was
 continuously being given.

 I checked to see if the 4 possible events within the shot at target event were not being repeated and that they were
 randomized each time I ran the simulator.

 I also made sure that the number of events in each half were equal, or that the 2nd half had one more event than
 the first half. The way that my program divides the number of events into each half is that if the total number of
 events is even, each half will have the same number of events. However, if there is an odd number, the 2nd half will
 have one more event than the first half.

 Lastly, I compared the statistics outputted at half-time and full-time with my manually tabulated statistics table
 based on the statement events that were being outputted.
 */

#include <iostream>
#include <unistd.h>
using namespace std;

bool run_soccer_simulation();
// PURPOSE: Runs the specified soccer simulation
//     INPUTS: none
//     RETURNS: returns true if the simulation was successful;
//              else, returns false

void shot_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked);
// PURPOSE: Handles the shot on target event
//     INPUTS: team_name - string that indicates current team name
//             goals - number of goals scored for the current team
//             on_goal - number of shots on goal for the current team
//             off_goal - number of shots off goal for the current team
//             blocked - number of shots blocked for the current team
//     RETURNS: nothing to return

void free_kick(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked);
// PURPOSE: Handles the free kick event
//      INPUTS: team_name - string that indicates current team name
//              goals - number of goals scored for current team
//              on_goal - number of shots on goal for current team
//              off_goal - number of shots off goal for current team
//              blocked - number of shots blocked for the current team
//      RETURNS: no return

void foul_card(string team_name, int& yellow, int& red, int& fouls);
// PURPOSE: Handles the distribution of cards for fouls
//      INPUTS: team_name - string that indicates current team name
//              yellow - number of yellow cards for current team
//              red - number of red cards for the current team
//              fouls - indicates number of fouls for current team
//      RETURNS: no return

void penalty(string team_name, int& goals, int& on_goal, int& off_goal);
// PURPOSE: Handles the penalty kick event
//      INPUTS: team_name - string that indicates current team name
//              goals - number of goals scored for current team
//              on_goal - number of shots on goal for current team
//              off_goal - number of shots off goal for current team
//      RETURNS: no return

void winner(int a_goals, int b_goals);
// PURPOSE: Determines the winner of the game by comparing goal counts for both teams
//      INPUTS: a_goals - number of goals for Team A
//              b_goals - number of goals for Team B
//      RETURNS: no returns


// MAIN FUNCTION
int main() {

    // runs if it returns a value of true
	if (run_soccer_simulation()){
	    // Outputs statement saying soccer simulation was successful.
        cout << "\n\tSoccer simulation completed successfully." << endl;
	}

    // Terminates
	return 0;
}

// Method that runs the soccer simulation
bool run_soccer_simulation() {

	// Initialize corresponding variables
	const string team_a = "Team A", team_b = "Team B";

	// Variables to keep track of stats to output during half-time and full-time
	int a_goals, b_goals, a_on_goal, b_on_goal, a_off_goal, b_off_goal, a_fouls, b_fouls, a_yellow, b_yellow;
	int a_blocked, b_blocked, a_red, b_red;

	// Variables that determine length of match in terms of events
	int no_of_events, cur_event;
	int first_half;

	// Gives random function a new seed so that random numbers generated each time
	srand(time(0));

    // Generates number of events
	no_of_events = rand() % 30 + 1;

	// Divide the events into two halves
    first_half = no_of_events / 2;

	// Prints the welcome message
	cout << "\n\tWELCOME TO THE SOCCER SIMULATION GAME!\n" << endl;

	// Process events
	// Uses for loop to generate 1-30 events, depending on the value of the random number (no_of_events)
	for (int event = 1; event <= no_of_events; event++) {

		// Generates the type of event based on 6 different potential outcomes
		cur_event = rand() % 6 + 1;

        // adds time delay of 1.7 seconds when outputting each event
        usleep(1500000);

		// Processes event depending on the random number generated between 1-6 (inclusive)
		switch(cur_event) {

			// Handle shot on target for Team A
			case 1:
				// call a function to handle shot on target
				shot_on_target(team_a, a_goals, a_on_goal, a_off_goal, b_blocked);
				break;

			// Handle shot on target for Team B
			case 2:
				// call a function to handle shot on target
				shot_on_target(team_b, b_goals, b_on_goal, b_off_goal, a_blocked);
				break;

		    // Handle free kick for Team A
		    case 3:
		        // call a function to handle the free kick
		        free_kick(team_a, a_goals, a_on_goal, a_off_goal, b_blocked);

		        // call a function to handle the card on foul
		        foul_card(team_b, b_yellow, b_red, b_fouls);
                break;

            // Handle free kick for Team B
		    case 4:
		        // call a function to handle the free kick
                free_kick(team_b, b_goals, b_on_goal, b_off_goal, a_blocked);

                // call a function to handle the card on foul
                foul_card(team_a, a_yellow, a_red, a_fouls);
                break;

            // Handle penalty kick for team A
		    case 5:
		        // call a function to handle the penalty
                penalty(team_a, a_goals, a_on_goal, a_off_goal);

                // call a function to determine what type of card is distributed or not
                foul_card(team_b, b_yellow, b_red, b_fouls);
                break;

            // Handle penalty kick for Team B
		    case 6:
		        // call a function to handle the penalty
                penalty(team_b, b_goals, b_on_goal, b_off_goal);

                // call a function to determine if no card, yellow card, or red card is distributed for foul
                foul_card(team_a, a_yellow, a_red, a_fouls);
                break;
		}

		// once the number of events looped through reaches the half-point, output half-time stats
		if (event == first_half){
		    usleep(1500000);
		    //outputs half-time stats
		    cout << "\tHALF TIME" << endl;
		    cout << "\t\t\t\t\tTEAM A\t\t\tTEAM B" << endl;
		    cout << "\tSCORE:\t\t\t\t" << a_goals << "\t\t\t\t" << b_goals << endl;
		    cout << "\tSHOTS ON GOAL:\t\t" << a_on_goal << "\t\t\t\t" << b_on_goal << endl;
		    cout << "\tSHOTS OFF GOAL:\t\t" << a_off_goal << "\t\t\t\t" << b_off_goal << endl;
		    cout << "\tSHOTS BLOCKED:\t\t" << a_blocked << "\t\t\t\t" << b_blocked << endl;
		    cout << "\tFOULS:\t\t\t\t" << a_fouls << "\t\t\t\t" << b_fouls << endl;
		    cout << "\tYELLOW CARDS:\t\t" << a_yellow << "\t\t\t\t" << b_yellow << endl;
		    cout << "\tRED CARDS:\t\t\t" << a_red << "\t\t\t\t" << b_red << "\n" << endl;

		    //delays for 1.5 seconds for user to view stats
		    usleep(1500000);

		    // Calls srand function again at half-time
		    srand(time(0));

		// once all the events have occurred and been outputted, output the full-time game stats
		} else if (event == no_of_events){
		    usleep(1500000);
		    //outputs full-time stats
            cout << "\tFULL TIME" << endl;
            cout << "\t\t\t\t\tTEAM A\t\t\tTEAM B" << endl;
            cout << "\tSCORE:\t\t\t\t" << a_goals << "\t\t\t\t" << b_goals << endl;
            cout << "\tSHOTS ON GOAL:\t\t" << a_on_goal << "\t\t\t\t" << b_on_goal << endl;
            cout << "\tSHOTS OFF GOAL:\t\t" << a_off_goal << "\t\t\t\t" << b_off_goal << endl;
            cout << "\tSHOTS BLOCKED:\t\t" << a_blocked << "\t\t\t\t" << b_blocked << endl;
            cout << "\tFOULS:\t\t\t\t" << a_fouls << "\t\t\t\t" << b_fouls << endl;
            cout << "\tYELLOW CARDS:\t\t" << a_yellow << "\t\t\t\t" << b_yellow << endl;
            cout << "\tRED CARDS:\t\t\t" << a_red << "\t\t\t\t" << b_red << "\n" << endl;
		}
	}

	// call function that outputs statement saying which team won, or if it was a tie.
	winner(a_goals, b_goals);

	// Returns true if the simulation is successful
	return true;
}

// function to determine winner of game by comparing number of goals scored for each team
void winner(int a_goals, int b_goals){
    // if statement outputting different statements depending on winner
    if (a_goals > b_goals){
        // Team A has won the game
        cout << "\tTEAM A HAS WON THE GAME! CONGRATULATIONS!" << endl;
    } else if (b_goals > a_goals){
        // Team B has won the game
        cout << "\tTEAM B HAS WON THE GAME! CONGRATULATIONS!" << endl;
    } else {
        // Both teams have tied
        cout << "\tIT IS A TIE GAME! CONGRATULATIONS TO BOTH TEAMS!" << endl;
    }
}

// function that generates a random outcome from a pool of 4 possibilities
void shot_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked) {

	// Initialize corresponding values
	int shot_outcome;

	// Generates random number from 0-3 for event outcome
	shot_outcome = rand() % 4;

	// Processes the event for shot on target
	switch(shot_outcome) {
	    // Outcome 1: team scores a goal
		case 0:
			cout << "\t" << team_name << " has scored a goal! Fantastic shot!\n\n";
			goals++;
			on_goal++;
			break;
		// Outcome 2: team has shot on goal, but saved
		case 1:
			cout << "\t" << team_name << " has shot on goal. Great save by the opposing team.\n\n";
			on_goal++;
			break;
		// Outcome 3: team has shot off goal
		case 2:
			cout << "\t" << team_name << " has shot off goal. Excellent attempt.\n\n";
			off_goal++;
			break;
		// Outcome 4: Team's shot is blocked
		case 3:
			cout << "\t" << team_name << "'s shot was blocked. Excellent attempt.\n\n";
			blocked++;
			break;
	}
}

// function that handles the free kick event (3-4)
void free_kick(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked){

    // Variable declaration
    int kick_outcome;

    // Assigns variable random number from 0-3
    kick_outcome = rand() % 4;

    // Processes one of the outcomes depending on value of random number generated
    switch(kick_outcome){
        // Outcome 1: Team scores goal on free kick
        case 0:
            // Outputs corresponding statement
            cout << "\t" << team_name << " awarded a free kick. Opposing team has committed a foul. " << team_name <<
            " has scored a goal!";
            //increases goal count by 1 because goal is scored
            goals++;
            on_goal++;
            break;

        // Outcome 2: Team has shot on goal on free kick, saved by opposing team
        case 1:
            cout << "\t" << team_name << " awarded a free kick. Opposing team has committed a foul. " << team_name <<
            " has shot on goal. Great save by opposing team.";
            // shots on goal count increases
            on_goal++;
            break;

        // Outcome 3: Team shoots off goal with free kick
        case 2:
            cout << "\t" << team_name << " awarded a free kick. Opposing team has committed a foul. " << team_name <<
            " has shot off goal. Nice attempt.";
            // shots off goal count increases
            off_goal++;
            break;

        // Outcome 4: Team's shot is blocked by opposing player on their free kick
        case 3:
            cout << "\t" << team_name << " awarded a free kick. Opposing team has committed a foul. " << team_name <<
            "'s shot was blocked!";
            // blocked shots increased by 1
            blocked++;
            break;
    }
}

// function that handles the penalty kick event (5-6)
void penalty(string team_name, int& goals, int& on_goal, int& off_goal){

    // Penalty outcome variable declared (holds a value of 0-3 which corresponds to a specific event)
    int pen_outcome;

    // Assigns random number from 0-3
    pen_outcome = rand() % 3;

    // Processes one of the outcomes depending on value of pen_outcome
    switch(pen_outcome){

        // Outcome 1: Team scores the penalty.
        case 0:
            cout << "\t" << team_name << " awarded a penalty. Opposing team has committed foul close to goal. "
            << team_name << " has scored a goal!";
            //increases goal and on goal count by 1
            goals++;
            on_goal++;
            break;

        // Outcome 2: Team shoots penalty on goal, but saved by goalkeeper.
        case 1:
            cout << "\t" << team_name << " awarded a penalty. Opposing team has committed foul close to goal. "
            << team_name << " has shot on goal, but saved by goalkeeper!";
            // increases on goal count by 1
            on_goal++;
            break;

        // Outcome 3: Team shoots penalty off goal.
        case 2:
            cout << "\t" << team_name << " awarded a penalty. Opposing team has committed foul close to goal. "
            << team_name << " has shot off goal.";
            // increases off goal count by 1
            off_goal++;
            break;
    }
}

// function that handles the dealing of cards on foul
void foul_card(string team_name, int& yellow, int& red, int& fouls){

    // Variable declaration
    int foul_outcome;

    // Assigns random value from 0-2 to foul_outcome
    foul_outcome = rand() % 3;

    // Processes one of the outcomes depending on value of foul_outcome
    switch(foul_outcome){

        // Outcome 1: No card given to team.
        case 0:
            cout << " No card was given to " << team_name << ".\n" << endl;
            // Foul count increases by 1
            fouls++;
            break;

        // Outcome 2: Yellow card given to team.
        case 1:
            cout << " Yellow card was given to " << team_name << ".\n" << endl;
            // Foul count and yellow card count increases by 1
            fouls++;
            yellow++;
            break;

        // Outcome 3: Red card was given to team.
        case 2:
            cout << " Red card was given to " << team_name << ".\n" << endl;
            // Foul count and red card count increases by 1
            fouls++;
            red++;
            break;
    }

}
