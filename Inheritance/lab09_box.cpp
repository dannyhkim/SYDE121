// *********************************************************************************************************************
//
// Student Names: Jennifer (Jing Yi) He and Daniel Kim
// Student Numbers: 20759401 and 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 8
// Filename: lab09_box.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Fresh Fruits and Veggies
// Purpose: To create a program that models an ordering system in which customers can subscribe to different plans
//          and get their fruits and vegetable items in a box based on the season of the month.
// Due Date: November 30, 2018
// *********************************************************************************************************************

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include "lab09_box.hpp"
#include "lab09_produce.hpp"
using namespace std;

// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100 /* in grams */, FruitsAndVeggiesBox::MAX_DAY = 31 /* not checking for Feb 31st */;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2 /* 2019 and 2020 as valid */;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2019;

// default/empty constructor that initializes the order size to 0
FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0) {}

// parametric constructor that allows user to initialize the order size of the box
FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) : order_size(new_order_size) {}

void FruitsAndVeggiesBox::print() { // print function that prints all items in the box

    // loops that iterate to print all the details of the produce objects of different seasons in the box
    for(int i = 0; i < winter_produce.size(); i++)
        winter_produce[i].print();
    for(int i = 0; i < spring_produce.size(); i++)
        spring_produce[i].print();
    for(int i = 0; i < summer_produce.size(); i++)
        summer_produce[i].print();
    for(int i = 0; i < fall_produce.size(); i++)
        fall_produce[i].print();
}

int FruitsAndVeggiesBox::size() { // function that calculates and returns the size of the box
    int cur_size = 0;
    cur_size = cur_size + winter_produce.size() + spring_produce.size() + summer_produce.size() + fall_produce.size();
    return cur_size;
}

void FruitsAndVeggiesBox::empty_the_box() {
    // TODO: complete method definition here
    // empty the box if some items already inserted
    winter_produce.clear();
    spring_produce.clear();
    summer_produce.clear();
    fall_produce.clear();
    
}

void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {
    // TODO: complete method definition here
    // step0. initialize corresponding variables
    ifstream produce_ifstream; string line;
    
    // step1. open the corresponding file
    produce_ifstream.open(file_name);
    
    // step2. load the values from the file
    if(!(produce_ifstream.fail())) {
        while (!produce_ifstream.eof()){
            getline(produce_ifstream, line);
            if (line.size() > 0)
                return_vector.push_back(line);
        }
               produce_ifstream.close();
    }
    // step3. close the file
    produce_ifstream.close();
}

void FruitsAndVeggiesBox::load_up_produce_names() {
    // TODO: complete method definition here
    
    // load up the four files one at a time
    file_to_vector(winter_produce_names, WINTER_FILE);
    file_to_vector(spring_produce_names, SPRING_FILE);
    file_to_vector(summer_produce_names, SUMMER_FILE);
    file_to_vector(fall_produce_names, FALL_FILE);
}

void FruitsAndVeggiesBox::print_loaded_names() {
    // TODO: complete method definition here
    
    // print each vector separately by listing each group of names separately
    cout << "WINTER PRODUCE" << endl;
    for(int i = 0; i < winter_produce_names.size(); i++) {
        cout << winter_produce_names[i] << endl;
    }
    cout << "SPRING PRODUCE" << endl;
    for(int i = 0; i < spring_produce_names.size(); i++) {
        cout << spring_produce_names[i] << endl;
    }
    cout << "SUMMER PRODUCE" << endl;
    for(int i = 0; i < summer_produce_names.size(); i++) {
        cout << summer_produce_names[i] << endl;
    }
    cout << "FALL PRODUCE" << endl;
    for(int i = 0; i < fall_produce_names.size(); i++) {
        cout << fall_produce_names[i] << endl;
    }
}

