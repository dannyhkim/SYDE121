// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 5
// Filename: lab06_01.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Fun with Scalable Vector Graphics
// Purpose: Program reads a maximum of 5 pairs (name, value) from a .txt file and then displays a bar chart depicting
//          each integer value as a rectangle of corresponding size onto an area of 400 pixels in an .svg file.
//          The program also has a function that draws a SYDE logo in the syde_logo_username.svg file.
// Due Date: November 7, 2018
// *********************************************************************************************************************

/* Testing Scenarios:
 * I tested with 5 pairs:
   Daniel, 500
   Andy, 300
   Justin, 200
   Ahmad, 550
   Jeffrey, 860

   I tested with 4 pairs:
   Andy, 300
   Justin, 200
   Ahmad, 550
   Jeffrey, 860

   I tested with 3 pairs:
   Justin, 200
   Ahmad, 550
   Jeffrey, 860

   I tested with 2 pairs:
   Andy, 300
   Justin, 200

   I tested with a single pair:
   Daniel, 500

   For each pair, I made sure to check the graph and see if the bars were scaled to the 400 pixel area.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool create_graph();
// PURPOSE: Runs the program to draw graph based on integer values in pairs and draw SYDE logo
// INPUTS: none
// RETURNS: true if the program is run successfully, else, false

void draw_axes(ofstream& my_ofstream);
// PURPOSE: Draws the axes of the bar chart and labels axes with x and y
// INPUTS: my_ofstream - instance of ofstream to output axes to graph.svg file
// RETURNS: nothing

void draw_rect(vector<int> rect_size, ofstream& my_ofstream);
// PURPOSE: Draws the rectangle bars on the graph corresponding to the integer value
// INPUTS: rect_size - vector containing list of integer values obtained from pairs
//         my_ofstream - instance of ofstream to output rectangle bars to graph.svg file
// RETURNS: nothing

void draw_logo(ofstream& my_ofstream_1);
// PURPOSE: Draws the SYDE logo with rectangles using svg language
// INPUTS: my_ofstream_1 - instance of ofstream to output logo to syde_logo_dh55kim.svg
// RETURNS: nothing

int main() {
    // Calls bool function to run program
    create_graph();
    return 0; // terminates program
}

bool create_graph(){
    // Variable Declaration
    ifstream my_ifstream; // instance of ifstream for collecting input from .txt file
    ofstream my_ofstream, my_ofstream_1; // instances of ofstream for drawing graph and syde logo in separate files
    string cur_pair; // temporarily stores a line of text from input.txt file
    vector<int> rect_size; // holds integer values obtained from pairs (max 5)

    my_ifstream.open("input.txt"); // opens the input file
    my_ofstream.open("graph.svg"); // opens the output file for graph
    my_ofstream_1.open("syde_logo_dh55kim.svg"); // opens svg logo file

    for(int i = 0; i < 5 && !my_ifstream.eof(); i++){ // for loop iterates to get lines of input
        getline(my_ifstream, cur_pair); // gets line of text from .txt file, temporarily stores it in cur_pair
        // obtains only integer value from line of string text, converts it to int, then inserts it in vector
        rect_size.push_back(atoi(cur_pair.substr(cur_pair.find(',', 0) + 2).c_str()));
    }

    draw_axes(my_ofstream); // function called to draw axes
    draw_rect(rect_size, my_ofstream); // draws rectangle bars on chart
    draw_logo(my_ofstream_1); // draws SYDE logo

    // closes all instances of ifstream & oftsream once program tasks are finished
    my_ifstream.close();
    my_ofstream.close();
    my_ofstream_1.close();

    return true;
}

void draw_axes(ofstream& my_ofstream){

    if(!my_ofstream.fail()) { // check for failure
        my_ofstream << "<?xml version=\"1.0\"?>\n"; // output svg content to a file
        my_ofstream << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
        my_ofstream << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        my_ofstream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";
        // draws vertical axes of 400 units
        my_ofstream << "<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"450\" style=\"stroke:rgb(255,51,51);stroke-width:2\"/>\n";
        // draws horizontal axes of 400 units
        my_ofstream << "<line x1=\"50\" y1=\"450\" x2=\"450\" y2=\"450\" style=\"stroke:rgb(255,51,51);stroke-width:2\"/>\n";
        // labels x and y axes
        my_ofstream << "<text x=\"458\" y=\"455\">" << "x" << "</text>\n";
        my_ofstream << "<text x=\"48\" y=\"43\">" << "y" << "</text>\n";
    }
}

void draw_rect(vector<int> rect_size, ofstream& my_ofstream){
    double max_size = rect_size.at(0); //variable storing max integer value found from pairs

    for (int i = 0; i < rect_size.size(); i++){
        // Iterates through loop to make max equal to element with greatest value
        // If the current element is greater than the current max, replace max with the current element
        if (rect_size.at(i) > max_size){
            max_size = rect_size.at(i);
        }
    }
    // iterates through vector to draw each bar based on corresponding integer value
    for (int i = 0; i < rect_size.size(); i++){
        if(!my_ofstream.fail()) { // checks for failure
            // draws rectangles evenly spaced apart by changing starting x-position of where to draw bars
            my_ofstream << "<rect x=\"" + to_string(50 + 400 / 11 + 800 / 11 * i) +
            // calculation to determine where to start drawing bar on y-position so it aligns with x-axis
            "\" y=\"" + to_string(450 - rect_size.at(i) / max_size * 400) + "\" width=\"" + to_string(400 / 11) +
            // height of each bar is scaled by dividing each int value with max value and multiplying by 400
            "\" height=\"" + to_string(rect_size.at(i) / max_size * 400) + "\" style=\"fill:rgb(0," + to_string(45 * i)
            + ",255);\"/>\n"; // colours of bars are changed each loop iteration
        }
    }
    my_ofstream << "<line x1=\"50\" y1=\"450\" x2=\"450\" y2=\"450\" style=\"stroke:rgb(255,51,51);stroke-width:2\"/>\n";
    my_ofstream << "</svg>\n"; // Drawing output to graph.svg is complete

}

void draw_logo(ofstream& my_ofstream_1){

    my_ofstream_1 << "<?xml version=\"1.0\"?>\n"; // output svg content to a file
    my_ofstream_1 << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
    my_ofstream_1 << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    my_ofstream_1 << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";

    // Draw S
    my_ofstream_1 << "<rect x=\"100\" y=\"50\" width=\"100\" height=\"30\" style=\"fill:rgb(200,61,50);\"/>\n";
    my_ofstream_1 << "<rect x=\"100\" y=\"90\" width=\"30\" height=\"30\" style=\"fill:rgb(200,61,50);\"/>\n";
    my_ofstream_1 << "<rect x=\"100\" y=\"130\" width=\"100\" height=\"30\" style=\"fill:rgb(200,61,50);\"/>\n";
    my_ofstream_1 << "<rect x=\"170\" y=\"170\" width=\"30\" height=\"30\" style=\"fill:rgb(200,61,50);\"/>\n";
    my_ofstream_1 << "<rect x=\"100\" y=\"210\" width=\"100\" height=\"30\" style=\"fill:rgb(200,61,50);\"/>\n";

    // Draw Y
    my_ofstream_1 << "<rect x=\"240\" y=\"50\" width=\"30\" height=\"80\" style=\"fill:rgb(98,161,169);\"/>\n";
    my_ofstream_1 << "<rect x=\"275\" y=\"130\" width=\"30\" height=\"110\" style=\"fill:rgb(98,161,169);\"/>\n";
    my_ofstream_1 << "<rect x=\"310\" y=\"50\" width=\"30\" height=\"80\" style=\"fill:rgb(98,161,169);\"/>\n";

    // Draw D
    my_ofstream_1 << "<rect x=\"100\" y=\"280\" width=\"30\" height=\"190\" style=\"fill:rgb(153,175,93);\"/>\n";
    my_ofstream_1 << "<rect x=\"140\" y=\"280\" width=\"40\" height=\"30\" style=\"fill:rgb(153,175,93);\"/>\n";
    my_ofstream_1 << "<rect x=\"170\" y=\"320\" width=\"30\" height=\"110\" style=\"fill:rgb(153,175,93);\"/>\n";
    my_ofstream_1 << "<rect x=\"140\" y=\"440\" width=\"40\" height=\"30\" style=\"fill:rgb(153,175,93);\"/>\n";

    // Draw E
    my_ofstream_1 << "<rect x=\"240\" y=\"280\" width=\"30\" height=\"190\" style=\"fill:rgb(230,183,64);\"/>\n";
    my_ofstream_1 << "<rect x=\"280\" y=\"280\" width=\"60\" height=\"30\" style=\"fill:rgb(230,183,64);\"/>\n";
    my_ofstream_1 << "<rect x=\"280\" y=\"360\" width=\"60\" height=\"30\" style=\"fill:rgb(230,183,64);\"/>\n";
    my_ofstream_1 << "<rect x=\"280\" y=\"440\" width=\"60\" height=\"30\" style=\"fill:rgb(230,183,64);\"/>\n";

    // Drawing output to svg is complete
    my_ofstream_1 << "</svg>\n";
}