void FruitsAndVeggiesBox::assign_seasons(int current_month) {
    // remove previously set seasons
    produce_seasons.clear();
    // insert corresponding seasons based on specified rules
    switch (current_month) {
        case JAN:
            produce_seasons.push_back(WINTER);
            break;
        case FEB:
        case MAR:
            produce_seasons.push_back(WINTER);
            produce_seasons.push_back(SPRING);
            break;
        case APR:
            produce_seasons.push_back(SPRING);
            break;
        case MAY:
        case JUN:
            produce_seasons.push_back(SPRING);
            produce_seasons.push_back(SUMMER);
            break;
        case JUL:
            produce_seasons.push_back(SUMMER);
            break;
        case AUG:
        case SEP:
            produce_seasons.push_back(SUMMER);
            produce_seasons.push_back(FALL);
            break;
        case OCT:
            produce_seasons.push_back(FALL);
            break;
        case NOV:
        case DEC:
            produce_seasons.push_back(FALL);
            produce_seasons.push_back(WINTER);
            break;
    }
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
    // generate random values for the current produce item
    rand_item = rand() % vector_size; // random item name
    rand_weight = rand() % MAX_WEIGHT + 1; rand_day = rand() % MAX_DAY + 1;
    rand_month = rand() % MAX_MONTH + 1; rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
    // TODO: complete method definition here

    // step0. initialize corresponding variables
    bool repeated_entry;
    WinterProduce w1;
    // step1. keep repeating this until a unique item is generated
    do {
        repeated_entry = false;
        // step1.1. generate random values for the winter produce item
        generate_random_value(winter_produce_names.size());
        // step1.2. create a new WinterProduce instance with the matching values
        w1 = WinterProduce(winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        if(winter_produce.size() == 0) {
            winter_produce.push_back(w1);
        } else {
            // step1.3. iterate through the winter produce vector to check if the item is unique
            for (int i = 0; i < winter_produce.size() && !repeated_entry; i++) {
                repeated_entry = (w1 == winter_produce[i]);
            }
            if(!repeated_entry) {
                // step2. once a unique item is generated, store it into the vector
                winter_produce.push_back(w1);
            }
        }
    } while(repeated_entry);
}

void FruitsAndVeggiesBox::handle_spring_item() {
    // TODO: complete method definition here
    
    // step0. initialize corresponding variables
    bool repeated_entry;
    // step1. keep repeating this until a unique item is generated
    do {
        repeated_entry = false;
        // step1.1. generate random values for the spring produce item
        generate_random_value(spring_produce_names.size());
        // step1.2. create a new SpringProduce instance with the matching values
        SpringProduce s1(spring_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        if(spring_produce.size() == 0) {
            spring_produce.push_back(s1);
        } else {
            // step1.3. iterate through the spring produce vector to check if the item is unique
            for (int i = 0; i < spring_produce.size() && !repeated_entry; i++) {
                repeated_entry = (s1 == spring_produce[i]);
            }
            if(!repeated_entry) {
                // step2. once a unique item is generated, store it into the vector
                spring_produce.push_back(s1);
            }
        }
    } while(repeated_entry);
}

void FruitsAndVeggiesBox::handle_summer_item() {
    // TODO: complete method definition here
    
    // step0. initialize corresponding variables
    bool repeated_entry;
    // step1. keep repeating this until a unique item is generated

    do {
        repeated_entry = false;
        // step1.1. generate random values for the summer produce item
        generate_random_value(summer_produce_names.size());
        // step1.2. create a new SummerProduce instance with the matching values
        SummerProduce s1(summer_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        if(summer_produce.size() == 0) {
            summer_produce.push_back(s1);
        } else {
            // step1.3. iterate through the summer produce vector to check if the item is unique
            for (int i = 0; i < summer_produce.size() && !repeated_entry; i++) {
                repeated_entry = (s1 == summer_produce[i]);
            }
            if(!repeated_entry) {
                // step2. once a unique item is generated, store it into the vector
                summer_produce.push_back(s1);
            }
        }
    } while(repeated_entry);
}

void FruitsAndVeggiesBox::handle_fall_item() {
    // TODO: complete method definition here
    
    // step0. initialize corresponding variables
    bool repeated_entry;
    // step1. keep repeating this until a unique item is generated
    do {
        repeated_entry = false;

        // step1.1. generate random values for the fall produce item
        generate_random_value(fall_produce_names.size());

        // step1.2. create a new FallProduce instance with the matching values
        FallProduce f1(fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);
        
        if(fall_produce.size() == 0) {
            fall_produce.push_back(f1);
        }
        else {
            // step1.3. iterate through the fall produce vector to check if the item is unique
            for (int i = 0; i < fall_produce.size() && !repeated_entry; i++) {
                repeated_entry = (f1 == fall_produce[i]);
            }
            if(!repeated_entry) {
                // step2. once a unique item is generated, store it into the vector
                fall_produce.push_back(f1);
            }
        }
    } while(repeated_entry);
}

void FruitsAndVeggiesBox::insert_unique_item() {
    // TODO: complete method definition here
    
    // step1. randomly generate a unique produce item
    // step1.1. randomly select a season from available seasons
    rand_season = rand() % produce_seasons.size();
    // step1.2. insert a new unique item with random values into the box
    switch (produce_seasons[rand_season]) {
        case WINTER:
            // step1.3a. insert winter produce item
            handle_winter_item();
            break;
            
        case SPRING:
            // step1.3b. insert spring produce item
            handle_spring_item();
            break;
            
        case SUMMER:
            // step1.3c. insert summer produce item
            handle_summer_item();
            break;
            
        case FALL:
            // step1.3d. insert fall produce item
            handle_fall_item();
            break;
    }
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {
    // TODO: complete method definition here
    
    // step0. set the randomization seed
    srand(time(0));
    
    // step1. remove all items if some already inserted
    empty_the_box();
    
    // step2. load up produce names
    load_up_produce_names();
    
    // step3. decide which seasons are current
    assign_seasons(current_month);
    
    // step4. insert matching unique items based on the current seasons
    for (int i = 0; i < order_size; i++) {
        insert_unique_item();
    }
    
}
